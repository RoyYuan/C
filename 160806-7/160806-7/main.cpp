//
//  main.cpp
//  160806-7
//
//  Created by 袁子涵 on 16/8/7.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
#define in(a) (a)
#define out(a) (a+n)
#define MAXM 400000
#define MAXN 70000
const int INF = 0x3f3f3f3f;
struct Edge
{
    int to,next,cap,flow;
}edge[MAXM];
int tol;
int head[MAXN];
int gap[MAXN],dep[MAXN],pre[MAXN],cur[MAXN];
inline void init()
{
    tol = 0;
    memset(head,-1,sizeof(head));
}
inline void addedge( int u, int v, int w, int rw=0) {
    edge[tol].to = v;edge[tol].cap = w;edge[tol].next = head[u];
    edge[tol].flow = 0;head[u] = tol++;
    edge[tol].to = u;edge[tol].cap = rw;edge[tol].next = head[v];
    edge[tol].flow = 0;head[v]=tol++;
}
int sap( int start, int end, int N) {
    memset(gap,0,sizeof(gap));
    memset(dep,0,sizeof(dep));
    memcpy(cur,head,sizeof(cur));
    int u = start;
    pre[u] = -1;
    gap[0] = N;
    int ans = 0;
    while(dep[start] < N)
    {
        if(u == end) {
            int Min = INF;
            for( int i = pre[u];i != -1; i = pre[edge[i^1].to])
                if(Min > edge[i].cap - edge[i].flow)
                    Min = edge[i].cap - edge[i].flow;
            for( int i = pre[u];i != -1; i = pre[edge[i^1].to]) {
                edge[i].flow += Min;
                edge[i^1].flow -= Min;
            }
            u = start;
            ans += Min;
            continue;
        }
        bool flag = false;
        int v=0;
        for( int i = cur[u]; i != -1;i = edge[i].next) {
            v = edge[i].to;
            if(edge[i].cap - edge[i].flow && dep[v]+1 == dep[u]) {
                flag = true;
                cur[u] = pre[v] = i; break;
            }
        }
        if(flag) {
            u = v;
            continue;
        }
        int Min = N;
        for( int i = head[u]; i != -1;i = edge[i].next)
            if(edge[i].cap - edge[i].flow && dep[edge[i].to] < Min) {
                Min = dep[edge[i].to];
                cur[u] = i;
            }
        gap[dep[u]]--;
        if(!gap[dep[u]])return ans;
        dep[u] = Min+1;
        gap[dep[u]]++;
        if(u != start) u = edge[pre[u]^1].to;
    }
    return ans;
}
int t,n,m,S,T,u,v;
int main(int argc, const char * argv[]) {
    scanf("%d",&t);
    while (t--) {
        init();
        scanf("%d%d",&n,&m);
        S=0,T=2*n+2;
        addedge(S, out(2), 2);
        addedge(in(1), T, 1);
        addedge(in(3), T, 1);
        for (int i=4; i<=n; i++)
            addedge(in(i), out(i), 1);
        for (int i=1; i<=m; i++) {
            scanf("%d%d",&u,&v);
            if (u<1 || u>n || v<1 || v>n)
                continue;
            addedge(out(u), in(v), 1);
            addedge(out(v), in(u), 1);
        }
        if (sap(S, T, 2*n+2)==2)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
