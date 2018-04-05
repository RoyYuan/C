//
//  main.cpp
//  POJ-2387-Til the Cows Come Home
//
//  Created by 袁子涵 on 15/11/25.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//普通 94ms   4620KB
//优先队列47ms 756KB

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXN 1010
#define typec long long int
#define INF 0x3f3f3f3f

using namespace std;
int T,N;
//bool vis[MAXN];
//int cost[MAXN][MAXN],lowcost[MAXN];
//void Dijkstra(int beg)
//{
//    for (int i=0; i<N; i++) {
//        lowcost[i]=INF;
//        vis[i]=0;
//    }
//    lowcost[beg]=0;
//    for (int j=0; j<N; j++) {
//        int k=-1;
//        long long int Min=INF;
//        for (int i=0; i<N; i++) {
//            if (!vis[i] && lowcost[i]<Min) {
//                Min=lowcost[i];
//                k=i;
//            }
//        }
//        if (k==-1) {
//            break;
//        }
//        vis[k]=1;
//        for (int i=0; i<N; i++) {
//            if (!vis[i] && lowcost[k]+cost[k][i]<lowcost[i]) {
//                lowcost[i]=lowcost[k]+cost[k][i];
//            }
//        }
//    }
//}
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
int dist[MAXN];
void Dijkstra(int start)
{
    memset(vis, 0, sizeof(vis));
    for (int i=1; i<=N; i++)
        dist[i]=INF;
    priority_queue<qnode>que;
    while (!que.empty())
        que.pop();
    dist[start]=0;
    que.push(qnode(start,0));
    qnode tmp;
    while (!que.empty()) {
        tmp=que.top();
        que.pop();
        int u=tmp.v;
        if (vis[u])
            continue;
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
    int a,b,c;
    scanf("%d%d",&T,&N);
    for (int i=0; i<=N+1; i++)
        E[i].clear();
    for (int i=1; i<=T; i++) {
        scanf("%d%d%d",&a,&b,&c);
        addedge(a,b,c);
        addedge(b, a, c);
    }
    Dijkstra(N);
    printf("%d\n",dist[1]);
    return 0;
}
