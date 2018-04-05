//
//  main.cpp
//  160801-1
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
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;
int w,l,dp[305];
string str,word[605];
int now[605],len[605];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    while (cin >> w >> l) {
        cin >> str;
        for (int i=1; i<=w; i++) {
            cin >> word[i];
            len[i]=word[i].length();
            now[i]=0;
        }
        dp[l+1]=0;
        for (int i=l; i>=1; i--) {
            dp[i]=dp[i+1]+1;
            memset(now, 0, sizeof(now));
            for (int j=i; j<=l; j++) {
                for (int k=1; k<=w; k++) {
                    if (str[j-1]==word[k][now[k]]) {
                        now[k]++;
                    }
                    if (now[k]==len[k]) {
                        dp[i]=min(dp[i],dp[j+1]+j+1-i-len[k]);
                        now[k]=0;
                    }
                }
            }
        }
        cout << dp[1] << endl;
    }
    return 0;
}
