//
//  main.cpp
//  BestCoder-Round 72.2-3
//
//  Created by 袁子涵 on 16/2/13.
//  Copyright © 2016年 袁子涵. All rights reserved.
//
//  327ms   8864KB

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <cstdlib>
#define MAXN 300005
using namespace std;

int t;
long long int n,m,now,tmp;
typedef struct {
    long long int x,y,w;
}Edge;
Edge E[MAXN];
long long int father[MAXN];

long long int find(long long int x)
{
    long long int s=x,root,tem;
    while (father[s]!=s)
        s=father[s];
    root=s;
    s=x;
    while (father[s]!=s) {
        tem=father[s];
        father[s]=root;
        s=tem;
    }
    return root;
}

int main(int argc, char *argv[])
{
    scanf("%d",&t);
    while (t--) {
        scanf("%lld%lld",&n,&m);
        for (long long int i=1; i<=m; i++)
            scanf("%lld%lld%lld",&E[i].x,&E[i].y,&E[i].w);
        now=0;
        for (int i=31; i>=0; --i) {
            tmp=now | (1<<i);
            for (long long int j=1; j<=n; j++)
                father[j]=j;
            for (long long int j=1; j<=m; j++) {
                if ((tmp & E[j].w)==tmp)
                    if (find(E[j].x)!=find(E[j].y))
                        father[father[E[j].x]]=father[E[j].y];
            }
            long long int sum=0;
            for (long long int j=1; j<=n; j++)
                if (father[j]==j)
                    sum++;
            if (sum==1)
                now=tmp;
        }
        printf("%lld\n",now);
    }
    return 0;
}