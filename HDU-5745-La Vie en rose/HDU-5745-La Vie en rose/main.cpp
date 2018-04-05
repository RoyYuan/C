//
//  main.cpp
//  HDU-5745-La Vie en rose
//
//  Created by 袁子涵 on 16/7/22.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <map>
#include <string>

using namespace std;

int t,now,last;
bool dp[2][15][3],flag;
long long int n,m;
string s,p;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> t;
    dp[0][0][0]=dp[0][0][2]=0;
    dp[1][0][0]=dp[1][0][2]=0;
    dp[1][0][1]=dp[0][0][1]=1;
    while (t--) {
        cin >> n >> m >> s >> p;
        now=1,last=0;
        for (long long int i=1; i<=n; i++) {
            dp[now][1][0]=dp[now][1][2]=0;
            dp[now][1][1]=(s[i-1]==p[0]);
            if (m>1)
                dp[now][1][2]=(s[i-1]==p[1]);
            for (long long int j=2; j<m; j++) {
                dp[now][j][0]=dp[last][j-1][2]&&(s[i-1]==p[j-2]);
                dp[now][j][1]=(dp[last][j-1][0]||dp[last][j-1][1])&&(s[i-1]==p[j-1]);
                dp[now][j][2]=(dp[last][j-1][0]||dp[last][j-1][1])&&(s[i-1]==p[j]);
            }
            if (m>1) {
                dp[now][m][0]=dp[last][m-1][2]&&(s[i-1]==p[m-2]);
                dp[now][m][1]=(dp[last][m-1][0]||dp[last][m-1][1])&&(s[i-1]==p[m-1]);
                flag=dp[now][m][0]||dp[now][m][1];
            }
            else
                flag=dp[now][m][1];
            if (flag)
                cout << 1;
            else
                cout << 0;
            if (now) {
                now=0;
                last=1;
            }
            else
            {
                now=1;
                last=0;
            }
        }
        cout << endl;
    }
    return 0;
}
