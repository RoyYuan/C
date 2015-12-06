//
//  main.cpp
//  kruskal
//
//  Created by 袁子涵 on 15/11/30.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

const int MAXN=110;
const int MAXM=10000;
int F[MAXN];
struct Edge
{
    int u,v,w;
} edge[MAXM];
int tol;

void addedge(int u,int v,int w)
{
    edge[tol].u=u;
    edge[tol].v=v;
    edge[tol++].w=w;
}

bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
int find(int x)
{
    if(F[x]==-1)return x;
    else return F[x]=find(F[x]);
}
int Kruskal(int n)
{
    memset(F,-1,sizeof(F));
    sort(edge,edge+tol,cmp);
    int cnt=0;
    int ans=0;
    for(int i=0; i<tol; i++)
    {
        int u=edge[i].u;
        int v=edge[i].v;
        int w=edge[i].w;
        int t1=find(u);
        int t2=find(v);
        if(t1!=t2)
        {
            ans+=w;
            F[t1]=t2;
            cnt++;
        }
        if(cnt==n-1)break;
    }
    if(cnt<n-1)return -1;
    else return ans;
}

int main()
{
    long long int m;
    int a,b,c,n;
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        cin >> a >> b >>c;
        addedge(a,b,c);
        addedge(b,a,c);
    }
    cout << Kruskal(n) << endl;
    return 0;
}
