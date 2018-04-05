//
//  main.cpp
//  160806-6
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

const int MAXN = 100;
const int MAXM = 1000;
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
int score[15],n;
bool checkans(int k)
{
    int S=0,T=n+n*(n-1)/2+1,now=0;
    if (k==0)
        return 1;
    init();
    for (int i=1; i<=n; i++)
        addedge(i, T, score[i]);
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            now++;
            addedge(S, n+now, 1);
            if (i>n-k && score[i]<score[j])
                addedge(n+now, i, 1);
            else if (j>n-k && score[i]>score[j])
                addedge(n+now, j, 1);
            else
            {
                addedge(n+now, i, 1);
                addedge(n+now, j, 1);
            }
        }
    }
    return sap(S, T, T+1)==n*(n-1)/2;
}
inline void read()
{
    char s[1000];
    gets(s);
    n=0;
    for(int i=0;s[i];i++)
    {
        int temp=0;
        if( isdigit(s[i]) )
        {
            while(s[i] && isdigit(s[i]) )
            {
                temp=temp*10+s[i]-'0';
                ++i;
            }
            --i;
            score[++n]=temp;
        }
    }
}
int main(int argc, const char * argv[]) {
    int t;
    scanf("%d%*c",&t);
    while (t--) {
        n=0;
        read();
        for (int i=n; i>=0; i--) {
            if (checkans(i)) {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
