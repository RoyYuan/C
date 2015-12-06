//
//  main.cpp
//  POJ-2240-Arbitrage
//
//  Created by 袁子涵 on 15/12/2.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  110ms   272KB

#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define MAXN 35

using namespace std;

int n,m;
map<string,double>num;
struct Edge
{
    int v;
    double cost;
    Edge(int _v=0,double _cost=0):v(_v),cost(_cost){}
};
vector<Edge>E[MAXN];
void addedge(int u,int v,double w)
{
    E[u].push_back(Edge(v,w));
}
bool vis[MAXN];
int cnt[MAXN];
double dist[MAXN];
bool SPFA()
{
    memset(vis, 0, sizeof(vis));
    memset(dist, 0, sizeof(dist));
    memset(cnt, 0, sizeof(cnt));
    vis[1]=1;
    queue<int>que;
    while (!que.empty())    que.pop();
    que.push(1);
    cnt[1]=1;
    dist[1]=1;
    while (!que.empty()) {
        int u=que.front();
        que.pop();
        vis[u]=0;
        for (int i=0; i<E[u].size(); i++) {
            int v=E[u][i].v;
            if (dist[v]<dist[u]*E[u][i].cost) {
                dist[v]=dist[u]*E[u][i].cost;
                if (!vis[v]) {
                    vis[v]=1;
                    que.push(v);
                    if (++cnt[v]>n) return 0;
                }
            }
        }
    }
    return 1;
}
int main(int argc, const char * argv[]) {
    int t=0;
    while (cin >> n && n!=0) {
        num.clear();
        for (int i=0; i<MAXN; i++)
            E[i].clear();
        t++;
        string tmp,a,b;
        double c;
        for (int i=1; i<=n; i++) {
            cin >> tmp;
            num[tmp]=i;
        }
        cin >> m;
        for (int i=1; i<=m; i++) {
            cin >> a >> c >> b;
            addedge(num[a], num[b], c);
        }
        if(SPFA())
            cout << "Case " << t << ": No" << endl;
        else
            cout << "Case " << t << ": Yes" << endl;
        getchar();
    }
    return 0;
}
