//
//  main.cpp
//  150927-2
//
//  Created by 袁子涵 on 15/9/27.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 9999999999;
using namespace std;
int m,n;
int T;
int maze[31][31];
int step[31][31][100];
long long int s[31][31];
long long int beauty;

long long int cal(int x,int y)
{
    long long int sum=0,final=0;
    for (int i=0; i<x+y-1; i++) {
        sum+=step[x-1][y-1][i];
        final+=(x+y-1)*step[x-1][y-1][i]*step[x-1][y-1][i];
    }
    final-=sum*sum;
    return final;
}

long long int dp(int x,int y)
{
    if (x==0 && y==0) {
        step[0][0][0]=maze[0][0];
        s[0][0]=maze[0][0];
        return s[0][0];
    }
    if (x>0 && y>0) {
        if (abs(dp(x, y-1)/(x+y+1)-maze[x][y])<abs(dp(x-1, y)/(x+y+1)-maze[x][y])) {
            s[x][y]=s[x][y-1]+maze[x][y];
            memcpy(step[x][y], step[x][y-1], sizeof(step[x][y-1]));
            step[x][y][x+y]=maze[x][y];
        }
        else
        {
            s[x][y]=s[x-1][y]+maze[x][y];
            memcpy(step[x][y], step[x-1][y], sizeof(step[x-1][y]));
            step[x][y][x+y]=maze[x][y];
        }
    }
    else
    {
        if (x==0) {
            s[x][y]=dp(x,y-1)+maze[x][y];
            memcpy(step[x][y], step[x][y-1], sizeof(step[x][y-1]));
            step[x][y][x+y]=maze[x][y];
        }
        else
        {
            s[x][y]=dp(x-1,y)+maze[x][y];
            memcpy(step[x][y], step[x-1][y], sizeof(step[x-1][y]));
            step[x][y][x+y]=maze[x][y];
        }
    }
    return s[x][y];
}


int main(int argc, const char * argv[]) {
    scanf("%d",&T);
    int p=T;
    while (p--) {
        beauty=N;
        memset(maze, 0, sizeof(maze));
        memset(step, 0, sizeof(step));
        memset(s, 0, sizeof(s));
        scanf("%d%d",&n,&m);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                scanf("%d",&maze[i][j]);
            }
        }
        dp(n-1, m-1);
        beauty=cal(n, m);
        printf("Case #%d: %lld\n",T-p,beauty);
    }
    return 0;
}
