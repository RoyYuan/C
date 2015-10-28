//
//  main.cpp
//  基础DP1-P-FatMouse and Cheese
//
//  Created by 袁子涵 on 15/10/28.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  140ms   2308KB

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#define MAX 200
#define maxof(a,b)  ((a)>(b)?(a):(b))
using namespace std;

int n,k;
long long int dp[MAX][MAX],cheese[MAX][MAX];
bool visit[MAX][MAX];

long long int DP(int x,int y,long long int c)
{
    if (cheese[x][y]<=c || x<1 || x>n || y<1 || y>n) {
        return 0;
    }
    if (visit[x][y]) {
        return dp[x][y];
    }
    dp[x][y]=cheese[x][y];
    for (int i=1; i<=k; i++) {
        dp[x][y]=maxof(DP(x-i,y,cheese[x][y])+cheese[x][y],dp[x][y]);
        dp[x][y]=maxof(DP(x+i,y,cheese[x][y])+cheese[x][y],dp[x][y]);
        dp[x][y]=maxof(DP(x,y+i,cheese[x][y])+cheese[x][y],dp[x][y]);
        dp[x][y]=maxof(DP(x,y-i,cheese[x][y])+cheese[x][y],dp[x][y]);
    }
    visit[x][y]=1;
    return dp[x][y];
    
}

int main(int argc, const char * argv[]) {
    while (scanf("%d%d",&n,&k)!=EOF && n!=-1 && k!=-1) {
        long long int out =0;
        memset(visit, 0, sizeof(visit));
        memset(dp, 0, sizeof(dp));
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                scanf("%lld",&cheese[i][j]);
            }
        }
        out=DP(1, 1, 0);
        printf("%lld\n",out);
    }
    return 0;
}
