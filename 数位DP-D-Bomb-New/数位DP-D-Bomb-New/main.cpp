//
//  main.cpp
//  数位DP-D-Bomb-New
//
//  Created by 袁子涵 on 15/10/30.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  15ms    1596KB

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

int T;
long long int N,dp[20][10];

void handle()
{
    for (int i=0; i<10; i++)
        dp[1][i]=0;
    for (int i=2; i<=18; i++) {
        for (int j=0; j<=9; j++) {
            dp[i][j]=0;
            if (j==4) {
                for (int k=0; k<=9; k++) {
                    if (k==9)
                        dp[i][j]+=(long long int )pow(10, i-2);
                    else
                        dp[i][j]+=dp[i-1][k];
                }
                continue;
            }
            else
                for (int k=0; k<=9; k++) {
                    dp[i][j]+=dp[i-1][k];
                }
        }
    }
}

long long int DP(long long int N)
{
    char num[20];
    memset(num, 0, sizeof(num));
    int size=0;
    long long int sum=0;
    while (N) {
        num[++size]=N%10;
        N/=10;
    }
    bool flag=0;
    for (int i=size; i>=1; i--) {
        if (flag)
        {
            sum+=num[i]*pow(10, i-1);
            continue;
        }
        for (int j=num[i]-1; j>=0; j--)
            sum+=dp[i][j];
        if (num[i]==9 && num[i+1]==4)
            flag=1;
    }
    return sum;
}

int main()
{
    memset(dp, 0, sizeof(dp));
    memset(dp, 0, sizeof(dp));
    handle();
    cin >> T;
    while (T--) {
        scanf("%lld",&N);
        N=DP(N+1);
        printf("%lld\n",N);
    }
    return 0;
}
