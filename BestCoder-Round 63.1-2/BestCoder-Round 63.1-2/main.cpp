//
//  main.cpp
//  BestCoder-Round 63.1-2
//
//  Created by 袁子涵 on 15/11/21.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#define INF 0x7fffffff

using namespace std;
int m,n;
long long int a[1010][1010],dp[1010][1010];

long long int A(int x,int y)
{
    if (x<0 || x>=n || y<0 || y>=m) {
        return INF;
    }
    else
        return a[x][y];
}

long long int DP(int x,int y)
{
    if (x<0 || x>=n || y<0 || y>=m) {
        return INF;
    }
    if (dp[x][y]!=INF) {
        return dp[x][y];
    }
    if ((x+y)%2==0) {
        dp[x][y]=min(DP(x-1, y), DP(x,y-1));
    }
    else
    {
        dp[x][y]=min(DP(x-1,y)+A(x-1,y)*A(x,y),DP(x, y-1)+A(x,y-1)*A(x,y));
    }
    return dp[x][y];
}

int main(int argc, const char * argv[]) {
    while (cin >> n >> m) {
        memset(a, 0, sizeof(a));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                dp[i][j]=INF;
            }
        }
        dp[0][0]=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                scanf("%lld",&a[i][j]);
            }
        }
        cout << DP(n-1, m-1) << endl;
    }
    return 0;
}
