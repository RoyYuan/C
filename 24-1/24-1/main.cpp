//
//  main.cpp
//  24-1
//
//  Created by 袁子涵 on 16/4/24.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

char maze[105][105];
int startx,starty,endx,endy;
int n,m;
typedef struct node
{
    int x,y,step;
}node;
bool vis[105][105];
bool check(int x,int y)
{
    if (x<0||x>=n||y<0||y>=m) {
        return 0;
    }
    if (maze[x][y]=='#') {
        return 0;
    }
    if (vis[x][y]==1) {
        return 0;
    }
    return 1;
}
int moved[8][2]={{-2,-1},{-2,1},{1,2},{-1,2},{2,1},{2,-1},{1,-2},{-1,-2}};
long long BFS()
{
    queue<node>q;
    memset(vis, 0, sizeof(vis));
    while (!q.empty()) {
        q.pop();
    }
    node tmp,next;
    tmp.x=startx,tmp.y=starty,tmp.step=0;
    q.push(tmp);
    vis[startx][starty]=1;
    while (!q.empty()) {
        tmp=q.front();
        next.step=tmp.step+1;
        if (tmp.x==endx && tmp.y==endy) {
            return tmp.step;
        }
        if (tmp.x>0 && maze[tmp.x-1][tmp.y]!='#') {
            for (int i=0; i<2; i++) {
                next.x=tmp.x+moved[i][0],next.y=tmp.y+moved[i][1];
                if (check(next.x,next.y )) {
                    q.push(next);
                    vis[next.x][next.y]=1;
                }
            }
        }
        if (tmp.x<n-1 && maze[tmp.x+1][tmp.y]!='#') {
            for (int i=4; i<6; i++) {
                next.x=tmp.x+moved[i][0],next.y=tmp.y+moved[i][1];
                if (check(next.x,next.y )) {
                    q.push(next);
                    vis[next.x][next.y]=1;
                }
            }
        }
        if (tmp.y>0 && maze[tmp.x][tmp.y-1]!='#') {
            for (int i=6; i<8; i++) {
                next.x=tmp.x+moved[i][0],next.y=tmp.y+moved[i][1];
                if (check(next.x,next.y )) {
                    q.push(next);
                    vis[next.x][next.y]=1;
                }
            }
        }
        if (tmp.y<m-1 && maze[tmp.x][tmp.y+1]!='#') {
            for (int i=2; i<4; i++) {
                next.x=tmp.x+moved[i][0],next.y=tmp.y+moved[i][1];
                if (check(next.x,next.y )) {
                    q.push(next);
                    vis[next.x][next.y]=1;
                }
            }
        }
        q.pop();
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    while (cin >> n >> m) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> maze[i][j];
                if (maze[i][j]=='s') {
                    startx=i,starty=j;
                }
                if (maze[i][j]=='e') {
                    endx=i,endy=j;
                }
            }
        }
        long long out=BFS();
        cout << out << endl;
    }
    return 0;
}
