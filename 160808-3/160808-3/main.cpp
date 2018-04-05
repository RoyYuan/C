//
//  main.cpp
//  160808-3
//
//  Created by 袁子涵 on 16/8/8.
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
const int INF=0x3f3f3f3f;
map<string,bool>Vis;
map<string,int>win;
int n,m;
int go[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
void p(int x,int y,char now,string &tmp)
{
    tmp[x*4+y]='0';
    for (int i=0; i<4; i++) {
        int nowx=x+go[i][0],nowy=y+go[i][1];
        if (nowx<0 || nowx>3 || nowy<0 || nowy>3) {
            continue;
        }
        else
        {
            char c=tmp[nowx*4+nowy];
            if (c==now)
                p(nowx, nowy, now, tmp);
        }
        
    }
}
void move(int x,int y,string &now)
{
    char tmp[4][4];
    p(x,y,now[x*4+y],now);
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            tmp[i][j]=now[i*4+j];
        }
    }
    for (int i=3; i>0; i--) {
        for (int j=0; j<4; j++) {
            if (tmp[i][j]=='0') {
                int tt=i;
                while (tmp[tt][j]=='0')
                    tt--;
                if (tt<0) {
                    continue;
                }
                tmp[i][j]=tmp[tt][j];
                tmp[tt][j]='0';
            }
        }
    }
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            now[i*4+j]=tmp[i][j];
        }
    }
}
int dfs(string now)
{
    bool flag=0;
    int out1=INF,out2=0;
    if (Vis[now])
        return win[now];
    Vis[now]=1;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (now[j+i*4]!='0') {
                string next=now;
                move(i,j,next);
                int tmp=dfs(next);
                if (tmp<=0)
                {
                    out1=min(out1,-tmp+1);
                    flag=1;
                }
                else
                    out2=min(out2,-tmp-1);
            }
        }
    }
    if (flag)
    {
        win[now]=out1;
        return out1;
    }
    else
    {
        win[now]=out2;
        return out2;
    }
}
int main(int argc, const char * argv[]) {
    int t,cas=0;
    string maze,tmp;
    scanf("%d",&t);
    while (t--) {
        cas++;
        Vis.clear();
        maze.clear();
        win.clear();
        for (int i=0; i<4; i++) {
            cin >> tmp;
            maze+=tmp;
        }
        printf("Case %d: ",cas);
        int tt=dfs(maze);
        if (tt>0)
            printf("win %d\n",tt);
        else
            printf("loss %d\n",-tt);
    }
    return 0;
}
