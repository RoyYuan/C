//
//  main.cpp
//  POJ-1511-Invitation Cards
//
//  Created by 袁子涵 on 15/12/2.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <map>
#define MAXN 1000110
#define INF 0x7fffffff
using namespace::std;
int N;
long long int P,Q;
long long int dist[2][MAXN];
bool vis[MAXN];
int cnt[2][MAXN];
struct Edge
{
    long long int v,cost;
    Edge(long long int _v=0,long long int _cost=0):v(_v),cost(_cost){}
};
vector<Edge>E[2][MAXN];
struct qnode
{
    long long int v,c;
    qnode(long long int _v=0,long long int _c=0):v(_v),c(_c){}
    bool operator <(const qnode &r)const
    {
        return c>r.c;
    }
};
void Dijkstra(int num)
{
    memset(vis, 0, sizeof(vis));
    for (long long int i=1; i<=P; i++) {
        dist[num][i]=INF;
    }
    priority_queue<qnode>que;
    while(!que.empty()) que.pop();
    dist[num][1]=0;
    que.push(qnode(1,0));
    qnode tmp;
    while (!que.empty()) {
        tmp=que.top();
        que.pop();
        long long int u=tmp.v;
        if (vis[u]) {
            continue;
        }
        vis[u]=1;
        for (long long int i=0; i<E[num][u].size(); i++) {
            long long int v=E[num][tmp.v][i].v;
            long long int cost=E[num][u][i].cost;
            if (!vis[v] && dist[num][v]>dist[num][u]+cost) {
                dist[num][v]=dist[num][u]+cost;
                que.push(qnode(v,dist[num][v]));
            }
        }
    }
}
void addedge(int num,long long int u, long long int v ,long long int w)
{
    E[num][u].push_back(Edge(v,w));
}
int main(int argc, const char * argv[]) {
    cin >> N;
    while (N--) {
        long long int a,b,c,sum=0;
        cin >> P >> Q;
        for (long long int i=1; i<=MAXN; i++) {
            E[0][i].clear();
            E[1][i].clear();
        }
        for (long long int i=1; i<=Q; i++) {
            scanf("%lld %lld %lld",&a,&b,&c);
            addedge(0,a, b, c);
            addedge(1,b, a, c);
        }
        Dijkstra(0);
        Dijkstra(1);
        for (int i=2; i<=P; i++) {
            sum+=dist[0][i]+dist[1][i];
        }
        cout << sum << endl;
    }
    return 0;
}
