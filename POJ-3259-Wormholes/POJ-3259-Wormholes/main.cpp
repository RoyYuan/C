//
//  main.cpp
//  POJ-3259-Wormholes
//
//  Created by 袁子涵 on 15/11/28.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  125ms   812KB

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#define MAXN 505
#define INF 0x3f3f3f3f
using namespace std;
int f,n,m,w;

struct Edge
{
    int v,cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge>E[MAXN];
void addedge(int u,int v,int w)
{
    E[u].push_back(Edge(v,w));
}
bool vis[MAXN];
int cnt[MAXN];
int dist[MAXN];
bool SPFA(int start)
{
    memset(vis, 0, sizeof(vis));
    for (int i=1; i<=n; i++) {
        dist[i]=INF;
    }
    dist[start]=0;
    vis[start]=1;
    queue<int>que;
    while (!que.empty()) {
        que.pop();
    }
    que.push(start);
    memset(cnt, 0, sizeof(cnt));
    cnt[start]=1;
    while (!que.empty()) {
        int u=que.front();
        que.pop();
        vis[u]=false;
        for (int i=0; i<E[u].size(); i++) {
            int v=E[u][i].v;
            if (dist[v]>dist[u]+E[u][i].cost) {
                dist[v]=dist[u]+E[u][i].cost;
                if (!vis[v]) {
                    vis[v]=1;
                    que.push(v);
                    if (++cnt[v]>n) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}
int main(int argc, const char * argv[]) {
    cin >> f;
    int a,b,c;
    while (f--) {
        cin >> n >> m >> w;
        for (int i=1; i<=n; i++) {
            E[i].clear();
        }
        for (int i=1; i<=m; i++) {
            scanf("%d%d%d",&a,&b,&c);
            addedge(a, b, c);
            addedge(b, a, c);
        }
        for (int i=1; i<=w; i++) {
            scanf("%d%d%d",&a,&b,&c);
            addedge(a, b, -c);
        }
        if(SPFA(1))
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
