//
//  main.cpp
//  数位DP-C-不要62
//
//  Created by 袁子涵 on 15/10/29.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  0ms 1564KB

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

long long int n,m;
long long int dp[10][10];

void handle()
{
    for (int i=0; i<10; i++)
        if (i!=4)
            dp[1][i]=1;
    for (int i=2; i<=9; i++) {
        for (int j=0; j<=9; j++) {
            dp[i][j]=0;
            if (j==4) {
                dp[i][j]=0;
                continue;
            }
            else
            {
                if (j==6) {
                    for (int k=0; k<=9; k++) {
                        if (k==2)
                            continue;
                        dp[i][j]+=dp[i-1][k];
                    }
                }
                else
                    for (int k=0; k<=9; k++)
                        dp[i][j]+=dp[i-1][k];
            }
        }
    }
}

long long int DP(long long int N)
{
    char num[10];
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
            break;
        for (int j=num[i]-1; j>=0; j--)
        {
            if (num[i+1]==6 && j==2) {
                continue;
            }
            sum+=dp[i][j];
    
        }
        if (num[i]==4 || (num[i]==2 && num[i+1]==6))
            flag=1;
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    memset(dp, 0, sizeof(dp));
    handle();
    while (scanf("%lld%lld",&n,&m)!=EOF && (m!=0 || n!=0)) {
        long long int right,left;
        right=DP(m+1);
        left=DP(n);
        printf("%lld\n",right-left);
    }
    return 0;
}
