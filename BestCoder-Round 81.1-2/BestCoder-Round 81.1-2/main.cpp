//
//  main.cpp
//  BestCoder-Round 81.1-2
//
//  Created by 袁子涵 on 16/4/22.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <vector>
#define MAXN 1000005
#define MOD 1000000007
using namespace::std;
int t,now,last;
long long int n,tmp;
long long int dp[2][MAXN];
int main(int argc, const char * argv[]) {
    cin >> t;
    while (t--) {
        cin >> n;
        memset(dp, 0, sizeof(dp));
        last=0;
        now=1;
        dp[0][0]=1;
        for (long long int i=1; i<=n; i++) {
            dp[now][0]=dp[last][0]+dp[last][1];
            tmp=min((n+1)/2,i);
            for (long long int j=1; j<=tmp; j++) {
                dp[now][j]=dp[last][j-1]+dp[last][j]+dp[last][j+1];
                dp[now][j]%=MOD;
            }
            now=1-now;
            last=1-last;
        }
        printf("%lld\n",dp[last][0]);
    }
    return 0;
}
