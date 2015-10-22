//
//  main.cpp
//  基础DP1-A-Max Sum Plus Plus
//
//  Created by 袁子涵 on 15/10/22.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  327ms   2752KB

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define INF 1000005
#define MAX 0x7fffffff

using namespace std;

long long int n,m;
int s[INF],dp[INF],pre[INF],temp;

int main(int argc, const char * argv[]) {
    while (scanf("%lld%lld",&m,&n)!=EOF) {
        for (long long int i=1; i<=n; i++){
            scanf("%d",&s[i]);
        }
        dp[0]=0;
        temp=-MAX;
        for (long long int j=1; j<=n; j++) {
            dp[j]=max(dp[j-1]+s[j],s[j]);
            pre[j-1]=temp;
            temp=max(temp,dp[j]);
        }
        for (long long int i=2; i<=m; i++) {
            temp=-MAX;
            for (long long int j=i; j<=n; j++) {
                dp[j]=max(dp[j-1]+s[j],pre[j-1]+s[j]);
                pre[j-1]=temp;
                temp=max(temp,dp[j]);
            }
        }
        printf("%d\n",temp);
    }
    return 0;
}
