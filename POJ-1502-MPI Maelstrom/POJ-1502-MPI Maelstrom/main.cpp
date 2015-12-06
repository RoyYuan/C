//
//  main.cpp
//  POJ-1502-MPI Maelstrom
//
//  Created by 袁子涵 on 15/11/28.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  16ms    804KB

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <queue>
#define MAXN 105
#define INF 0x3f3f3f3f
using namespace std;

int n;
struct qnode {
    int v,c;
    qnode(int _v=0,int _c=0):v(_v),c(_c){}
    bool operator <(const qnode &r) const
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
    char x[20];
    cin >> n;
    for (int i=1; i<=n; i++) {
        E[i].clear();
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<i; j++) {
            scanf("%s",x);
            if (x[0]=='x') {
                continue;
            }
            else
            {
                int temp=atoi(x);
                addedge(i,j,temp);
                addedge(j,i,temp);
            }
        }
    }
    Dijkstra(1);
    int out=0;
    for (int i=2; i<=n; i++) {
        out=max(out,dist[i]);
    }
    cout << out << endl;
    return 0;
}
