//
//  main.cpp
//  基础DP1-H-Tickets
//
//  Created by 袁子涵 on 15/10/24.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  0ms 1620KB

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <math.h>

#define INF 0x7fffffff
#define MAX 2005

using namespace::std;

int N,k,single[MAX],db[MAX];
long long int dp[MAX],out;
int second,minute,hour,flag;

int main(int argc, const char * argv[]) {
    cin >> N;
    while (N--) {
        cin >> k;
        for (int i=1; i<=k; i++) {
            scanf("%d",&single[i]);
        }
        for (int i=2; i<=k; i++) {
            scanf("%d",&db[i]);
        }
        dp[0]=0;
        dp[1]=single[1];
        for (int i=2; i<=k; i++) {
            dp[i]=min(dp[i-1]+single[i],dp[i-2]+db[i]);
        }
        out=dp[k];
        hour=out/3600;
        out%=3600;
        minute=out/60;
        out%=60;
        second=out;
        hour+=8;
        if (hour/12) {
            hour%=12;
            flag=1;
        }
        else
            flag=0;
        printf("%02d:%02d:%02d ",hour,minute,second);
        if (flag) {
            printf("pm\n");
        }
        else
            printf("am\n");
    }
    return 0;
}
