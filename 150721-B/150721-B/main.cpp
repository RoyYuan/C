//
//  main.cpp
//  150721-B
//
//  Created by 袁子涵 on 15/7/21.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <math.h>
using namespace std;

int T;
int n , k;
int a[100001];
int dp[3];
int temp;
int x;
int main(void){
    cin >> T;
    while(T --){
        cin >> n >> k;
        for(int i = 1; i <= n; i ++){
            cin >> a[i];
        }
        
        memset(dp, 0 , sizeof(dp));
        temp = 0;
        for(int i = 2; i <= n; i ++){
            x = i % 2 + 1;
            for(int j = 1; i - j >= 1; j ++){
                if(i == 2 && j == 1){
                    if(abs(a[2] - a[1]) < k){
                        dp[1] = 1;
                        break;
                    }
                    else
                        break;
                }
                else if(j == 1 && abs(a[i] - a[i - 1]) < k){
                    dp[x] ++;
                }
                else if(abs(a[i] - a[i - j]) < k){
                    for(int q = 1; i - q > i - j; q ++){
                        if(abs(a[i - q] - a[i - j]) >= k){
                            temp = 1;
                            break;
                        }
                    }
                    if(temp != 1){
                        dp[x] ++;
                    }
                    temp = 0;
                }
                else
                    break;
            }
            if(i >= 3 ){
                if(x == 1){
                    dp[x] += dp[2];
                    dp[2] = 0;
                }
                else{
                    dp[x] += dp[1];
                    dp[1] = 0;
                }
            }
        }
        cout << dp[x] + n << endl;
    }
}
