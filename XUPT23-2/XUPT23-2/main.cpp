//
//  main.cpp
//  XUPT23-2
//
//  Created by 袁子涵 on 17/2/13.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int maxn=1005;
int n,m;
int vis[maxn][maxn];
int now=0;
vector<int>total;
char maze[maxn][maxn];
int mv[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
bool check(int x,int y)
{
    if (x<0 || x>=n || y<0 || y>=m || maze[x][y]=='*' || vis[x][y]!=0) {
        return 0;
    }
    return 1;
}
int dfs(int x,int y)
{
    if (!check(x,y)) {
        return 0;
    }
    vis[x][y]=now;
    int tmp=0;
    for (int i=0; i<4; i++) {
        tmp+=dfs(x+mv[i][0], y+mv[i][1]);
    }
    return tmp+1;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> maze[i][j];
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (maze[i][j]=='.' && !vis[i][j]) {
                now++;
                total.push_back(dfs(i, j));
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (maze[i][j]=='*') {
                int tmp=0;
                set<int>rt;
                rt.clear();
                for (int a=0; a<4; a++) {
                    int tmpx=i+mv[a][0],tmpy=j+mv[a][1];
                    if (tmpx<0 || tmpx>=n || tmpy<0 || tmpy>=m) {
                        continue;
                    }
                    if (vis[tmpx][tmpy]) {
                        rt.insert(vis[tmpx][tmpy]-1);
                    }
                }
                set<int>::iterator it;
                for (it=rt.begin() ; it!=rt.end(); it++) {
                    tmp+=total[*it];
                }
                cout << (tmp+1)%10;
            }
            else
            {
                cout << ".";
            }
        }
        cout << endl;
    }
    return 0;
}
