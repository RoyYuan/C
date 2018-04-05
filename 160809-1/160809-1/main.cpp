//
//  main.cpp
//  160809-1
//
//  Created by 袁子涵 on 16/8/9.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
int out[125],dp[125][125],n;
int main(int argc, const char * argv[]) {
    for (int i=1; i<=120; i++) {
        dp[i][1]=dp[i][i]=1;
        for (int j=1; j<=i; j++) {
            if (dp[i][j]) {
                out[i]+=dp[i][j];
                continue;
            }
            for (int k=1; k<=min(j,i-j); k++)
                dp[i][j]+=dp[i-j][k];
            out[i]+=dp[i][j];
        }
    }
    while (scanf("%d",&n)!=EOF)
        printf("%d\n",out[n]);
    return 0;
}
