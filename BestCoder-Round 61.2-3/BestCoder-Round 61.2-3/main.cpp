//
//  main.cpp
//  BestCoder-Round 61.2-3
//
//  Created by 袁子涵 on 15/11/14.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

using namespace std;


long long int l,r;
int k;
long long int dp[12][10][2][7];

long long int f(int x)
{
    long long int sum=1;
    while (x) {
        sum*=10;
        x--;
    }
    return sum;
}

//void handle()
//{
//    memset(dp, 0, sizeof(dp));
//    dp[1][7][1][0]=1;
//    dp[1][8][0][1]=1;
//    dp[1][9][0][2]=1;
//    for (int i=0; i<7; i++) {
//        dp[1][i][0][i]=1;
//    }
//    for (int i=2; i<10; i++) {//位数
//        for (int j=0; j<10; j++) {//第i位
//            for (int p=0; p<10; p++) {//第i-1位
//                for (int q=0; q<7; q++) {//余数
//                    if (q==0) {
//                        if (j+p==k) {
//                            continue;
//                        }
//                        else
//                        {
//                            int temp=(j*f(i-1)+q)%7;
//                            if (temp==0) {
//                                dp[i][j][1][0]+=dp[i-1][p][1][0];
//                            }
//                            else
//                                dp[i][j][0][temp]+=dp[i-1][p][1][0];
//                            
//                        }
//                    }
//                    else
//                    {
//                        if (j+p==k) {
//                            continue;
//                        }
//                        else
//                        {
//                            int temp=(j*f(i-1)+q)%7;
//                            if (temp==0) {
//                                dp[i][j][1][0]+=dp[i-1][p][0][q];
//                            }
//                            else
//                                dp[i][j][0][temp]+=dp[i-1][p][0][q];
//                        }
//                    }
//                }
//            }
//        }
//    }
//}


int main(int argc, const char * argv[]) {
    int T;
    handle();
    cin >> T;
    while (T--) {
        cin >> l >> r >> k;
        cout <<  << endl;
    }
    return 0;
}
