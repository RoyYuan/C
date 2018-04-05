//
//  main.cpp
//  160812-4
//
//  Created by 袁子涵 on 16/8/12.
//  Copyright © 2016年 袁子涵. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <utility>
using namespace std;
const int maxn=105;
const int size=55;
typedef struct Trie
{
    int next[maxn][size],fail[maxn],root,total;
    bool end[maxn];
    int hash[256], M;
    void Set_Hash(int n, unsigned char s[]) {
        M = n;
        for (int i=0; i<n; i++)
            hash[s[i]] = i;
    }
    int NewNode()
    {
        for (int i=0;i<size;i++)
            next[total][i]=-1;
        end[total++]=0;
        return total-1;
    }
    void AddNewStr(unsigned char *str)
    {
        int c;
        int now=root;
        for (int i=0;str[i];i++)
        {
            c=hash[str[i]];
            if (next[now][c]==-1)
                next[now][c]=NewNode();
            now=next[now][c];
        }
        end[now]=1;
    }
    void init()
    {
        total=0;
        memset(end, 0, sizeof(end));
        root=NewNode();
    }
    void build()
    {
        queue<int>Q;
        while(!Q.empty())Q.pop();
        fail[root]=root;
        int now=root;
        for (int i=0;i<size;i++)
        {
            if (next[now][i]==-1)
                next[now][i]=root;
            else
            {
                fail[next[now][i]]=root;
                Q.push(next[now][i]);
            }
        }
        while(!Q.empty())
        {
            now=Q.front();
            Q.pop();
            for (int i=0;i<size;i++)
            {
                end[now]=end[now]||end[fail[now]];
                if(next[now][i]==-1)
                    next[now][i]=next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
            }
        }
    }
}Trie;
Trie Tree;
struct BigInt
{
    const static int mod = 10000;
    const static int DLEN = 4;
    int a[200],len;
    BigInt()
    {
        memset(a,0,sizeof(a));
        len = 1;
    }
    BigInt(int v)
    {
        memset(a,0,sizeof(a));
        len = 0;
        do
        {
            a[len++] = v%mod;
            v /= mod;
        }
        while(v);
    }
    BigInt(const char s[])
    {
        memset(a,0,sizeof(a));
        int L = strlen(s);
        len = L/DLEN;
        if(L%DLEN)len++;
        int index = 0;
        for(int i = L-1; i >= 0; i -= DLEN)
        {
            int t = 0;
            int k = i - DLEN + 1;
            if(k < 0)k = 0;
            for(int j = k; j <= i; j++)
                t = t*10 + s[j] - '0';
            a[index++] = t;
        }
    }
    BigInt operator +(const BigInt &b)const
    {
        BigInt res;
        res.len = max(len,b.len);
        for(int i = 0; i <= res.len; i++)
            res.a[i] = 0;
        for(int i = 0; i < res.len; i++)
        {
            res.a[i] += ((i < len)?a[i]:0)+((i < b.len)?b.a[i]:0);
            res.a[i+1] += res.a[i]/mod;
            res.a[i] %= mod;
        }
        if(res.a[res.len] > 0)res.len++;
        return res;
    }
    BigInt operator *(const BigInt &b)const
    {
        BigInt res;
        for(int i = 0; i < len; i++)
        {
            int up = 0;
            for(int j = 0; j < b.len; j++)
            {
                int temp = a[i]*b.a[j] + res.a[i+j] + up;
                res.a[i+j] = temp%mod;
                up = temp/mod;
            }
            if(up != 0)
                res.a[i + b.len] = up;
        }
        res.len = len + b.len;
        while(res.a[res.len - 1] == 0 &&res.len > 1)res.len--;
        return res;
    }
    void output()
    {
        printf("%d",a[len-1]);
        for(int i = len-2; i >=0 ; i--)
            printf("%04d",a[i]);
        printf("\n");
    }
};
BigInt dp[55][maxn],out;
int main(int argc, const char * argv[]) {
    int n,m,p;
    unsigned char str[55];
    while(~scanf("%d%d%d",&n,&m,&p))
    {
        out=0;
        Tree.init();
        scanf("%s",str);
        Tree.Set_Hash(n,str);
        for (int i=0; i<p; i++) {
            scanf("%s",str);
            Tree.AddNewStr(str);
        }
        Tree.build();
        memset(dp, 0, sizeof(dp));
        dp[0][0]=1;
        for (int i=1; i<=m; i++) {
            for (int j=0; j<Tree.total; j++) {
                for (int k=0; k<n; k++) {
                    if (Tree.end[Tree.next[j][k]])
                        continue;
                    dp[i][Tree.next[j][k]]=dp[i][Tree.next[j][k]]+dp[i-1][j];
                }
            }
        }
        for (int i=0; i<Tree.total; i++)
            if (!Tree.end[i])
                out=out+dp[m][i];
        out.output();
    }
    return 0;
}
