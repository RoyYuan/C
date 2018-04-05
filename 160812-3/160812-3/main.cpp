//
//  main.cpp
//  160812-3
//
//  Created by 袁子涵 on 16/8/12.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <set>
#define fix(x) (x-'A')
using namespace std;
const int maxsize=30;
const int maxn=1e5;
int out[1005];
typedef struct Trie
{
    int next[maxn][maxsize],fail[maxn],end[maxn];
    int root,total;
    int NewNode()
    {
        for (int i=0; i<maxsize; i++)
            next[total][i]=-1;
        end[total++]=0;
        return total-1;
    }
    void Init()
    {
        total=0;
        root=NewNode();
    }
    void AddNewStr(char *str,int id)
    {
        int len=(int)strlen(str);
        int now=root;
        for (int i=0;i<len;i++)
        {
            if (next[now][fix(str[i])]==-1)
                next[now][fix(str[i])]=NewNode();
            now=next[now][fix(str[i])];
        }
        end[now]=id;
    }
    
    void build()
    {
        int now;
        queue<int>Q;
        while (!Q.empty())Q.pop();
        fail[root]=root;
        for (int i=0;i<maxsize;i++)
        {
            if (next[root][i]==-1)
                next[root][i]=root;
            else
            {
                fail[next[root][i]]=root;
                Q.push(next[root][i]);
            }
        }
        while (!Q.empty())
        {
            now=Q.front();
            Q.pop();
            for (int i=0;i<maxsize;i++)
            {
                if (next[now][i]==-1)
                    next[now][i]=next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
            }
        }
    }
    void Get_Ans(char *str)
    {
        int len=(int)strlen(str);
        int now=root,tmp;
        for (int i=0;i<len;i++)
        {
            if (str[i]<'A' || str[i]>'Z')
            {
                now=root;
                continue;
            }
            now=next[now][fix(str[i])];
            tmp=now;
            while (tmp!=root)
            {
                if (end[tmp])
                    out[end[tmp]]++;
                tmp=fail[tmp];
            }
        }
        return;
    }
}Trie;
Trie Tree;

int main(int argc, const char * argv[]) {
    int n;
    char str[1005][51];
    char str1[2000005],c;
    while(scanf("%d",&n)!=EOF)
    {
        memset(out, 0, sizeof(out));
        while ((c=getchar())!='\n');
        Tree.Init();
        for (int i=1; i<=n; i++) {
            gets(str[i]);
            Tree.AddNewStr(str[i], i);
        }
        Tree.build();
        gets(str1);
        Tree.Get_Ans(str1);
        for (int i=1; i<=n; i++)
            if (out[i])
                printf("%s: %d\n",str[i],out[i]);
    }
    return 0;
}
