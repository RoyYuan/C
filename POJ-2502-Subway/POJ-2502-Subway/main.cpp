//
//  main.cpp
//  POJ-2502-Subway
//
//  Created by 袁子涵 on 15/12/2.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  32ms    588KB

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#define INF 0x3f3f3f3f
#define MAXN 210
#define v1 (40000.0/60)
#define v2 (10000.0/60)
using namespace std;
struct stop
{
    long long int x,y;
};
struct stop s[MAXN];
double dist[MAXN][MAXN];
double dis(struct stop a,struct stop b)
{
    return sqrt((double)(a.x-b.x)*(a.x-b.x)+(double)(a.y-b.y)*(a.y-b.y));
}
bool vis[MAXN];
double d[MAXN];
int total=3;
void dijkstra()
{
    for (int i=1; i<=total; i++) {
        d[i]=INF;vis[i]=0;
    }
    d[1]=0;
    for (int j=1; j<=total; j++) {
        int k=-1;
        int Min=INF;
        for (int i=1; i<=total; i++) {
            if (!vis[i] && d[i]<Min) {
                Min=d[i];
                k=i;
            }
        }
        if (k==-1) {
            break;
        }
        vis[k]=1;
        for (int i=1; i<=total; i++) {
            if (!vis[i] && d[k]+dist[k][i]<d[i]) {
                d[i]=d[k]+dist[k][i];
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    int now=0;
    memset(s, 0, sizeof(s));
    for (int i=0; i<MAXN; i++) {
        for (int j=i; j<MAXN; j++) {
            if (i==j) {
                dist[i][j]=0;
            }
            else
                dist[i][j]=dist[j][i]=INF;
        }
    }
    cin >> s[1].x >> s[1].y >> s[2].x >> s[2].y;
    while (scanf("%lld %lld",&s[total].x,&s[total].y)!=EOF) {
        now=total++;
        while (scanf("%lld%lld",&s[total].x,&s[total].y) && s[total].x!=-1 && s[total].y!=-1) {
            total++;
        }
        for (int i=now; i<total; i++) {
            if (i>now) {
                dist[i][i-1]=dist[i-1][i]=min(dist[i][i-1],dis(s[i],s[i-1])/v1);
            }
            if (i<total-1) {
                dist[i][i+1]=dist[i+1][i]=min(dist[i][i+1],dis(s[i],s[i+1])/v1);
            }
            for (int j=i-2; j>=now; j--) {
                dist[i][j]=dist[j][i]=min(dist[i][j],dist[i][j+1]+dist[j+1][j]);
            }
            for (int j=i+2; j<total; j++) {
                dist[i][j]=dist[j][i]=min(dist[i][j],dist[i][j-1]+dist[j-1][j]);
            }
        }
    }
    for (int i=1; i<total; i++) {
        for (int j=i+1; j<total; j++) {
            dist[i][j]=dist[j][i]=min(dist[i][j],dis(s[i],s[j])/v2);
        }
    }
    total--;
    dijkstra();
    printf("%.0f",d[2]);
    return 0;
}
