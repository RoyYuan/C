//
//  main.cpp
//  16-3
//
//  Created by 袁子涵 on 16/4/16.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,t,tmp;
long long int dp[200][35];
vector<int>coin;
int main(int argc, const char * argv[]) {
    cin >> t;
    int num=0;
    while (t--) {
        num++;
        coin.clear();
        memset(dp, 0, sizeof(dp));
        cin >> n >> m;
        for (int i=0; i<n; i++) {
            cin >> tmp;
            coin.push_back(tmp);
        }
        sort(coin.begin(), coin.end());
        dp[0][0]=1;
        for (int i=1; i<=m; i++) {
            for (int j=0; j<n; j++) {
                if (coin[j]>i) {
                    break;
                }
                for (int z=0; z<=j; z++) {
                    dp[i][j]+=dp[i-coin[j]][z];
                }
            }
        }
        long long int out=0;
        for (int i=0; i<n; i++) {
            out+=dp[m][i];
        }
        cout << "Case #" << num << ": " << out << endl;
    }
    return 0;
}
