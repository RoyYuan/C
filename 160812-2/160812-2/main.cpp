//
//  main.cpp
//  160812-2
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
#define fix(x) (x-32)
using namespace std;
const int maxsize=100;
const int maxn=1e5+1e4;
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
    int Get_Ans(char *str,int id)
    {
        int len=(int)strlen(str);
        int now=root,tmp,total=0;
        set<int>out;
        out.clear();
        for (int i=0;i<len;i++)
        {
            now=next[now][fix(str[i])];
            tmp=now;
            while (tmp!=root)
            {
                if (end[tmp])
                {
                    total++;
                    out.insert(end[tmp]);
                }
                tmp=fail[tmp];
            }
        }
        if(total)
        {
            printf("web %d:",id);
            set<int>::iterator it=out.begin();
            for (;it!=out.end();it++)
                printf(" %d",*it);
            puts("");
        }
        return total>0?1:0;
    }
}Trie;
Trie Tree;

int main(int argc, const char * argv[]) {
    int n,m,out=0;
    char str[10005],c;
    scanf("%d",&n);
    while ((c=getchar())!='\n');
    Tree.Init();
    for (int i=1; i<=n; i++) {
        gets(str);
        Tree.AddNewStr(str, i);
    }
    scanf("%d",&m);
    while ((c=getchar())!='\n');
    Tree.build();
    for (int i=1; i<=m; i++) {
        gets(str);
        out+=Tree.Get_Ans(str, i);
    }
    printf("total: %d\n",out);
    return 0;
}
