//
//  main.cpp
//  简单搜索-L-Oil Deposits
//
//  Created by 袁子涵 on 15/8/17.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

bool visit[101][101];
char land[101][101];
int sum;
int m,n;

void dfs(int x,int y)
{
    if (visit[x][y]) {
        return;
    }
    //先把自身消去
    land[x][y]='*';
    visit[x][y]=1;
    //上下左右斜对角
    if (x>0) {
        if (land[x-1][y]=='@') {
            dfs(x-1, y);
        }
        if (y>0 && land[x-1][y-1]=='@') {
            dfs(x-1, y-1);
        }
        if (y<n-1 && land[x-1][y+1]=='@') {
            dfs(x-1, y+1);
        }
    }
    if (x<m-1) {
        if (land[x+1][y]=='@') {
            dfs(x+1, y);
        }
        if (y>0 && land[x+1][y-1]=='@') {
            dfs(x+1, y-1);
        }
        if (y<n-1 && land[x+1][y+1]=='@') {
            dfs(x+1, y+1);
        }
    }
    if (y>0) {
        if (land[x][y-1]=='@') {
            dfs(x, y-1);
        }
    }
    if (y<n-1) {
        if (land[x][y+1]=='@') {
            dfs(x, y+1);
        }
    }
    return;
}

int main(int argc, const char * argv[]) {
    while (1) {
        cin >> m >> n;
        if (m==0) {
            return 0;
        }
        memset(land, 0, sizeof(land));
        memset(visit, 0, sizeof(visit));
        sum=0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                cin >> land[i][j];
            }
        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (visit[i][j]==0 && land[i][j]=='@') {
                    dfs(i, j);
                    sum++;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}
