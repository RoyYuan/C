//
//  main.cpp
//  POJ-1797-Heavy Transportation
//
//  Created by 袁子涵 on 15/11/26.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  469ms   8616KB

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#define MAXN 1005
#define INF 9999999999
using namespace std;
int n;
long long int m;
long long int cost[MAXN][MAXN];
bool vis[MAXN];
long long int lowc[MAXN];
long long int Prim()
{
    long long int ans=INF;
    memset(vis, 0, sizeof(vis));
    vis[1]=1;
    for (int i=2; i<=n; i++) {
        lowc[i]=cost[1][i];
    }
    for (int i=2; i<=n; i++) {
        long long int maxc=0;
        int p=-1;
        for (int j=2; j<=n; j++) {
            if (!vis[j] && maxc<=lowc[j]) {
                maxc=lowc[j];
                p=j;
            }
        }
        ans=min(ans,maxc);
        if (p==n) {
            return ans;
        }
        vis[p]=1;
        for (int j=2; j<=n; j++) {
            if (!vis[j] && lowc[j]<cost[p][j]) {
                lowc[j]=cost[p][j];
            }
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    int t,num=0,a,b;
    long long int c;
    cin >> t;
    while (t--) {
        num++;
        scanf("%d %lld",&n,&m);
        memset(cost, 0, sizeof(cost));
        for (long long int i=1; i<=m; i++) {
            scanf("%d %d %lld",&a,&b,&c);
            cost[a][b]=c;
            cost[b][a]=c;
        }
        long long int out=Prim();
        printf("Scenario #%d:\n%lld\n\n",num,out);
    }
    return 0;
}
