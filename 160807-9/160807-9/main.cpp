//
//  main.cpp
//  160807-9
//
//  Created by 袁子涵 on 16/8/7.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <utility>
#include <vector>
#include <map>

using namespace std;
map<string,bool>vis;
map<string,bool>win;
int n,m;
inline bool can(int x,int y,string now)
{
    if (x>=n-1 || y>=m-1)
        return 0;
    if (now[x*m+y]=='1' || now[x*m+y+1]=='1' || now[x*m+m+y]=='1' || now[x*m+m+y+1]=='1')
        return 0;
    return 1;
}
bool dfs(string now)
{
    if (vis[now])
        return win[now];
    vis[now]=1;
    for (int i=0; i<n-1; i++)
        for (int j=0; j<m-1; j++) {
            if (can(i,j,now)) {
                string next=now;
                next[i*m+j]=next[i*m+j+1]=next[i*m+m+j]=next[i*m+m+j+1]='1';
                if (dfs(next)==0) {
                    win[now]=1;
                    return 1;
                }
            }
        }
    win[now]=0;
    return 0;
}
int main(int argc, const char * argv[]) {
    string maze;
    while (scanf("%d%d",&n,&m)!=EOF) {
        maze.clear();
        win.clear();
        vis.clear();
        string tmp;
        for (int i=1; i<=n; i++) {
            cin >> tmp;
            maze+=tmp;
        }
        if (dfs(maze))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
