//
//  main.cpp
//  160814-3
//
//  Created by 袁子涵 on 16/8/14.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
const int MAXN=100+5;
typedef struct edge
{
    int to,cost,num;
}Edge;
int total1,total2,n,add[MAXN];
int dp[MAXN][2][2];
bool Vis[MAXN][2];
vector<Edge>E1[MAXN],E2[MAXN];
void addedge(int u,int v,int cost)
{
    E1[u].push_back(Edge{v,cost,++total1});
    Vis[total1][0]=0;
    E2[v].push_back(Edge{u,cost,++total2});
    Vis[total2][1]=0;
}
int dfs1(int root,int flag)
{
    int tmp;
    if (Vis[root][0])
        return dp[root][0][flag];
    Vis[root][0]=1;
    dp[root][0][0]=dp[root][0][1]=0;
    for (int i=0; i<E1[root].size(); i++) {
        int next=E1[root][i].to;
        int cost=E1[root][i].cost;
        tmp=-cost+dfs1(next, 0);
        dp[root][0][1]+=max(0,-2*cost+dfs1(next, 1));
        for (int j=0; j<E1[root].size(); j++) {
            if (i==j) {
                continue;
            }
            tmp+=max(0,-E1[root][j].cost+dfs1(E1[root][j].to, 1));
        }
        dp[root][0][0]=max(tmp,dp[root][0][0]);
    }
    dp[root][0][0]+=add[root];
    dp[root][0][1]+=add[root];
    return dp[root][0][flag];
}
int dfs2(int root,int flag)
{
    int tmp;
    if (Vis[root][1])
        return dp[root][1][flag];
    Vis[root][1]=1;
    dp[root][1][0]=dp[root][1][1]=0;
    for (int i=0; i<E2[root].size(); i++) {
        int next=E1[root][i].to;
        int cost=E1[root][i].cost;
        tmp=-cost+dfs1(next, 0);
        dp[root][
    }
    for (int i=0; i<E1[root].size(); i++) {
        int from=E1[root][i].to;
        int cost=E1[root][i].cost;
        tmp=
    }
}
int main(int argc, const char * argv[]) {
    int t,u,v,c;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        memset(dp, 0, sizeof(dp));
        total1=total2=0;
        for (int i=1; i<=n; i++)
        {
            E1[i].clear();
            E2[i].clear();
        }
        for (int i=1; i<=n; i++)
            scanf("%d",&add[i]);
        for (int i=1; i<n; i++) {
            scanf("%d%d%d",&u,&v,&c);
            addedge(u, v, c);
        }
        dfs1(1,0);
        dfs2(1,0);
    }
    return 0;
}