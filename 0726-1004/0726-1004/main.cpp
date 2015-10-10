//
//  main.cpp
//  0726-1004
//
//  Created by 袁子涵 on 15/7/28.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int m,n,T;
int maze[55][55];
int sum;

void red(int x,int y)
{
    int i=x,j=y;
    sum++;
    if (x==n-1) {
        maze[x][y]--;
        return;
    }
    maze[x][y]--;
    while (i<n && j>=0 && j<m) {
        i++;
        j++;
        if (maze[i][j]==1 || maze[i][j]==3) {
            maze[i][j]--;
        }
        else
        {
            break;
        }
    }
    return;
}

void blue(int x,int y)
{
    int i=x,j=y;
    sum++;
    if (x==n-1) {
        maze[x][y]-=2;
        return;
    }
    maze[x][y]-=2;
    while (i<n && j>0 && j<m) {
        i++;
        j--;
        if (maze[i][j]==2 || maze[i][j]==3) {
            maze[i][j]-=2;
        }
        else
        {
            break;
        }
    }
    return;
}

void green(int x,int y)
{
    red(x, y);
    blue(x, y);
    return;
}

void f(int num)
{
    for (int i=0; i<m; i++) {
        switch (maze[num][i]) {
            case 1:
                red(num,i);
                break;
            case 2:
                blue(num,i);
                break;
            case 3:
                green(num,i);
                break;
            default:
                break;
        }
    }
}

int main(int argc, const char * argv[]) {
    char x[55];
    int t;
    cin >> T;
    while (T--) {
        cin >> n;
        memset(maze, 0, sizeof(maze));
        sum=0;
        for (int i=0; i<n; i++) {
            scanf("%s",x);
            m=strlen(x);
            t=0;
            while (t<m) {
                switch (x[t]) {
                    case 'R':
                        maze[i][t]=1;
                        break;
                    case 'B':
                        maze[i][t]=2;
                        break;
                    case 'G':
                        maze[i][t]=3;
                        break;
                    case '.':
                        maze[i][t]=0;
                        break;
                    default:
                        break;
                }
                t++;
            }
        }
        for (int i=0; i<n; i++) {
            f(i);
        }
        cout << sum << endl;
    }
    return 0;
}
