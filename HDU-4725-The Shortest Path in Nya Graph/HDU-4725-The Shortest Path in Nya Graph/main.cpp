//
//  main.cpp
//  HDU-4725-The Shortest Path in Nya Graph
//
//  Created by 袁子涵 on 15/12/7.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  811ms   26736KB

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define MAXN 200005
#define LL long long int
using namespace std;

int T;
LL n,m,c;
LL layer[MAXN];
bool have[MAXN];
struct qnode
{
    LL v,c;
    qnode(LL _v=0,LL _c=0):v(_v),c(_c){}
    bool operator <(const qnode &r)const
    {
        return c>r.c;
    }
};
struct Edge
{
    LL v,cost;
    Edge(LL _v=0,LL _cost=0):v(_v),cost(_cost){}
};
vector<Edge>E[MAXN];
bool vis[MAXN];
LL dist[MAXN];
void Dijkstra(LL start)
{
    memset(vis, 0, sizeof(vis));
    for (LL i=1; i<=2*n; i++) {
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
        LL u=tmp.v;
        if (vis[u]) {
            continue;
        }
        vis[u]=1;
        for (LL i=0; i<E[u].size(); i++) {
            LL v=E[tmp.v][i].v;
            LL cost=E[u][i].cost;
            if (!vis[v]&&dist[v]>dist[u]+cost) {
                dist[v]=dist[u]+cost;
                que.push(qnode(v,dist[v]));
            }
        }
    }
}
void addedge(LL u,LL v,LL w)
{
    E[u].push_back(Edge(v,w));
}
int main(int argc, const char * argv[]) {
    cin >> T;
    int t=0;
    LL a,b,w;
    while (t<T) {
        t++;
        cin >> n >> m >> c;
        memset(have, 0, sizeof(have));
        for (LL i=1; i<=2*n; i++) {
            E[i].clear();
        }
        for (LL i=1; i<=n; i++)
        {
            scanf("%lld",&layer[i]);
            have[layer[i]+n]=1;
            addedge(layer[i]+n, i, 0);
            if (layer[i]>1) {
                addedge(i, n+layer[i]-1, c);
            }
            if (layer[i]<n) {
                addedge(i, n+layer[i]+1, c);
            }
        }
        for (LL i=1+n; i<2*n; i++) {
            if (have[i] && have[i+1]) {
                addedge(i, i+1, c);
                addedge(i+1, i, c);
            }
        }
        for (LL i=1; i<=m; i++) {
            scanf("%lld%lld%lld",&a,&b,&w);
            addedge(a, b, w);
            addedge(b, a, w);
        }
        Dijkstra(1);
        printf("Case #%d: ",t);
        if (dist[n]==INF) {
            dist[n]=-1;
        }
        cout << dist[n] << endl;
    }
    return 0;
}
