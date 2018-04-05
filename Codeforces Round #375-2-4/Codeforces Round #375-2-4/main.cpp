//
//  main.cpp
//  Codeforces Round #375-2-4
//
//  Created by 袁子涵 on 16/10/3.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <utility>
#include <queue>
#include <vector>
#include <map>

using namespace std;
const int maxn=55;
typedef struct c
{
    int x,y;
}c;
typedef struct lake
{
    int size;
    vector<c>C;
    bool operator <(const lake &r)const
    {
        return size>=r.size;
    }
}L;
vector<L>Lake;
int n,m,k;
char maze[maxn][maxn];
bool vis[maxn][maxn];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool check(int x,int y)
{
    if (x<1 || x>n || y<1 || y>m) {
        return 0;
    }
    return 1;
}
bool check_sea(int x,int y)
{
    if (x==1 || y==1 || x==n || y==m) {
        return 1;
    }
    return 0;
}
lake tt;
bool dfs(int x,int y)
{
    int nx,ny;
    bool flag=1,flag1=1;
    if (check_sea(x, y)) {
        flag1=0;
    }
    tt.size++;
    c tmp;
    tmp.x=x,tmp.y=y;
    tt.C.push_back(tmp);
    for (int i=0; i<4; i++) {
        nx=x+dir[i][0],ny=y+dir[i][1];
        if (check(nx,ny)) {
            if (maze[nx][ny]==maze[x][y] && !vis[nx][ny]) {
                vis[nx][ny]=1;
                flag=dfs(nx, ny);
                if (!flag) {
                    flag1=0;
                }
            }
        }
    }
    if (!flag1) {
        return 0;
    }
    return 1;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> maze[i][j];
        }
    }
    int total=0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (maze[i][j]=='.' && !vis[i][j]) {
                tt.C.clear();
                tt.size=0;
                vis[i][j]=1;
                if (dfs(i, j)) {
                    Lake.push_back(tt);
                    total++;
                }
            }
        }
    }
    priority_queue<lake>Q;
    while (!Q.empty()) {
        Q.pop();
    }
    for (int i=1; i<=total; i++) {
        Q.push(Lake[i-1]);
    }
    int out=0;
    while (total>k) {
        total--;
        L tmp=Q.top();
        Q.pop();
        out+=tmp.size;
        for (int i=0; i<tmp.C.size(); i++) {
            maze[tmp.C[i].x][tmp.C[i].y]='*';
        }
    }
    cout << out << endl;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }
    return 0;
}