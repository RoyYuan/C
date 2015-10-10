//
//  main.cpp
//  1169 传纸条
//
//  Created by 袁子涵 on 15/6/9.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int dp[100][50][50];
int m,n;
int book[50][50];

int maxof(int x1,int x2,int x3,int x4)
{
    if (x1>=x2 && x1>=x3 && x1>=x4) {
        return  x1;
    }
    if (x2>=x1 && x2>=x3 && x2>=x4) {
        return  x2;
    }
    if (x3>=x1 && x3>=x2 && x3>=x4) {
        return  x3;
    }
    if (x4>=x1 && x4>=x2 && x4>=x3) {
        return  x4;
    }
    return 0;
}

int main(void)
{
    int a,b,k;
    cin>>m>>n;
    memset(book, 0, sizeof(book));
    memset(dp, 0, sizeof(dp));
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cin>>book[i][j];
        }
    }
    for (k=1; k<=m+n-2; k++) {
        for (a=1; a<m; a++) {
            for (b=0; b<m; b++) {
                if (a<=k && b<=k && a!=b) {
                    dp[k][a][b]=maxof(dp[k-1][a][b],dp[k-1][a-1][b],dp[k-1][a][b-1],dp[k-1][a-1][b-1])+book[a][k-a]+book[b][k-b];
                }
                if (b>k) {
                    break;
                }
            }
            if (a>k) {
                break;
            }
        }
    }
    cout<<dp[m+n-3][m-1][m-2]<<endl;
}
