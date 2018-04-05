//
//  main.cpp
//  BestCoder-Round 75-2
//
//  Created by 袁子涵 on 16/3/12.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define M 1000000007
#define fix 97
using namespace std;
long long int dp[2005][3][26],out;
int t,n;
int main(int argc, const char * argv[]) {
    cin >> t;
    while (t--) {
        cin >> n;
        out=0;
        memset(dp, 0, sizeof(dp));
        for (int i=0; i<26; i++)
            dp[1][0][i]=1;
        for (int i=2; i<=n; i++) {
            for (int j=0; j<26; j++) {
                for (int z=0; z<26; z++) {
                    if (j==z) {
                        continue;
                    }
                    dp[i][0][j]+=dp[i-1][0][z];
                    dp[i][0][j]+=dp[i-1][1][z];
                    dp[i][0][j]+=dp[i-1][2][z];
                    dp[i][0][j]%=M;
                }
                dp[i][1][j]=dp[i-1][0][j];
                dp[i][2][j]=dp[i-1][1][j];
            }
        }
        for (int i=0; i<26; i++) {
            out+=dp[n][0][i];
            out%=M;
            out+=dp[n][1][i];
            out%=M;
            out+=dp[n][2][i];
            out%=M;
        }
        cout << out << endl;
        
    }
    return 0;
}
