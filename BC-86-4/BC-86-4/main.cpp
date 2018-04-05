//
//  main.cpp
//  BC-86-4
//
//  Created by 袁子涵 on 16/8/6.
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
#include <queue>
#include <stack>
#include <map>

using namespace std;
const int MOD=998244353;
bool dis[55][55],can[55][55][55];
int w[55];
int n,m,k,q,u,v,a,b,c;
long long int ans[55][55][55][4];
long long int out;
long long int dfs(int a,int b,int c,int flag)
{
    if (ans[a][b][c][flag]>-1)
        return ans[a][b][c][flag];
    if (flag==1) {
        if (can[a][b][c]==0) {
            return ans[a][b][c][1]=0;
        }
        ans[a][b][c][1]=1;
        for (int i=a+1; i<=n; i++) {
            if (dis[a][i]) {
                (ans[a][b][c][flag]+=dfs(i, b, c,2))%=MOD;
            }
        }
    }
    else if (flag==2)
    {
        ans[a][b][c][2]=0;
        for (int i=b+1; i<=n; i++) {
            if (dis[b][i]) {
                (ans[a][b][c][flag]+=dfs(a, i, c,3))%=MOD;
            }
        }
    }
    else
    {
        ans[a][b][c][3]=0;
        for (int i=c+1; i<=n; i++) {
            if (dis[c][i]) {
                (ans[a][b][c][flag]+=dfs(a, b, i,1))%=MOD;
            }
        }
    }
    return ans[a][b][c][flag];
}
int main(int argc, const char * argv[]) {
    int t;
    scanf("%d",&t);
    while (t--) {
        memset(dis, 0, sizeof(dis));
        memset(can, 0, sizeof(can));
        memset(ans, -1, sizeof(ans));
        scanf("%d%d%d%d",&n,&m,&k,&q);
        for (int i=1; i<=n; i++)
            scanf("%d",&w[i]);
        for (int i=1; i<=n; i++)
            for (int j=i; j<=n; j++)
                for (int x=j; x<=n; x++)
                    if (abs(w[i]-w[j])<=k && abs(w[i]-w[x])<=k && abs(w[x]-w[j])<=k)
                        can[i][j][x]=can[i][x][j]=can[j][i][x]=can[j][x][i]=can[x][i][j]=can[x][j][i]=1;
        for (int i=1; i<=m; i++) {
            scanf("%d%d",&u,&v);
            dis[u][v]=1;
        }
        for (int i=1; i<=q; i++) {
            scanf("%d%d%d",&a,&b,&c);
            printf("%lld\n",dfs(a, b, c, 1));
        }
    }
    return 0;
}
