//
//  main.cpp
//  长大15acm-F
//
//  Created by 袁子涵 on 15/12/7.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;
int t,n;
int a[10005],b[10005];
long long int dp[2][1005];
bool flag=1;
int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    while (T--) {
        cin >> t >> n;
        flag=1;
        memset(dp, 0, sizeof(dp));
        for (int i=1; i<=t; i++)
            dp[0][i]=t;
        long long int out=t;
        for (int i=1; i<=n; i++)
            scanf("%d%d",&a[i],&b[i]);
        for (int i=1; i<=n; i++) {
            for (int j=t-a[i]; j>=1; j--) {
                dp[flag][j]=max(dp[!flag][j],(dp[!flag][j+a[i]]/(j+a[i])+b[i])*j);
                out=max(out,dp[flag][j]);
            }
            flag=!flag;
        }
        cout << out << endl;
    }
    return 0;
}
