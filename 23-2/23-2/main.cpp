//
//  main.cpp
//  23-2
//
//  Created by 袁子涵 on 16/4/23.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>

using namespace std;
int t;
int h,w,out;
char maze[105][105];
bool check(int x,int y)
{
    if (x<0 || x>=h || y<0 || y>=w) {
        return 0;
    }
    return 1;
}
void f0(int x,int y)
{
    if (check(x+1,y) && maze[x+1][y]=='|') {
        maze[x+1][y]='.';
    }
    if (check(x+1,y-1) && maze[x+1][y-1]=='/') {
        maze[x+1][y-1]='.';
    }
    if (check(x+1,y+1) && maze[x+1][y+1]==92) {
        maze[x+1][y+1]='.';
    }
    if (check(x+2, y-1) && maze[x+2][y-1]=='(') {
        maze[x+2][y-1]='.';
    }
    if (check(x+2, y+1) && maze[x+2][y+1]==')') {
        maze[x+2][y+1]='.';
    }
}
void f1(int x,int y)
{
    if (check(x, y+1) && maze[x][y+1]=='|') {
        maze[x][y+1]='.';
    }
    if (check(x, y+2) && maze[x][y+2]==92) {
        maze[x][y+2]='.';
    }
    if (check(x+1, y) && maze[x+1][y]=='(') {
        maze[x+1][y]='.';
    }
    if (check(x+1, y+2) && maze[x+1][y+2]==')') {
        maze[x+1][y+2]='.';
    }
}
void f2(int x,int y)
{
    if (check(x, y+1) && maze[x][y+1]==92) {
        maze[x][y+1]='.';
    }
    if (check(x+1, y-1) && maze[x+1][y-1]=='(') {
        maze[x+1][y-1]='.';
    }
    if (check(x+1, y+1) && maze[x+1][y+1]==')') {
        maze[x+1][y+1]='.';
    }
}
void f3(int x,int y)
{
    if (check(x+1, y-2) && maze[x+1][y-2]=='(') {
        maze[x+1][y-2]='.';
    }
    if (check(x+1, y) && maze[x+1][y]==')') {
        maze[x+1][y]='.';
    }
}
void f4(int x,int y)
{
    if (check(x, y+2) && maze[x][y+2]==')') {
        maze[x][y+2]='.';
    }
}


int main(int argc, const char * argv[]) {
    cin >> t;
    while (t--) {
        cin >> h >> w;
        out=0;
        memset(maze, 0, sizeof(maze));
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                cin >> maze[i][j];
            }
        }
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                if (maze[i][j]=='.') {
                    continue;
                }
                if (maze[i][j]=='O') {
                    out++;
                    maze[i][j]='.';
                    f0(i, j);
                    continue;
                }
                if (maze[i][j]=='/') {
                    out++;
                    maze[i][j]='.';
                    f1(i, j);
                    continue;
                }
                if (maze[i][j]=='|') {
                    out++;
                    maze[i][j]='.';
                    f2(i,j);
                    continue;
                }
                if (maze[i][j]==92) {
                    out++;
                    f3(i,j);
                    continue;
                }
                if (maze[i][j]=='(') {
                    out++;
                    maze[i][j]='.';
                    f4(i,j);
                    continue;
                }
                if (maze[i][j]==')') {
                    maze[i][j]='.';
                    out++;
                }
            }
        }
        cout << out << endl;
    }
    return 0;
}
