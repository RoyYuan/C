//
//  main.cpp
//  2015-ccpc-H
//
//  Created by 袁子涵 on 15/11/20.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  0ms 1580KB

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;
int T;
char sudo[5][5];
bool line[5][5];
bool col[5][5];
bool mat[5][5];
int pos[5][5];

bool dfs(int x,int y)
{
    if (y==5) {
        if(dfs(x+1,1))
            return 1;
        else
            return 0;
    }
    if (x==5) {
        return 1;
    }
    if (sudo[x][y]=='*') {
        for (int i=1; i<5; i++) {
            if (line[y][i]&&col[x][i]&&mat[pos[x][y]][i]) {
                sudo[x][y]=i+'0';
                line[y][i]=col[x][i]=mat[pos[x][y]][i]=0;
                if(dfs(x, y+1))
                    return 1;
                line[y][i]=col[x][i]=mat[pos[x][y]][i]=1;
            }
        }
        sudo[x][y]='*';
    }
    else
        if(dfs(x, y+1))
            return 1;
    return 0;
}

int main(int argc, const char * argv[]) {
    int now=0;
    cin >> T;
    while (now<T) {
        memset(pos, 0, sizeof(pos));
        memset(col, 0, sizeof(col));
        memset(line, 0, sizeof(line));
        for (int i=1; i<3; i++) {
            pos[i][1]=1;
            pos[i][2]=1;
            pos[i][3]=2;
            pos[i][4]=2;
        }
        for (int i=3; i<5; i++) {
            pos[i][1]=3;
            pos[i][2]=3;
            pos[i][3]=4;
            pos[i][4]=4;
        }
        for (int i=1; i<5; i++) {
            for (int j=1; j<5; j++) {
                line[i][j]=1;
                col[i][j]=1;
                mat[i][j]=1;
            }
        }
        for (int i=1; i<5; i++) {
            for (int j=1; j<5; j++) {
                cin >> sudo[i][j];
                if (sudo[i][j]=='*') {
                    continue;
                }
                int temp=(int)sudo[i][j]-'0';
                line[j][temp]=0;
                col[i][temp]=0;
                mat[pos[i][j]][temp]=0;
            }
        }
        dfs(1,1);
        now++;
        printf("Case #%d:\n",now);
        for (int i=1; i<5; i++) {
            for (int j=1; j<5; j++) {
                printf("%c",sudo[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
