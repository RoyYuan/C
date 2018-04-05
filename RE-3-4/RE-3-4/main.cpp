//
//  main.cpp
//  RE-3-4
//
//  Created by 袁子涵 on 17/8/2.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <utility>
using namespace std;
const int maxn=5e3+5;
string s;
long long int out[maxn],dp[maxn][maxn];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> s;
    int l=s.size();
    for (int i=0; i<l; i++) {
        for (int j=0; j+i<l && i-j>=0; j++) {
            if (s[i+j]==s[i-j])
                dp[i-j][i+j]=1,out[1]++;
            else
                break;
        }
        for (int j=0; j+i+1<l && i-j>=0; j++) {
            if (s[i+j+1]==s[i-j])
                dp[i-j][i+j+1]=1,out[1]++;
            else
                break;
        }
    }
    for (int j=2; j<=l; j++) {
        for (int i=0; i+j<=l; i++)  {
            int mid=i+j/2-1;
            if (dp[i][i+j-1] && dp[i][mid]) {
                dp[i][i+j-1]=max(dp[i][mid]+1,dp[i][i+j-1]);
                out[dp[i][i+j-1]]++;
            }
        }
    }
    for (int i=l; i>1; i--) {
        out[i]+=out[i+1];
    }
    for (int i=1; i<=l; i++) {
        cout << out[i] << ' ';
    }
    cout << endl;
    return 0;
}
