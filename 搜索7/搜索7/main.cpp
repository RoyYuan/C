//
//  main.cpp
//  搜索7
//
//  Created by 袁子涵 on 17/3/6.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <list>
#include <map>
#include <stack>
using namespace::std;
int t;
int r,c;
const int maxn=1005;
char maze[maxn][maxn];
bool vis[maxn][maxn];
typedef struct node
{
    bool flag;
    int x,y,step;
}node;
queue<node>Q;
int mv[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool check(int x,int y)
{
    if (x<0 || x>=r || y<0 || y>=c)
        return 0;
    if (maze[x][y]=='#' || maze[x][y]=='F' || vis[x][y])
        return 0;
    return 1;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        memset(vis, 0, sizeof(vis));
        cin >> r >> c;
        int sx,sy;
        node tmp,now;
        while (!Q.empty())  Q.pop();
        for (int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++) {
                cin >> maze[i][j];
                if (maze[i][j]=='F') {
                    tmp.x=i,tmp.y=j;
                    tmp.flag=1;
                    Q.push(tmp);
                }
                if (maze[i][j]=='J')
                    sx=i,sy=j;
            }
        }
        tmp.flag=0,tmp.x=sx,tmp.y=sy,tmp.step=1;
        Q.push(tmp);
        int flag=0;
        while (!Q.empty()) {
            now=Q.front();
            if (!now.flag) {
                if (now.x==0 || now.x==r-1 || now.y==0 || now.y==c-1) {
                    flag=now.step;
                    break;
                }
            }
            Q.pop();
            for (int i=0; i<4; i++) {
                tmp=now;
                tmp.x+=mv[i][0],tmp.y+=mv[i][1];
                if (check(tmp.x, tmp.y)) {
                    if (tmp.flag)
                        maze[tmp.x][tmp.y]='F';
                    else
                    {
                        tmp.step++;
                        vis[tmp.x][tmp.y]=1;
                    }
                    Q.push(tmp);
                }
            }
        }
        if (flag)
            cout << flag << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
