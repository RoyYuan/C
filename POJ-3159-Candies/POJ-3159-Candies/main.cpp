//
//  main.cpp
//  POJ-3159-Candies
//
//  Created by 袁子涵 on 15/12/2.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  563ms   3172KB

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define MAXN 30005
#define MAXE 150005
using namespace std;
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
    int v,cost,next;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
Edge E[150005];
bool vis[MAXN];
int dist[MAXN],n,m,pre[MAXN];
void Dijkstra()
{
    memset(vis, 0, sizeof(vis));
    for (int i=1; i<=n; i++)    dist[i]=INF;
    priority_queue<qnode>que;
    while (!que.empty())    que.pop();
    dist[1]=0;
    que.push(qnode(1,0));
    qnode tmp;
    while (!que.empty()) {
        tmp=que.top();
        que.pop();
        int u=tmp.v;
        if(vis[u])continue;
        vis[u]=1;
        for (int i=pre[u]; i!=-1; i=E[i].next) {
            int v=E[i].v;
            int cost=E[i].cost;
            if (!vis[v] && dist[v]>dist[u]+cost) {
                dist[v]=dist[u]+cost;
                que.push(qnode(v,dist[v]));
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    int a,b,c,now=1;
    cin >> n >> m;
    memset(pre, -1, sizeof(pre));
    for (int i=1; i<=m; i++) {
        scanf("%d%d%d",&a,&b,&c);
        E[now].v=b;
        E[now].cost=c;
        E[now++].next=pre[a];
        pre[a]=i;
    }
    Dijkstra();
    cout << dist[n] << endl;
    return 0;
}
