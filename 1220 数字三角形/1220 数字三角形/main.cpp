//
//  main.cpp
//  1220 数字三角形
//
//  Created by 袁子涵 on 15/7/26.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>

#define maxof(a,b)  ((a)>(b)?(a):(b))
using namespace std;

int tree[100][100];
int visit[100][100];
int n;

int dp(int level,int num)
{
    if (visit[level][num]) {
        return tree[level][num];
    }
    if (level==n-1) {
        return tree[level][num];
    }
    visit[level][num]=1;
    return tree[level][num]=tree[level][num]+maxof(dp(level+1, num),dp(level+1, num+1));
}

int main(int argc, const char * argv[]) {
    cin >> n;
    memset(visit, 0, sizeof(visit));
    memset(tree, -1, sizeof(tree));
    for (int i=0; i<n; i++) {
        for (int j=0; j<=i; j++) {
            cin >> tree[i][j];
        }
    }
    dp(0,0);
    cout << tree[0][0] <<endl;
    return 0;
}
