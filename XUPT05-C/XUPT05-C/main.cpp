//
//  main.cpp
//  XUPT05-C
//
//  Created by 袁子涵 on 16/9/9.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;
long long int n;
const int maxn=100005;
const long long int inf=0x6fffffffffffffff;
string str1[maxn],str2[maxn];
long long int c[maxn],dp[2][maxn];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> n;
    for (long long int i=1; i<=n; i++)
        cin >> c[i];
    for (long long int i=1; i<=n; i++) {
        cin >> str1[i];
        str2[i]=str1[i];
        reverse(str2[i].begin(), str2[i].end());
    }
    dp[1][1]=c[1];
    bool flag=1;
    for (long long int i=2; i<=n; i++) {
        dp[0][i]=dp[1][i]=inf;
        if (str1[i]>=str1[i-1])
            dp[0][i]=min(dp[0][i],dp[0][i-1]);
        if (str1[i]>=str2[i-1])
            dp[0][i]=min(dp[0][i],dp[1][i-1]);
        if (str2[i]>=str1[i-1])
            dp[1][i]=min(dp[1][i],dp[0][i-1]+c[i]);
        if (str2[i]>=str2[i-1])
            dp[1][i]=min(dp[1][i],dp[1][i-1]+c[i]);
        if (dp[0][i]==inf && dp[1][i]==inf) {
            flag=0;
            break;
        }
    }
    if (!flag) {
        cout << -1 << endl;
        return 0;
    }
    long long int out=min(dp[0][n],dp[1][n]);
    cout << out << endl;
    return 0;
}
