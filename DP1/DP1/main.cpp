//
//  main.cpp
//  DP1
//
//  Created by 袁子涵 on 17/3/6.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <list>
#include <map>
#include <stack>
using namespace::std;
const int maxn=110;
const long long int inf=0x6fffffffffffffff;
long long int dp[maxn][maxn][maxn];
long long int n,m,k,tree[maxn],color[maxn][maxn];
int main(int argc, const char * argv[]) {
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++)
        cin >> tree[i];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++) {
            dp[0][i][j]=inf;
            cin >> color[i][j];
        }
    for (int i=1; i<=k; i++) {
        for (int j=1; j<=n; j++) {
            if (j<i) {
                for (int x=1; x<=m; x++)
                    dp[i][j][x]=inf;
                continue;
            }
            if (tree[j]!=0) {
                dp[i][j][tree[j]]=dp[i][j-1][tree[j]];
                for (int x=1; x<=m; x++) {
                    if (x==tree[j])
                        continue;
                    dp[i][j][tree[j]]=min(dp[i][j][tree[j]],dp[i-1][j-1][x]);
                    dp[i][j][x]=inf;
                }
                continue;
            }
            for (int x=1; x<=m; x++) {
                dp[i][j][x]=dp[i][j-1][x]+color[j][x];
                for (int y=1; y<=m; y++) {
                    if (y==x)
                        continue;
                    dp[i][j][x]=min(dp[i][j][x],dp[i-1][j-1][y]+color[j][x]);
                }
            }
        }
    }
    long long int out=inf;
    for (int i=1; i<=m; i++)
        out=min(out,dp[k][n][i]);
    cout << (out==inf?-1:out) << endl;
    return 0;
}
