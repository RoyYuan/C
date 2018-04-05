//
//  main.cpp
//  160801-2
//
//  Created by 袁子涵 on 16/8/1.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <utility>

using namespace std;
const int MOD=1024523;
const int MAXN=501;
string U,D;
int n,m,dp[MAXN][MAXN][MAXN],top;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    while (cin >> n >> m) {
        cin >> U >> D;
        dp[0][0][0]=1;
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=m; j++) {
                top=min(n,i+j);
                for (int k=top; k>=0; k--) {
                    if (i+j-k>m)
                        break;
                    if (i<n && k<n && U[n-1-i]==U[n-1-k]) {
                        dp[i+1][j][k+1]+=dp[i][j][k];
                        dp[i+1][j][k+1]%=MOD;
                    }
                    if (i<n && i+j-k<m && U[n-1-i]==D[m-(i+j-k)-1]) {
                        dp[i+1][j][k]+=dp[i][j][k];
                        dp[i+1][j][k]%=MOD;
                    }
                    if (j<m && k<n && U[n-1-k]==D[m-1-j]) {
                        dp[i][j+1][k+1]+=dp[i][j][k];
                        dp[i][j+1][k+1]%=MOD;
                    }
                    if (j<m && i+j-k<m && D[m-1-j]==D[m-1-(i+j-k)]) {
                        dp[i][j+1][k]+=dp[i][j][k];
                        dp[i][j+1][k]%=MOD;
                    }
                }
            }
        }
        cout << dp[n][m][n] << endl;
    }
    return 0;
}