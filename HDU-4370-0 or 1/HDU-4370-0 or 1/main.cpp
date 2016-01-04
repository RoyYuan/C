//
//  main.cpp
//  HDU-4370-0 or 1
//
//  Created by 袁子涵 on 15/12/7.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  795ms   2304KB

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define MAXN 305
#define LL long long int
using namespace std;
int n;
LL dis[MAXN][MAXN],lowcost[MAXN];
bool vis[MAXN];
void Dijkstra(int start,LL *cir)
{
    for (int i=1; i<=n; i++) {
        lowcost[i]=INF;
        vis[i]=0;
    }
    lowcost[start]=0;
    vis[start]=1;
    for (int j=1; j<=n; j++) {
        int k=start;
        LL Min=INF;
        for (int i=1; i<=n; i++) {
            if (!vis[i] && lowcost[i]<Min) {
                Min=lowcost[i];
                k=i;
            }
        }
        vis[k]=1;
        for (int i=1; i<=n; i++) {
            if (!vis[i] && lowcost[i]>lowcost[k]+dis[k][i]) {
                lowcost[i]=lowcost[k]+dis[k][i];
            }
            if (i==start && start!=k) {
                *cir=min(*cir,lowcost[k]+dis[k][i]);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    while (scanf("%d",&n)!=EOF) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                scanf("%lld",&dis[i][j]);
            }
        }
        LL cir1=INF,cir2=INF,dis;
        Dijkstra(1,&cir1);
        dis=lowcost[n];
        Dijkstra(n, &cir2);
        lowcost[n]=min(dis,cir1+cir2);
        cout << lowcost[n] << endl;
    }
    return 0;
}
