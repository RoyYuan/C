//
//  main.cpp
//  POJ-2253-Frogger
//
//  Created by 袁子涵 on 15/11/26.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  0ms 1048KB

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#define maxof(A,B)  (A>B?A:B)
#define MAXN 210
using namespace std;

int n;
typedef struct node
{
    int x,y;
}Node;
const double INF=0x3f3f3f3f;
Node map[MAXN];
bool vis[MAXN];
double lowc[MAXN],cost[MAXN][MAXN];

double dis(Node a,Node b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double Prim()
{
    double ans=0;
    memset(vis, 0, sizeof(vis));
    for (int i=2; i<=n; i++) {
        lowc[i]=cost[1][i];
    }
    vis[1]=1;
    for (int i=2; i<=n; i++) {
        double minc=INF;
        int p=-1;
        for (int j=2; j<=n; j++) {
            if (!vis[j] && minc>lowc[j]) {
                minc=lowc[j];
                p=j;
            }
        }
        ans=maxof(ans,minc);
        if (p==2) {
            return ans;
        }
        vis[p]=1;
        for (int j=2; j<=n; j++) {
            if (!vis[j]&&lowc[j]>cost[p][j]) {
                lowc[j]=cost[p][j];
            }
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    int t=0;
    while (cin >> n && n!=0) {
        t++;
        double out=0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (i==j) {
                    cost[i][j]=0;
                }
                else
                    cost[i][j]=INF;
            }
        }
        for (int i=1; i<=n; i++) {
            scanf("%d%d",&map[i].x,&map[i].y);
        }
        for (int i=1; i<n; i++) {
            for (int j=i+1; j<=n; j++) {
                cost[i][j]=dis(map[i], map[j]);
                cost[j][i]=cost[i][j];
            }
        }
        out=Prim();
        printf("Scenario #%d\n",t);
        printf("Frog Distance = %.3f\n\n",out);
        getchar();
    }
    return 0;
}
