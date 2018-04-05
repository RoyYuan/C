//
//  main.cpp
//  160801-4
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

using namespace std;
const int mod=1e9+7;
const int maxn=15005;
const int h=1<<5;
int t,cas,a[5],n,num[h+1];
long long int fa[maxn],fb[maxn],dp[maxn][h+1],out;
long long int C(long long int a,long long int b)
{
    return fa[a]*fb[b]%mod*fb[a-b]%mod;
}
long long int DP()
{
    memset(dp, 0, sizeof(dp));
    for (int i=0; i<h; i++) {
        if (num[i]&1)
            dp[0][i]=1;
        else
            dp[0][i]=mod-1;
    }
    for (int i=1; i<=n; i++) {
        for (int mask=0; mask<h; mask++) {
            dp[i][mask]=(dp[i][mask]+dp[i-1][mask]*num[mask]%mod)%mod;
            for (int j=0; j<5; j++)
                if (!(mask&(1<<j)) && i>a[j])
                    dp[i][mask|(1<<j)]=(dp[i][mask|(1<<j)]+dp[i-1-a[j]][mask]*C(i-1,a[j])%mod)%mod;
        }
    }
    return dp[n][h-1];
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> t;
    fa[0]=fa[1]=fb[0]=fb[1]=1;
    for (int i=2; i<maxn; i++) {
        fa[i]=i;
        fb[i]=(mod-mod/i)*fb[mod%i]%mod;
    }
    for (int i=2; i<maxn; i++) {
        fa[i]=fa[i]*fa[i-1]%mod;
        fb[i]=fb[i]*fb[i-1]%mod;
    }
    for (int i=0; i<=h; i++)
        num[i]=__builtin_popcount(i);
    while (t--) {
        cas++;
        cin >> n;
        for (int i=0; i<5; i++)
            cin >> a[i];
        out=DP();
        if (n>1 && a[0]>0) {
            n--;
            a[0]--;
            out=(out-DP()+mod)%mod;
        }
        cout << "Case #" << cas << ": " << out << endl;
    }
    return 0;
}
