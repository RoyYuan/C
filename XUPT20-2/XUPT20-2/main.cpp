//
//  main.cpp
//  XUPT20-2
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
bool maze[maxn][maxn];
string str;
vector<pair<int,int>>edge[maxn][maxn];
int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
bool check(int x,int y)
{
    if (x<0 || x>50 || y<0 || y>50)
        return 0;
    return maze[x][y];
}
bool in()
{
    bool flag=1;
    char tmp;
    memset(maze, 0, sizeof(maze));
    if(!(cin >> tmp))
        return 0;
    else
        maze[1][1]=tmp;
    for (int j=2; tmp!='\n';j++;maze[1][j]=tmp) {
        cin >> tmp;
    }
    for (int i=2; ; i++) {
        for (int j=1; tmp!='\n'; j++) {
            cin >> tmp;
        }
    }
    for(j=2;scanf("%c",&temp)&&temp!=10;mp[1][j++]=temp);
    
    for(n=2;j!=1;n++)
        for(j=1;scanf("%c",&temp)&&temp!=10;mp[n][j++]=temp);
    return 1;
}
bool vis[maxn][maxn];
int total;
void bfs(int x,int y)
{
    
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int wid=0;
    while (in()) {
        total=0;
        for (int i=0; i<50; i++) {
            for (int j=0; j<50; j++) {
                if (maze[i][j]==' ') {
                    total++;
                    bfs(i,j);
                }
            }
        }
    }
    return 0;
}
#include<iostream>
using namespace std;

char mp[60][60];
int num;

void bfs(int x,int y)
{
    if(x<0||x>51||y<0||y>51) return;
    if('*'==mp[x][y])	return;
    mp[x][y]='*';
    
				bfs(x-1,y);
    bfs(x,y-1);				bfs(x,y+1);
				bfs(x+1,y);
}


int main()
{
    int i,j,k,n;
    char temp;
    while(readin())
    {
        for(num=0,i=0;i<=51;i++)
            for(j=0;j<=51;j++)
                if(' '==mp[i][j])
                {
                    num++;
                    bfs(i,j);
                }
        printf("%c\n",num==2?'A':'C');
    }
    return 0;
}

