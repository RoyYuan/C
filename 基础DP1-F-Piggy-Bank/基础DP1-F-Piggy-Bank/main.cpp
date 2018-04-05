//
//  main.cpp
//  基础DP1-F-Piggy-Bank
//
//  Created by 袁子涵 on 15/10/23.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <stdlib.h>

#define INF 0x7fffffff
#define MAX 10005

using namespace std;

typedef struct {
    long long int p,w;
}Coin;

long long int dp[MAX];
Coin c[505];
int E,F,N;
bool visit[MAX];

long long int Dp(long long int wt)
{
    if (visit[wt]) {
        return dp[wt];
    }
    for (int i=1; i<=N; i++) {
        if (wt<c[i].w) {
            continue;
        }
        dp[wt]=min(dp[wt],Dp(wt-c[i].w)+c[i].p);
    }
    visit[wt]=1;
    return dp[wt];
}

int main(int argc, const char * argv[]) {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d%d",&E,&F,&N);
        memset(visit, 0, sizeof(visit));
        for (int i=0; i<=F-E; i++) {
            dp[i]=INF;
        }
        dp[0]=0;
        for (int i=1; i<=N; i++) {
            scanf("%lld%lld",&c[i].p,&c[i].w);
            dp[c[i].w]=min(dp[c[i].w],c[i].p);
        }
        for (int i=1; i<=F-E; i++) {
            Dp(i);
        }
        if (dp[F-E]==INF) {
            printf("This is impossible.\n");
        }
        else
            printf("The minimum amount of money in the piggy-bank is %lld.\n",dp[F-E]);
    }
    return 0;
}
