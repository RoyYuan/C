//
//  main.cpp
//  160806-5
//
//  Created by ??? on 16/8/6.
//  Copyright © 2016? ???. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 1000;
const int MAXM = 4000;
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
            } }
        if(flag) {
            u = v;
            continue; }
        int Min = N;
        for( int i = head[u]; i != -1;i = edge[i].next)
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
int main(int argc, const char * argv[])
{
    int sum=0,flag,remain[25],map[25][25],n,won[25],S,T;
    while(~scanf("%d",&n)){
        init();
        for(int i=1;i<=n;i++)
            scanf("%d",&won[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&remain[i]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&map[i][j]);
        sum=won[1]+remain[1];
        flag=0;
        for(int i=2;i<=n;i++){
            if(sum<won[i]){
                flag=1;
                break;
            }
        }
        if(flag){
            puts("NO");
            continue;
        }
        S=0,T=n*n+n+1;
        for(int i=2;i<=n;i++)
            addedge(S,i,sum-won[i]);
        sum=0;
        for(int i=2;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(map[i][j]>0){
                    sum+=map[i][j];
                    addedge(i,i*n+j,map[i][j]);
                    addedge(j,i*n+j,map[i][j]);
                    addedge(i*n+j,T,map[i][j]);
                }
            }
        }
        if(sap(S,T,T+1)==sum){
            puts("YES");
        }
        else
            puts("NO");
    }
    return 0;
}