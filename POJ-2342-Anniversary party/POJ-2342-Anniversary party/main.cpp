//
//  main.cpp
//  POJ-2342-Anniversary party
//
//  Created by 袁子涵 on 16/9/16.
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
#include <vector>
#include <queue>
#include <utility>
#include <map>

using namespace std;
const int maxn=6005;
int n;
vector<int>son[maxn];
int dp[maxn][2],root=1,fa[maxn];
void TreeDP(int now)
{
    for(int i=0;i<son[now].size();i++)
    {
        int ss=son[now][i];
        TreeDP(ss);
        dp[now][1]+=dp[ss][0];
        dp[now][0]+=max(dp[ss][0],dp[ss][1]);
    }
}
int main(int argc, const char * argv[]) {
    int s,f;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&dp[i][1]);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&s,&f);
        son[f].push_back(s);
        fa[s]=f;
    }
    scanf("%d%d",&s,&f);
    while(fa[root])
        root=fa[root];
    TreeDP(root);
    printf("%d\n",max(dp[root][0],dp[root][1]));

    return 0;
}
