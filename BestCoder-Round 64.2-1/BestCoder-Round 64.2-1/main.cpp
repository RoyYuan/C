//
//  main.cpp
//  BestCoder-Round 64.2-1
//
//  Created by 袁子涵 on 15/11/28.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#define MAXN 100005
using namespace std;

long long int n;
long long int f[MAXN],num[MAXN];
long long int sum=0;
long long int dp[MAXN][3];
long long int get(long long int x)
{
    return (1890*x+143)%10007;
}
int main(int argc, const char * argv[]) {
    while (cin >> n) {
        memset(num, 0, sizeof(num));
        memset(f, 0, sizeof(f));
        memset(dp, 0, sizeof(dp));
        for (int i=0; i<n; i++) {
            scanf("%lld",&num[i]);
            f[i]=get(num[i])-num[i];
        }
        dp[0][0]=num[0];
        dp[0][1]=num[0]+f[0];
        dp[0][2]=num[0];
        for (int i=1; i<n; i++) {
            dp[i][0]=dp[i-1][0]+num[i];
            dp[i][1]=max(dp[i-1][0]+num[i]+f[i],dp[i-1][1]+num[i]+f[i]);
            dp[i][2]=max(dp[i-1][2]+num[i],dp[i-1][1]+num[i]);
        }
        long long int out=max(dp[n-1][0],dp[n-1][1]);
        out=max(dp[n-1][2],out);
        cout << out << endl;
    }
    return 0;
}
