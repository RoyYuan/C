//
//  main.cpp
//  基础DP1-I-最少拦截系统
//
//  Created by 袁子涵 on 15/10/24.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  15ms    1584KB

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>

#define MAX 100000

using namespace std;

long long int n;
int h[MAX],sum,dp[MAX],out;

int main(int argc, const char * argv[]) {
    while (scanf("%lld",&n)!=EOF) {
        for (long long int i=1; i<=n; i++) {
            scanf("%d",&h[i]);
            dp[i]=1;
        }
        dp[0]=0;
        for (long long int i=1; i<=n; i++) {
            for (long long int j=1; j<=i; j++) {
                if (h[i]>h[j]) {
                    dp[i]=max(dp[j]+1,dp[i]);
                }
            }
        }
        out=0;
        for (long long int i=1; i<=n; i++) {
            out=max(out,dp[i]);
        }
        cout << out << endl;
    }
        return 0;
}
