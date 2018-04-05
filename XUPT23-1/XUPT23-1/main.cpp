//
//  main.cpp
//  XUPT23-1
//
//  Created by 袁子涵 on 17/2/13.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int mv[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
typedef struct node
{
    int x,y;
}node;
bool maze[5][5],vis[5][5];
node fa[5][5];
bool check(node x)
{
    if (x.x<0 || x.x>4 || x.y<0 || x.y>4) {
        return 0;
    }
    if (vis[x.x][x.y] || maze[x.x][x.y]==0) {
        return 0;
    }
    return 1;
}
int main(int argc, const char * argv[]) {
    int a;
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            cin >> a;
            if (a) {
                maze[i][j]=0;
            }
            else
                maze[i][j]=1;
        }
    }
    node now,nxt;
    now.x=4,now.y=4;
    vis[4][4]=1;
    queue<node> Q;
    while (!Q.empty()) {
        Q.pop();
    }
    Q.push(now);
    while (!Q.empty()) {
        now=Q.front();
        Q.pop();
        for (int i=0; i<4; i++) {
            nxt.x=now.x+mv[i][0];
            nxt.y=now.y+mv[i][1];
            if (check(nxt)) {
                vis[nxt.x][nxt.y]=1;
                Q.push(nxt);
                fa[nxt.x][nxt.y]=now;
            }
        }
    }
    now.x=now.y=0;
    while (now.x!=4 || now.y!=4) {
        cout << "(" << now.x << ", " << now.y << ")\n";
        now=fa[now.x][now.y];
    }
    cout << "(4, 4)\n";
    return 0;
}