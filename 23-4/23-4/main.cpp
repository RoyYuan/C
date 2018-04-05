//
//  main.cpp
//  23-4
//
//  Created by 袁子涵 on 16/4/23.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>

using namespace std;
int t;
long long int n,m;
const int INF=0x3f3f3f3f;
const int MAXN=100005;
const int fix=1e5;
struct qnode
{
    long long int v,c;
    qnode(long long int _v=0,long long int _c=0):v(_v),c(_c){}
    bool operator <(const qnode &r)const
    {
        return c>r.c;
    }
};
struct Edge
{
    long long int v,cost;
    Edge(long long int _v=0,long long int _cost=0):v(_v),cost(_cost){}
};
vector<Edge>E[MAXN];
bool vis[MAXN];
long long int pre[MAXN];
long long int dist[MAXN];
long long int wei[MAXN];
void Dijkstra()
{
    memset(vis, 0, sizeof(vis));
    for (long long int i=0; i<n; i++) {
        dist[i]=INF;
        wei[i]=INF;
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
        long long int u=tmp.v;
        if (vis[u]) {
            continue;
        }
        vis[u]=1;
        for (long long int i=0; i<E[u].size(); i++) {
            long long int v=E[u][i].v;
            long long int cost=E[u][i].cost;
            if (!vis[v] && dist[v]>=dist[u]+cost) {
                dist[v]=dist[u]+cost;
                wei[v]=(cost%fix);
                que.push(qnode(v,dist[v]));
            }
        }
    }
}
void addedge(long long int u,long long int v,long long int cost)
{
    E[u].push_back(Edge(v,cost));
    E[v].push_back(Edge(u,cost));
}
int main(int argc, const char * argv[]) {
    cin >> t;
    while (t--) {
        long long int a,b,c,d;
        cin >> n >> m;
        for (int i=0; i<n; i++)
            E[i].clear();
        for (long long int i=0; i<m; i++) {
            scanf("%lld%lld%lld%lld",&a,&b,&d,&c);
            if (a==b)
                continue;
            addedge(a,b,d*fix+c);
        }
        Dijkstra();
        long long int out=0,out1=0;
        for (long long int i=1; i<n; i++){
            out1+=dist[i]/fix;
            out+=wei[i];
        }
        cout << out1 << " " << out << endl;
    }
    return 0;
}
