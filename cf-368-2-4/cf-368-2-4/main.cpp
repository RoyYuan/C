//
//  main.cpp
//  cf-368-2-4
//
//  Created by 袁子涵 on 16/8/20.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <utility>
#include <map>

using namespace std;
const int MAXN=100005;
int n,m,q;
typedef struct node
{
    int num;
    int op,i,j;
    int re;
    int fa;
    vector<int>son;
}node;
node State[105];
int now,out;
bool maze[1005][1005];
void dfs(int ,bool,int,int);
void redfs(int num,int end,int step)
{
    if (num==end) {
        cout << out << endl;
        return;
    }
    if (num<end) {
        dfs(num,0,end,step);
        return;
    }
    int op=State[num].op,x=State[num].i,y=State[num].j;
    if (op==1) {
        if (State[num].re==1) {
            maze[x][y]=0;
            out--;
        }
    }
    else if (op==2)
    {
        if (State[num].re==-1) {
            maze[x][y]=1;
            out++;
        }
    }
    else if (op==3)
    {
        for (int i=1; i<=m; i++) {
            if (maze[x][i]==1)
                maze[x][i]=0;
            else
                maze[x][i]=1;
        }
        out-=State[num].re;
    }
    redfs(State[num].fa,end,step);
}
void dfs(int num,bool flag,int end,int step)
{
    int op=State[num].op,x=State[num].i,y=State[num].j;
    if (op==1) {
        if (maze[x][y]==0) {
            maze[x][y]=1;
            State[num].re=1;
            out++;
        }
        else
        {
            State[num].re=0;
        }
    }
    else if (op==2)
    {
        if (maze[x][y]==1) {
            maze[x][y]=0;
            State[num].re=-1;
            out--;
        }
        else
        {
            State[num].re=0;
        }
    }
    else if (op==3)
    {
        State[num].re=0;
        for (int i=1; i<=m; i++) {
            if (maze[x][i]==1) {
                maze[x][i]=0;
                State[num].re--;
            }
            else
            {
                maze[x][i]=1;
                State[num].re++;
            }
        }
        out+=State[num].re;
    }
    else if (op==4)
    {
        redfs(num, x,step);
        num=x;
    }
    if (num==end) {
        cout << out << endl;
        return;
    }
    else if (flag && op!=4) {
        cout << out << endl;
    }
    for (int i=0; i<State[num].son.size(); i++) {
        if (State[num].son[i]==step+1) {
            dfs(step+1,flag,end,step+1);
            break;
        }
    }
}
int main(int argc, const char * argv[]) {
    int op,x,y,last=0;
    scanf("%d%d%d",&n,&m,&q);
    for (int i=1; i<=q; i++) {
        scanf("%d%d",&op,&x);
        if (op==1) {
            scanf("%d",&y);
            State[++now].op=op;
            State[now].num=i;
            State[now].i=x,State[now].j=y;
            State[now].fa=last;
            State[last].son.push_back(now);
            last=now;
        }
        else if (op==2)
        {
            scanf("%d",&y);
            State[++now].op=op;
            State[now].num=i;
            State[now].i=x,State[now].j=y;
            State[now].fa=last;
            State[last].son.push_back(now);
            last=now;
        }
        else if (op==3)
        {
            State[++now].op=op;
            State[now].num=i;
            State[now].i=x;
            State[now].fa=last;
            State[last].son.push_back(now);
            last=now;
        }
        else if (op==4)
        {
            State[++now].op=op;
            State[now].num=i;
            State[now].fa=last;
            State[now].i=x;
            State[last].son.push_back(now);
            last=x;
        }
    }
    dfs(1,1,-1,1);
    return 0;
}
