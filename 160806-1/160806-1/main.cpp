//
//  main.cpp
//  160806-1
//
//  Created by 袁子涵 on 16/8/6.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <utility>
#include <string>

using namespace std;
int n,f,d;
const int MAXN=1100;
int maze[MAXN][MAXN];
int gap[MAXN],dis[MAXN],pre[MAXN],cur[MAXN];
int sap(int start,int end,int nodenum)
{
    memset(cur,0,sizeof(cur));
    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
    int u=pre[start]=start,maxflow=0,aug=-1;
    gap[0]=nodenum;
    while(dis[start]<nodenum)
    {
    loop:
        for(int v=cur[u]; v<nodenum; v++)
            if(maze[u][v] && dis[u]==dis[v]+1)
            {
                if(aug==-1 || aug>maze[u][v])aug=maze[u][v];
                pre[v]=u;
                u=cur[u]=v;
                if(v==end)
                {
                    maxflow+=aug;
                    for(u=pre[u]; v!=start; v=u,u=pre[u])
                    {
                        maze[u][v]-=aug;
                        maze[v][u]+=aug;
                    }
                    aug=-1;
                }
                goto loop;
            }
        int mindis=nodenum-1;
        for(int v=0; v<nodenum; v++)
            if(maze[u][v]&&mindis>dis[v])
            {
                cur[u]=v;
                mindis=dis[v];
            }
        if((--gap[dis[u]])==0)break;
        gap[dis[u]=mindis+1]++;
        u=pre[u];
    }
    return maxflow;
}
int main(void)
{
    int num1,num2,tmp;
    ios::sync_with_stdio(false);
    cin >> n >> f >> d;
    int total=f+d+1;
    for(int i=1; i<=n; i++)
    {
        cin >> num1 >> num2;
        for(int j=1; j<=num1; j++)
        {
            cin >> tmp;
            maze[tmp][total+i]=1;
        }
        for(int j=1; j<=num2; j++)
        {
            cin >> tmp;
            maze[total+n+i][tmp+f]=1;
        }
    }
    for(int i=1; i<=n; i++)
        maze[total+i][total+n+i]=1;
    for(int i=1; i<=f; i++)
        maze[0][i]=1;
    for(int i=f+1; i<total; i++)
        maze[i][total]=1;
    cout << sap(0,total,total+1+2*n) << endl;
    return 0;
}
