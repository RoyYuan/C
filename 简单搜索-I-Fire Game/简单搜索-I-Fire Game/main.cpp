//
//  main.cpp
//  简单搜索-I-Fire Game
//
//  Created by 袁子涵 on 15/8/3.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>

#define minof(a,b) ((a)>(b)?(b):(a))

using namespace std;

int T;
int maze[101][101];
int maze_1[101][101];
int n,m;
int times;
int flag=-1;

typedef struct plaz
{
    int x,y;
}Plaz;

Plaz origin_1,origin_2;

void move(int x,int y)
{
    if (x>0) {
        if (maze[x-1][y]==1) {
            maze[x-1][y]=3;
        }
    }
    if (x<n-1) {
        if (maze[x+1][y]==1) {
            maze[x+1][y]=3;
        }
    }
    if (y>0) {
        if (maze[x][y-1]==1) {
            maze[x][y-1]=3;
        }
    }
    if (y<m-1) {
        if (maze[x][y+1]==1) {
            maze[x][y+1]=3;
        }
    }
}

void Fire()
{
    maze[origin_1.x][origin_1.y]=2;
    maze[origin_2.x][origin_2.y]=2;
    times=0;
    while (1) {
        //点燃的向周围延伸
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (maze[i][j]==2) {
                    maze[i][j]=0;
                    move(i,j);
                }
            }
        }
        int f=1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (maze[i][j]==1 || maze[i][j]==3) {
                    f=0;
                    break;
                }
            }
        }
        if (f) {
            if (flag==-1) {
                flag=times;
                return;
            }
            flag=minof(times,flag);
            return;
        }
        f=1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (maze[i][j]==3) {
                    f=0;
                    maze[i][j]=2;
                }
                
            }
        }
        if (f) {
            return;
        }
        times++;
    }
    
    
}

int main(int argc, const char * argv[]) {
    cin >> T;
    int c=T;
    char x;
    while (c--) {
        memset(maze, 0, sizeof(maze));
        memset(maze_1, 0, sizeof(maze_1));
        flag=-1;
        cin >> n >> m;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> x;
                switch (x) {
                    case '#':
                        maze[i][j]=1;
                        break;
                    case '.':
                        maze[i][j]=0;
                        break;
                    default:
                        break;
                }
            }
        }
        memcpy(maze_1, maze, sizeof(maze));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                origin_1.x=i;
                origin_1.y=j;
                if (maze[origin_1.x][origin_1.y]!=1) {
                    continue;
                }
                for (int p=i; p<n; p++) {
                    if (p==origin_1.x) {
                        for (int q=origin_1.y; q<m; q++) {
                            origin_2.x=p;
                            origin_2.y=q;
                            if (maze[origin_2.x][origin_2.y]!=1) {
                                continue;
                            }
                            Fire();
                            memcpy(maze, maze_1, sizeof(maze));
                        }
                    }
                    else
                    {
                        for (int q=0; q<m; q++) {
                            origin_2.x=p;
                            origin_2.y=q;
                            if (maze[origin_2.x][origin_2.y]!=1) {
                                continue;
                            }
                            Fire();
                            memcpy(maze, maze_1, sizeof(maze));
                        }
                    }
                }
            }
        }
        cout << "Case " << T-c << ": " << flag << endl;
    }
    return 0;
}
