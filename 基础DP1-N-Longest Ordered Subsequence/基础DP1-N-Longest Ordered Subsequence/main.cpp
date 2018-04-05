//
//  main.cpp
//  基础DP1-N-Longest Ordered Subsequence
//
//  Created by 袁子涵 on 15/10/24.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  0ms 716KB

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace::std;

int num[1005],dp[1005],n,out;

int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    num[0]=-1;
    for (int i=1; i<=n; i++) {
        scanf("%d",&num[i]);
    }
    out=1;
    for (int i=1; i<=n; i++) {
        dp[i]=1;
        for (int j=1; j<i; j++) {
            if (num[j]<num[i]) {
                dp[i]=max(dp[j]+1,dp[i]);
            }
        }
        out=max(out,dp[i]);
    }
    printf("%d\n",out);
    return 0;
}
