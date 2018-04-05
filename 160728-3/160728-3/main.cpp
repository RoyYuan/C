//
//  main.cpp
//  160728-3
//
//  Created by 袁子涵 on 16/7/28.
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

using namespace std;
const int MOD=1000000007;
long long int out,L1,L2,total,tmp;
long long int dp[100005];
string str,mode;
int main(int argc, const char * argv[]) {
    int t,cas=0;
    cin >> t;
    while (t--) {
        cas++;
        total=0;
        cin >> str >> mode;
        L1=str.length();
        L2=mode.length();
        for (long long int i=0; i<L2; i++)
            dp[i]=1;
        for (long long int i=L2; i<=L1; i++) {
            dp[i]=dp[i-1];
            string tt=str.substr(i-L2,L2);
            if (tt==mode)
                dp[i]+=dp[i-L2];
            dp[i]%=MOD;
        }
        cout << "Case #" << cas << ": " << dp[L1] << endl;
    }
    return 0;
}
