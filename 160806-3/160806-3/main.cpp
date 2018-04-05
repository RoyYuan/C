//
//  main.cpp
//  160806-3
//
//  Created by 袁子涵 on 16/8/6.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

const int MAXN = 6000;
const int MAXM = 100010;
const int INF = 0x7fffffff;
struct Edge
{
    long long int to,next,cap,flow;
}edge[MAXM];
long long int tol;
long long int head[MAXN];
long long int gap[MAXN],dep[MAXN],pre[MAXN],cur[MAXN];
inline void init()
{
    tol = 0;
    memset(head,-1,sizeof(head));
}
inline void addedge(long long int u,long long int v,long long int w,long long int rw=0) {
    edge[tol].to = v;edge[tol].cap = w;edge[tol].next = head[u];
    edge[tol].flow = 0;head[u] = tol++;
    edge[tol].to = u;edge[tol].cap = rw;edge[tol].next = head[v];
    edge[tol].flow = 0;head[v]=tol++;
}
long long int sap(long long int start,long long int end,long long int N) {
    memset(gap,0,sizeof(gap));
    memset(dep,0,sizeof(dep));
    memcpy(cur,head,sizeof(cur));
    long long int u = start;
    pre[u] = -1;
    gap[0] = N;
    long long int ans = 0;
    while(dep[start] < N)
    {
        if(u == end) {
            long long int Min = INF;
            for(long long int i = pre[u];i != -1; i = pre[edge[i^1].to])
                if(Min > edge[i].cap - edge[i].flow)
                    Min = edge[i].cap - edge[i].flow;
            for(long long int i = pre[u];i != -1; i = pre[edge[i^1].to]) {
                edge[i].flow += Min;
                edge[i^1].flow -= Min;
            }
            u = start;
            ans += Min;
            continue;
        }
        bool flag = false;
        long long int v;
        for(long long int i = cur[u]; i != -1;i = edge[i].next) {
            v = edge[i].to;
            if(edge[i].cap - edge[i].flow && dep[v]+1 == dep[u]) {
                flag = true;
                cur[u] = pre[v] = i; break;
            } }
        if(flag) {
            u = v;
            continue; }
        long long int Min = N;
        for(long long int i = head[u]; i != -1;i = edge[i].next)
            if(edge[i].cap - edge[i].flow && dep[edge[i].to] < Min) {
                Min = dep[edge[i].to];
                cur[u] = i; }
        gap[dep[u]]--;
        if(!gap[dep[u]])return ans;
        dep[u] = Min+1;
        gap[dep[u]]++;
        if(u != start) u = edge[pre[u]^1].to;
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    long long int n,m;
    scanf("%lld%lld",&n,&m);
    init();
    for (long long int i=1; i<=m; i++) {
        long long int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        addedge(a, b, c, c);
    }
    long long int maxflow=sap(1, n, n);
    printf("%lld\n",maxflow);
    return 0;
}
