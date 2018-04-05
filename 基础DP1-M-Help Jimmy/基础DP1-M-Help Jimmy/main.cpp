//
//  main.cpp
//  基础DP1-M-Help Jimmy
//
//  Created by 袁子涵 on 15/10/24.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  0ms 752KB

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

#define INF 0x7fffffff
#define minof(a,b) ((a)>(b)?(b):(a))

using namespace std;

typedef struct {
    int x1,x2,h;
}Platform;

int N,X,Y,MAX;
Platform p[1005];
bool visit[1005][2];
long long int dp[1005][2];

int comp(Platform a,Platform b)
{
    return a.h<b.h;
}

long long int DP(int num,int dir)
{
    int k;
    if (visit[num][dir]) {
        return dp[num][dir];
    }
    if (num==0) {
        return 0;
    }
    if (dir==0) {
        k=num-1;
        while (k>0 && p[num].h-p[k].h<=MAX) {
            if (p[num].x1>=p[k].x1 && p[num].x1<=p[k].x2) {
                dp[num][dir]=p[num].h-p[k].h+minof(DP(k, 0)-p[k].x1+p[num].x1,DP(k, 1)+p[k].x2-p[num].x1);
                visit[num][dir]=1;
                return dp[num][dir];
            }
            k--;
        }
        if (p[num].h-p[k].h>MAX) {
            dp[num][dir]=INF;
        }
        else
            dp[num][dir]=p[num].h;
    }
    else
    {
        k=num-1;
        while (k>0 && p[num].h-p[k].h<=MAX) {
            if (p[num].x2>=p[k].x1 && p[num].x2<=p[k].x2) {
                dp[num][dir]=p[num].h-p[k].h+minof(DP(k, 0)-p[k].x1+p[num].x2,DP(k,1)+p[k].x2-p[num].x2);
                visit[num][dir]=1;
                return dp[num][dir];
            }
            k--;
        }
        if (p[num].h-p[k].h>MAX) {
            dp[num][dir]=INF;
        }
        else
            dp[num][dir]=p[num].h;
    }
    visit[num][dir]=1;
    return dp[num][dir];
}

int main(int argc, const char * argv[]) {
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d%d%d",&N,&X,&Y,&MAX);
        memset(visit, 0, sizeof(visit));
        memset(dp, 0, sizeof(dp));
        for (int i=1; i<=N; i++) {
            scanf("%d%d%d",&p[i].x1,&p[i].x2,&p[i].h);
        }
        p[N+1].x1=X;
        p[N+1].x2=X;
        p[N+1].h=Y;
        p[0].x1=-20000;
        p[0].x2=20000;
        p[0].h=0;
        sort(p+1, p+N+2, comp);
        visit[0][0]=0;
        visit[0][1]=0;
        DP(N+1, 0);
        DP(N+1, 1);
        printf("%lld\n",minof(DP(N+1, 0),DP(N+1, 1)));
    }
    return 0;
}
