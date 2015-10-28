//
//  main.cpp
//  基础DP1-Q-Phalanx
//
//  Created by 袁子涵 on 15/10/28.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  2449ms  7500KB

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#define MAX 1005

using namespace std;

char phalanx[MAX][MAX];
int dp[MAX][MAX],n;
bool visit[MAX][MAX];

int DP(int x,int y)
{
    if (x<1 || y<1 || x>n || y>n) {
        return 0;
    }
    if (visit[x][y]) {
        return dp[x][y];
    }
    int temp,flag=0;
    temp=DP(x-1, y+1);
    for (int i=1; i<=temp; i++) {
        if (phalanx[x-i][y]!=phalanx[x][y+i]) {
            break;
        }
        flag++;
    }
    if (flag) {
        dp[x][y]=max(dp[x][y],flag+1);
    }
    visit[x][y]=1;
    return dp[x][y];
}

int main(int argc, const char * argv[]) {
    while (scanf("%d",&n)!=EOF && n!=0) {
        for (int i=1; i<=n; i++) {
            int c;
            while((c = getchar()) != '\n' && c != EOF);
            for (int j=1; j<=n; j++) {
                scanf("%c",&phalanx[i][j]);
            }
            
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                dp[i][j]=1;
                visit[i][j]=0;
            }
        }
        for (int i=1; i<=n; i++) {
            visit[1][i]=1;
        }
        int out =1;
        for (int i=2; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                out=max(out,DP(i, j));
            }
        }
        cout << out << endl;
    }
    return 0;
}
