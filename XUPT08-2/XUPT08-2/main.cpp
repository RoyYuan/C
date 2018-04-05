//
//  main.cpp
//  XUPT08-2
//
//  Created by 袁子涵 on 16/9/22.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>
#include <map>

using namespace std;
const int maxn=1e5+5;
vector<int>edge[maxn];
int dp[maxn];
int n,m,du[maxn];
long long int ma;
int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&m);
    int a,b;
    for (int i=1; i<=m; i++) {
        scanf("%d%d",&a,&b);
        if (a>b)
            swap(a, b);
        du[a]++;
        du[b]++;
        edge[b].push_back(a);
    }
    ma=0;
    for (int i=1; i<=n; i++) {
        dp[i]=1;
        for (int j=0; j<edge[i].size(); j++) {
            dp[i]=max(dp[i],dp[edge[i][j]]+1);
        }
        ma=max(1ll*dp[i]*du[i],ma);
    }
    printf("%lld\n",ma);
    return 0;
}
