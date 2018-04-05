//
//  main.cpp
//  搜索1
//
//  Created by 袁子涵 on 17/2/24.
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
int mv[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int maxn=105;
bool vis[maxn][maxn],maze[maxn][maxn];
int n,m,ans;
bool check(int x,int y)
{
    if (x<0 || x>=n || y<0 || y>=m)
        return 0;
    return maze[x][y];
}
void dfs(int x,int y)
{
    if (vis[x][y])
        return;
    vis[x][y]=1;
    for (int i=0; i<8; i++)
        if (check(x+mv[i][0], y+mv[i][1]))
            dfs(x+mv[i][0], y+mv[i][1]);
    return;
}
int main(int argc, const char * argv[]) {
    while (cin >> n >> m && n && m) {
        memset(vis, 0, sizeof(vis));
        memset(maze, 0, sizeof(maze));
        ans=0;
        char c;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> c;
                if (c=='@')
                    maze[i][j]=1;
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (maze[i][j] && !vis[i][j]) {
                    ans++;
                    dfs(i,j);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
