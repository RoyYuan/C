//
//  main.cpp
//  POJ-1062-昂贵的聘礼
//
//  Created by 袁子涵 on 15/12/6.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  16ms    912KB

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
#define MAXN 10005
using namespace std;

long long int m,n;

struct qnode {
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
long long int dist[MAXN],level[105],lvmax;
void Dijkstra()
{
    for (int i=1; i<=n; i++) {
        dist[i]=INF;
    }
    priority_queue<qnode>que;
    while (!que.empty()) {
        que.pop();
    }
    dist[0]=0;
    que.push(qnode(0,0));
    qnode tmp;
    while (!que.empty()) {
        tmp=que.top();
        que.pop();
        int u=tmp.v;
        if (vis[u]) {
            continue;
        }
        vis[u]=1;
        for (int i=0; i<E[u].size(); i++) {
            int v=E[tmp.v][i].v;
            long long int cost=E[u][i].cost;
            if (!vis[v] && dist[v]>dist[u]+cost && level[v]<=lvmax) {
                dist[v]=dist[u]+cost;
                que.push(qnode(v,dist[v]));
            }
        }
    }
}
void addedge(int u,int v,long long int w)
{
    E[u].push_back(Edge(v,w));
}
int main(int argc, const char * argv[]) {
    long long int c,out=INF;
    int a,total;
    memset(level, 0, sizeof(level));
    cin >> m >> n;
    for (int i=1; i<=n; i++) {
        scanf("%lld %lld %d",&c,&level[i],&total);
        addedge(0, i, c);
        for (int j=1; j<=total; j++) {
            scanf("%d %lld",&a,&c);
            addedge(a, i, c);
        }
    }
    for (int i=1; i<=n; i++) {
        memset(vis, 0, sizeof(vis));
        lvmax=level[i]+m;
        for (int j=1; j<=n; j++) {
            if (level[j]<level[i] || level[j]>lvmax) {
                vis[j]=1;
            }
        }
        Dijkstra();
        out=min(out,dist[1]);
    }
    cout << out << endl;
    return 0;
}
