//
//  main.cpp
//  POJ-1847-Tram
//
//  Created by 袁子涵 on 15/12/6.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  32ms    880KB

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define MAXN 10005

using namespace std;

int n,a,b;
struct qnode
{
    int v,c;
    qnode(int _v=0,int _c=0):v(_v),c(_c){}
    bool operator <(const qnode &r)const
    {
        return c>r.c;
    }
};
struct Edge
{
    int v,cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge>E[MAXN];
bool vis[MAXN];
int dist[MAXN],out[105];
void Dijkstra(int start)
{
    memset(vis, 0, sizeof(vis));
    for (int i=1; i<=n; i++) {
        dist[i]=INF;
    }
    priority_queue<qnode>que;
    while (!que.empty()) {
        que.pop();
    }
    dist[start]=0;
    que.push(qnode(start,0));
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
            int cost=E[u][i].cost;
            if (!vis[v]&&dist[v]>dist[u]+cost) {
                dist[v]=dist[u]+cost;
                que.push(qnode(v,dist[v]));
            }
        }
    }
}
void addedge(int u,int v,int w)
{
    E[u].push_back(Edge(v,w));
}
int main(int argc, const char * argv[]) {
    cin >> n >> a >> b;
    int t;
    for (int i=1; i<=n; i++) {
        scanf("%d",&out[i]);
        for (int j=1; j<=out[i]; j++) {
            scanf("%d",&t);
            if (j==1) {
                addedge(i, t, 0);
            }
            else
                addedge(i, t, 1);
        }
    }
    Dijkstra(a);
    if (dist[b]!=INF) {
        cout << dist[b] << endl;
    }
    else
        cout << "-1" << endl;
    return 0;
}
