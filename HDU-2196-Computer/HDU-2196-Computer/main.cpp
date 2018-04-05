//
//  main.cpp
//  HDU-2196-Computer
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
const int maxn=10005;
vector<pair<int,int> >edge[maxn];
int n;
int dp[maxn][3];
void dfs1(int now,int from)
{
    int max1=0,max2=0;
    for(int i=0;i<edge[now].size();i++)
    {
        int to=edge[now][i].first,cost=edge[now][i].second;
        if(to==from)    continue;
        dfs1(to,now);
        int tmp=dp[to][0]+cost;
        if(tmp>=max1)
        {
            max2=max1;
            max1=tmp;
        }
        else if(tmp>max2)
            max2=tmp;
    }
    dp[now][0]=max1;
    dp[now][1]=max2;
}
void dfs2(int now,int from)
{
    for(int i=0;i<edge[now].size();i++)
    {
        int to=edge[now][i].first,cost=edge[now][i].second;
        if(to==from)    continue;
        dp[to][2]=max(dp[now][2],dp[to][0]+cost==dp[now][0]?dp[now][1]:dp[now][0])+cost;
        dfs2(to,now);
    }
}
int main(int argc, const char * argv[]) {
    int a,b;
    while(scanf("%d",&n)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            edge[i].clear();
        for(int i=2;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            edge[a].push_back(make_pair(i,b));
            edge[i].push_back(make_pair(a,b));
        }
        dfs1(1,0);
        dfs2(1,0);
        for(int i=1;i<=n;i++)
            printf("%d\n",max(dp[i][0],dp[i][2]));
    }
    return 0;
}
