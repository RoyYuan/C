//
//  main.cpp
//  160808-2
//
//  Created by 袁子涵 on 16/8/8.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;
const int INF=0x3f3f3f3f;
int dp[505],n,s,w,total,cas;
bool vis[105];
vector<int>page[505];
int main(int argc, const char * argv[]) {
    int t;
    scanf("%d",&t);
    while (t--) {
        int tmp,tmp1;
        scanf("%d%d%d",&n,&s,&w);
        for (int i=1; i<=n; i++)
        {
            page[i].clear();
            dp[i]=INF;
        }
        for (int i=1; i<=w; i++) {
            scanf("%d",&tmp);
            for (int j=1; j<=tmp; j++) {
                scanf("%d",&tmp1);
                page[tmp1].push_back(i);
            }
        }
        dp[0]=0;
        for (int i=1; i<=n; i++) {
            memset(vis, 0, sizeof(vis));
            total=0;
            for (int j=i; j>0; j--) {
                for (int k=0; k<page[j].size(); k++) {
                    if (vis[page[j][k]]) {
                        continue;
                    }
                    vis[page[j][k]]=1;
                    total++;
                }
                if (total+i-j+1>s) {
                    break;
                }
                dp[i]=min(dp[i],dp[j-1]+total);
            }
        }
        printf("Case %d: ",++cas);
        if (dp[n]==INF) {
            printf("-1\n");
        }
        else
            printf("%d\n",dp[n]);
        
    }
    return 0;
}
//3
//5 5 3
//2 1 2
//2 3 4
//1 5
//5 2 3
//2 1 2
//2 3 4
//1 5
//1 1 1
//1 1
