//
//  main.cpp
//  160917-5
//
//  Created by 袁子涵 on 16/9/17.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <utility>
#include <map>

using namespace std;
const int maxn=2050;
const int MAXN = 2050;
const int MAXM = 100010;
const int INF = 0x3f3f3f3f;
struct Edge
{
    int to,next,cap,flow;
} edge[MAXM];
int tol;
int head[MAXN];
int gap[MAXN],dep[MAXN],cur[MAXN];
int t,n,m,lth[maxn][maxn];
set<int>ledge[maxn];
void init()
{
    tol = 0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int w,int rw = 0)
{
    edge[tol].to = v;
    edge[tol].cap = w;
    edge[tol].flow = 0;
    edge[tol].next = head[u];
    head[u] = tol++;
    edge[tol].to = u;
    edge[tol].cap = rw;
    edge[tol].flow = 0;
    edge[tol].next = head[v];
    head[v] = tol++;
}
int Q[MAXN];
void BFS(int start,int end)
{
    memset(dep,-1,sizeof(dep));
    memset(gap,0,sizeof(gap));
    gap[0] = 1;
    int front = 0, rear = 0;
    dep[end] = 0;
    Q[rear++] = end;
    while(front != rear)
    {
        int u = Q[front++];
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            if(dep[v] != -1)continue;
            Q[rear++] = v;
            dep[v] = dep[u] + 1;
            gap[dep[v]]++;
        }
    }
}
int S[MAXN];
int lon=-1;
int sap(int start,int end,int N)
{
    BFS(start,end);
    memcpy(cur,head,sizeof(head));
    int top = 0;
    int u = start;
    int ans = 0;
    while(dep[start] < N)
    {
        if(u == end)
        {
            int Min = INF;
            int inser;
            int now=0;
            for(int i = 0; i < top; i++)
                if(Min > edge[S[i]].cap - edge[S[i]].flow)
                {
                    Min = edge[S[i]].cap - edge[S[i]].flow;
                    now++;
                    inser = i;
                }
            if(lon==-1)lon=now;
            if(lon<now)return ans;
            for(int i = 0; i < top; i++)
            {
                edge[S[i]].flow += Min;
                edge[S[i]^1].flow -= Min;
            }
            ans += Min;
            top = inser;
            u = edge[S[top]^1].to;
            continue;
        }
        bool flag = false;
        int v;
        for(int i = cur[u]; i != -1; i = edge[i].next)
        {
            v = edge[i].to;
            if(edge[i].cap - edge[i].flow && dep[v]+1 == dep[u])
            {
                flag = true;
                cur[u] = i;
                break;
            }
        }
        if(flag)
        {
            S[top++] = cur[u];
            u = v;
            continue;
        }
        int Min = N;
        for(int i = head[u]; i != -1; i = edge[i].next)
            if(edge[i].cap - edge[i].flow && dep[edge[i].to] < Min)
            {
                Min = dep[edge[i].to];
                cur[u] = i;
            }
        gap[dep[u]]--;
        if(!gap[dep[u]])return ans;
        dep[u] = Min + 1;
        gap[dep[u]]++;
        if(u != start)u = edge[S[--top]^1].to;
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    scanf("%d",&t);
    while (t--) {
        int u,v,w;
        scanf("%d%d",&n,&m);
        if (n<=1) {
            printf("0\n");
            continue;
        }
        init();
        lon=-1;
        for (int i=1; i<=m; i++) {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u, v, w,w);
        }
        printf("%d\n",sap(1, n, n));
    }
    return 0;
}
//4
//4 4
//1 2 1
//2 4 2
//3 1 3
//4 3 4
//4 5
//1 2 1
//2 4 2
//3 1 3
//4 3 4
//1 4 2
//5 6
//1 4 2
//1 3 3
//1 2 1
//4 5 1
//2 5 1
//3 5 1
//9 14
//1 2 1
//1 3 2
//1 4 1
//1 5 2
//1 6 3
//1 7 5
//1 8 7
//2 9 2
//3 9 1
//4 9 2
//5 9 1
//6 9 2
//7 9 6
//8 9 8