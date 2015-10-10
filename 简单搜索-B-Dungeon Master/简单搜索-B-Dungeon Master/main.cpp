//
//  main.cpp
//  简单搜索-B-Dungeon Master
//
//  Created by 袁子涵 on 15/7/20.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
struct node
{
    int x,y,z;
    int time;
};
char map[33][33][33];
bool flag[33][33][33];
int dir[][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
int L,R,C;
int sx,sy,sz,ex,ey,ez;

bool judge(node p)
{
    if(p.x<0 || p.z<0 || p.y<0 || p.x>=L || p.y>=R || p.z>=C || flag[p.x][p.y][p.z] || map[p.x][p.y][p.z]=='#')
    {
        return false;
    }
    return true;
}
void bfs()
{
    node p,temp;
    int i;
    queue<node>q;
    while(!q.empty())
    {
        q.pop();
    }
    flag[sx][sy][sz]=true;
    p.x=sx;
    p.y=sy;
    p.z=sz;
    p.time=0;
    q.push(p);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        for(i=0;i<6;i++)
        {
            temp=p;
            temp.x+=dir[i][0];
            temp.y+=dir[i][1];
            temp.z+=dir[i][2];
            temp.time=p.time+1;
            if(!judge(temp))
            {
                continue;
            }
            if(map[temp.x][temp.y][temp.z]=='E')
            {
                printf("Escaped in %d minute(s).\n",temp.time);
                return;
            }
            flag[temp.x][temp.y][temp.z]=true;
            q.push(temp);
        }
    }
    printf("Trapped!\n");
    
}
int main()
{
    while(~scanf("%d%d%d",&L,&R,&C))
    {
        if(L==0 && R==0 && C==0)
        {
            break;
        }
        int i,j,k;
        for(i=0;i<L;i++)
        {
            for(j=0;j<R;j++)
            {
                scanf("%s",map[i][j]);
            }
        }
        for(i=0;i<L;i++)
        {
            for(j=0;j<R;j++)
            {
                for(k=0;k<C;k++)
                {
                    if(map[i][j][k]=='S')
                    {
                        sx=i;
                        sy=j;
                        sz=k;
                    }
                }
            }
        }
        memset(flag,false,sizeof(flag));
        bfs();
    }
    return 0;
}