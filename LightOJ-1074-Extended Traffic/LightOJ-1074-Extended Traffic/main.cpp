//
//  main.cpp
//  LightOJ-1074-Extended Traffic
//
//  Created by 袁子涵 on 15/12/6.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  52ms    2096KB

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define MAXN 205
using namespace std;
int T,n,m;
long long int busy[MAXN];
struct qnode
{
    int v;
    long long int c;
    qnode(int _v=0,long long int _c=0):v(_v),c(_c){}
    bool operator <(const qnode &r)const
    {
        return c>r.c;
    }
};
struct Edge
{
    int v;
    long long int cost;
    Edge(int _v=0,long long int _cost=0):v(_v),cost(_cost){}
};
vector<Edge>E[MAXN];
bool vis[MAXN];
long long int dist[MAXN];

int cnt[MAXN];
bool re[MAXN];
void dfs(int u)
{
    re[u]=1;
    for(int i = 0;i < E[u].size();i++)
        if(!re[E[u][i].v])
            dfs(E[u][i].v);
}
void SPFA()
{
    memset(vis, 0, sizeof(vis));
    memset(re, 0, sizeof(re));
    for (int i=1; i<=n; i++) {
        dist[i]=INF;
    }
    vis[1]=1;
    dist[1]=0;
    queue<int>que;
    while (!que.empty()) {
        que.pop();
    }
    que.push(1);
    memset(cnt, 0, sizeof(cnt));
    cnt[1]=1;
    while (!que.empty()) {
        int u=que.front();
        que.pop();
        vis[u]=0;
        for (int i=0; i<E[u].size(); i++) {
            int v=E[u][i].v;
            if (re[v]) {
                continue;
            }
            if (dist[v]>dist[u]+E[u][i].cost) {
                dist[v]=dist[u]+E[u][i].cost;
                if (!vis[v]) {
                    vis[v]=1;
                    que.push(v);
                    if (++cnt[v]>n) {
                        dfs(v);
                    }
                }
            }
        }
    }
}
void addedge(int u,int v,long long int w)
{
    E[u].push_back(Edge(v,w));
}
int main(int argc, const char * argv[]) {
    int num1,num2;
    cin >> T;
    int t=0;
    while (t!=T) {
        t++;
        scanf("%d",&n);
        for (int i=0; i<=n; i++) {
            E[i].clear();
        }
        for (int i=1; i<=n; i++) {
            scanf("%lld",&busy[i]);
        }
        scanf("%d",&m);
        for (int i=1; i<=m; i++) {
            scanf("%d %d",&num1,&num2);
            long long int tmp=(busy[num2]-busy[num1])*(busy[num2]-busy[num1])*(busy[num2]-busy[num1]);
            addedge(num1,num2,tmp);
        }
        SPFA();
        scanf("%d",&num1);
        printf("Case %d:\n",t);
        for (int i=1; i<=num1; i++) {
            scanf("%d",&num2);
            if (dist[num2]==INF || dist[num2]<3 || re[num2]) {
                printf("?\n");
            }
            else
                printf("%lld\n",dist[num2]);
        }
    }
    return 0;
}
