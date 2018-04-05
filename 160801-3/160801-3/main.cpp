//
//  main.cpp
//  160801-3
//
//  Created by 袁子涵 on 16/8/1.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <map>
#include <set>

using namespace std;
const int INF=0x7fffffff;
int n,k,now,nxt;
long long int s,dp[2][151][150*300+1],num[151],S,out;
int main(int argc, const char * argv[]) {
    scanf("%d%d%lld",&n,&k,&s);
    for (int i=1; i<=n; i++)
        scanf("%lld",&num[i]);
    if (s>=n*n) {
        sort(num+1,num+n+1);
        out=0;
        for (int i=1; i<=k; i++)
            out+=num[i];
        printf("%lld\n",out);
        return 0;
    }
    now=0,nxt=1;
    for (int i=1; i<=n; i++)
        for (int j=0; j<=n*n; j++)
            dp[0][i][j]=dp[1][i][j]=INF;
    S=s+(1+k)*k/2;
    for (int i=1; i<=n; i++) {
        now^=1,nxt^=1;
        for (int j=1; j<=i; j++) {
            for (int x=1; x<=S; x++) {
                dp[now][j][x]=dp[nxt][j][x];
                if (x>=i && dp[nxt][j-1][x-i]!=INF)
                    dp[now][j][x]=min(dp[now][j][x],dp[nxt][j-1][x-i]+num[i]);
            }
        }
    }
    out=INF;
    for (int i=0; i<=S; i++)
        out=min(out,dp[now][k][i]);
    cout << out << endl;
    return 0;
}
