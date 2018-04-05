//
//  main.cpp
//  160809-5
//
//  Created by 袁子涵 on 16/8/9.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int dp[305][18],out[305];
void init()
{
    for (int i=1; i<=17; i++)
        dp[i*i][i]=1;
    for (int n=1; n<=300; n++) {
        dp[n][1]=1;
        for (int i=1; i*i<=n; i++) {
            if (dp[n][i]) {
                out[n]+=dp[n][i];
                continue;
            }
            for (int j=1; j<=
                 i; j++)
                dp[n][i]+=dp[n-i*i][j];
            out[n]+=dp[n][i];
        }
    }
}
int main(int argc, const char * argv[]) {
    int n;
    init();
    while (scanf("%d",&n)!=EOF && n!=0)
        printf("%d\n",out[n]);
    return 0;
}
