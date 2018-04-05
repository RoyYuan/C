//
//  main.cpp
//  数位DP-E-Round Numbers
//
//  Created by 袁子涵 on 15/11/4.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  0ms    716KB

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;
long long int start,finish;
long long int dp[2][35][35];

void handle()
{
    memset(dp, 0, sizeof(dp));
    dp[1][0][0]=1;
    dp[1][1][0]=1;
    dp[1][1][1]=1;
    for (int i=2; i<33; i++) {
        for (int j=i; j>=0; j--) {
            dp[1][i][j]=dp[1][i-1][j]+dp[1][i-1][j-1];
        }
    }
    dp[0][1][1]=1;
    for (int i=2; i<33; i++) {
        dp[0][i][1]=1;
        for (int j=i; j>1; j--) {
            dp[0][i][j]=dp[1][i-1][j-1];
        }
    }
}

long long int DP(long long int x)
{
    int num[35],size=0,pre=0;
    long long int sum=0;
    memset(num, 0, sizeof(num));
    while (x) {
        num[++size]=x%2;
        x/=2;
    }
    for (int i=size-1; i>=1; i--) {
        for (int j=i/2; j>0; j--) {
            sum+=dp[0][i][j];
        }
    }
    pre++;
    for (int i=size-1; i>=1; i--) {
        if (num[i]==1) {
            for (int j=(size/2)-pre; j>=0; j--) {
                sum+=dp[1][i-1][j];
            }
            pre++;
        }
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    cin >> start >> finish;
    handle();
    start=DP(start);
    finish=DP(finish+1);
    cout << finish-start << endl;
    return 0;
}
