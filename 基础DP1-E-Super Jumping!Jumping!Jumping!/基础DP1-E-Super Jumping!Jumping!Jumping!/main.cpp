//
//  main.cpp
//  基础DP1-E-Super Jumping!Jumping!Jumping!
//
//  Created by 袁子涵 on 15/10/23.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 1005
#define INF 0x7ffffff

using namespace std;

int N,num[MAX];
long long int dp[MAX],out;

int main(int argc, const char * argv[]) {
    while (scanf("%d",&N)!=EOF && N!=0) {
        for (int i=1; i<=N; i++) {
            scanf("%d",&num[i]);
            dp[i]=num[i];
        }
        dp[0]=0;
        num[0]=INF;
        out=num[1];
        for (int i=1; i<=N; i++) {
            for (int j=1; j<i; j++) {
                if (num[i]>num[j]) {
                    dp[i]=max(dp[i],dp[j]+num[i]);
                    out=max(out,dp[i]);
                }
            }
        }
        printf("%lld\n",out);
    }
    return 0;
}
