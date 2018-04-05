//
//  main.cpp
//  XUPT20-3
//
//  Created by 袁子涵 on 16/11/25.
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
#include <queue>
#include <vector>
#include <stack>
#include <utility>

using namespace std;
const int maxn=55;
int n,m;
char maze[maxn][maxn];
bool used[maxn];
char out[maxn];
int Total,rbGs[maxn],Idx[maxn],stk[maxn],pxIdx[maxn];
int minX[maxn], maxX[maxn], minY[maxn], maxY[maxn];
bool G[maxn][maxn],vis[maxn];
void init(){
    memset(used, 0, sizeof(used));
    memset(G, 0, sizeof(G));
    memset(rbGs, 0, sizeof(rbGs));
    memset(vis, 0, sizeof(vis));
    Total=0;
}
void dfs(int now){
    if(now == Total){
        for(int i=0; i<now; i++)
            cout << out[stk[i]];
        cout << endl;
        return;
    }
    for(int x=0; x<Total; x++){
        int i=pxIdx[x];
        if(vis[i]|| rbGs[i]>0) continue;
        vis[i]=1;
        stk[now]=i;
        for(int j=0; j<Total; j++){
            if(G[i][j])
                rbGs[j]--;
        }
        dfs(now+1);
        for(int j=0; j<Total; j++){
            if(G[i][j])
                rbGs[j]++;
        }
        vis[i]=0;
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    while(cin >>n >>m){
        init();
        for(int i=0; i<n; i++){
            for (int j=0; j<m; j++) {
                cin >>maze[i][j];
                if (maze[i][j]!='.' && !used[maze[i][j]-'A']) {
                    used[maze[i][j]-'A']=true;
                    Idx[maze[i][j]-'A']=Total;
                    out[Total]=maze[i][j];
                    Total++;
                }
            }
        }
        for(int i=0; i<Total; i++)
            minX[i]=minY[i]=0x7fffffff;
        memset(maxX, 0, sizeof(maxX));
        memset(maxY, 0, sizeof(maxY));
        int pos=0;
        for(int i=0; i<maxn; i++){
            if(!used[i])
                continue;
            pxIdx[pos]=Idx[i];
            pos ++;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(maze[i][j]=='.')
                    continue;
                int zmIdx=Idx[maze[i][j]-'A'];
                minX[zmIdx]=min(minX[zmIdx],i);
                maxX[zmIdx]=max(maxX[zmIdx],i);
                minY[zmIdx]=min(minY[zmIdx],j);
                maxY[zmIdx]=max(maxY[zmIdx],j);
            }
        }
        for(int i=0; i<Total; i++){
            int x1=minX[i], y1=minY[i], x2=maxX[i], y2=maxY[i];
            for(int j=y1; j<y2; j++)
                if(maze[x1][j]!=out[i] && maze[x1][j]!='.')
                    G[i][Idx[maze[x1][j]-'A']]=1;
            for(int j=x1; j<x2; j++)
                if(maze[j][y2]!= out[i] && maze[j][y2]!= '.')
                    G[i][Idx[maze[j][y2]-'A']]=1;
            for(int j=y2; j>y1; j--)
                if(maze[x2][j]!= out[i] && maze[x2][j]!= '.')
                    G[i][Idx[maze[x2][j]-'A']]=1;
            for(int j=x2; j>x1; j--)
                if(maze[j][y1]!= out[i] && maze[j][y1]!= '.')
                    G[i][Idx[maze[j][y1]-'A']]=1;
        }
        for(int i=0; i<Total; i++)
            for(int j=0; j<Total; j++)
                if(G[i][j])
                    rbGs[j]++;
        dfs(0);
    }
    return 0;
}