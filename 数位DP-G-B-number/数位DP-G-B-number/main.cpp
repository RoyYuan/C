//
//  main.cpp
//  数位DP-G-B-number
//
//  Created by 袁子涵 on 15/11/14.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  0ms 1612KB

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

long long int dp[12][10][2][13];

long long int p(int n)
{
    long long int out=1;
    while (n) {
        out*=10;
        n--;
    }
    return out;
}

long long int dfs(int size,int head,int have,int mod)
{
    if (dp[size][head][have][mod]!=-1) {
        return dp[size][head][have][mod];
    }
    long long int bit=p(size-1);
    int temp=(13+mod-head*bit%13)%13;
    dp[size][head][have][mod]=0;
    for (int i=0; i<10; i++) {
        if (have) {
            dp[size][head][have][mod]+=dfs(size-1, i, 1, temp);
            if (head==1 && i==3) {
                dp[size][head][have][mod]+=dfs(size-1, i, 0, temp);
            }
        }
        else
        {
            if (head==1 && i==3) {
                continue;
            }
            else
                dp[size][head][have][mod]+=dfs(size-1, i, 0, temp);
        }
    }
    return dp[size][head][have][mod];
}

long long int solve(long long int n)
{
    int num[12],l=0,flag=0,mod=0;
    long long int sum=0;
    memset(num, 0, sizeof(num));
    while (n) {
        num[++l]=n%10;
        n/=10;
    }
    for (int i=l; i>0; i--) {
        for (int j=0; j<num[i]; j++) {
            if (flag || (j==3 && num[i+1]==1)) {
                sum+=dfs(i, j, 1, (13-mod*p(i)%13)%13);
                sum+=dfs(i, j, 0, (13-mod*p(i)%13)%13);
            }
            else
                sum+=dfs(i, j, 1, (13-mod*p(i)%13)%13);
        }
        if (num[i+1]==1 && num[i]==3) {
            flag=1;
        }
        mod=(mod*10+num[i])%13;
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    long long int n;
    memset(dp, -1, sizeof(dp));
    for (int i=0; i<10; i++) {
        for (int j=0; j<=12; j++) {
            dp[1][i][1][j]=0;
            dp[1][i][0][j]=0;
        }
        dp[1][i][0][i]=1;
    }
    dp[2][1][1][0]=1;
    while (scanf("%lld",&n)!=EOF) {
        cout << solve(n+1) << endl;
    }
    return 0;
}
