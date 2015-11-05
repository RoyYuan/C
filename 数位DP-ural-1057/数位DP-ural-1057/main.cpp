//
//  main.cpp
//  数位DP-ural-1057
//
//  Created by 袁子涵 on 15/10/30.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  15ms    388KB

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int X,Y;
int dp[32][32];
int K,B;

void handle()
{
    for (int i=2; i<32; i++) {
        dp[i][0]=1;
        for (int j=1; j<=i; j++) {
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        }
    }
}

int DP(int N)
{
    int num[32],k=0,flag=-1,sum=0,need=K;
    memset(num, 0, sizeof(num));
    while (N) {
        num[++k]=N%B;
        N/=B;
    }
    if (B!=2) {
        for (int i=k; i>0; i--) {
            if (num[i]>1) {
                flag=i;
                break;
            }
        }
        for (int i=flag; i>=0; i--) {
            num[i]=1;
        }
    }
    for (int i=k;i>0; i--) {
        if (num[i]==1) {
            sum+=dp[i-1][need--];
        }
        else
            continue;
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    cin >> X >> Y;
    cin >> K >> B;
    dp[0][1]=0;
    dp[0][0]=1;
    dp[1][1]=1;
    dp[1][0]=1;
    handle();
    Y=DP(Y+1);
    X=DP(X);
    cout << Y-X << endl;
    return 0;
}
