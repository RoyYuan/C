//
//  main.cpp
//  搜索3
//
//  Created by 袁子涵 on 17/2/25.
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
const int maxn=1005;
int n,m,maze[maxn][maxn];
int mv[8][2]={{-1,0},{1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
typedef struct node
{
    int x,y,h;
    bool operator <(const node &r)const
    {
        return h>r.h;
    }
}node;
node maze1[maxn*maxn];
bool vis[maxn][maxn];
bool check(int x,int y)
{
    if (x<0 || x>=n || y<0 || y>=m)
        return 0;
    return !vis[x][y];
}
void dfs(int x,int y)
{
    vis[x][y]=1;
    for (int i=0; i<8; i++) {
        int tmpx=x+mv[i][0],tmpy=y+mv[i][1];
        if (check(tmpx, tmpy) && maze[tmpx][tmpy]<=maze[x][y])
            dfs(tmpx, tmpy);
    }
    return;
}
int main(int argc, const char * argv[]) {
    int ans=0,total=0,now=0,x,y;
    cin >> n >> m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            cin >> maze[i][j];
            maze1[total].x=i,maze1[total].y=j;
            maze1[total].h=maze[i][j];
            total++;
        }
    sort(maze1+0, maze1+total);
    x=maze1[0].x,y=maze1[0].y;
    while (now!=total) {
        ans++;
        dfs(x,y);
        while (vis[maze1[now].x][maze1[now].y] && now<total) {
            now++;
        }
        x=maze1[now].x,y=maze1[now].y;
    }
    cout << ans << endl;
    return 0;
}
