//
//  main.cpp
//  简单搜索-J-Fire!
//
//  Created by 袁子涵 on 15/8/13.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int T;
char maze[1001][1001];
bool visit[1001][1001];
int R,C;
int flag=1;
unsigned long long int sum;

int x;
int y;

typedef struct plz
{
    int x;
    int y;
    long long int step;
    bool fire;
}Plz;

typedef struct queue
{
    long long int head,tail;
    Plz data[2000010];
}Queue;

Queue q;

void initqueue()
{
    q.tail=0;
    q.head=0;
}

bool emptyqueue()
{
    if (q.head==q.tail) {
        return 0;
    }
    return 1;
}

void bfs()
{
    Plz t,k;
    t.x=x;
    t.y=y;
    t.step=0;
    t.fire=0;
    q.data[q.tail++]=t;
    while (emptyqueue()) {
        t=q.data[q.head++];
        if (t.fire) {
            //火出队
            maze[t.x][t.y]='F';
            //上下左右
            if (t.x>0 && maze[t.x-1][t.y]!='#' && maze[t.x-1][t.y]!='F') {
                k=t;
                k.x--;
                k.step++;
                maze[k.x][k.y]='F';
                q.data[q.tail++]=k;
            }
            if (t.x<R-1 && maze[t.x+1][t.y]!='#' && maze[t.x+1][t.y]!='F') {
                k=t;
                k.x++;
                k.step++;
                maze[k.x][k.y]='F';
                q.data[q.tail++]=k;
            }
            if (t.y>0 && maze[t.x][t.y-1]!='#' && maze[t.x][t.y-1]!='F') {
                k=t;
                k.y--;
                k.step++;
                maze[k.x][k.y]='F';
                q.data[q.tail++]=k;
            }
            if (t.y<C-1 && maze[t.x][t.y+1]!='#' && maze[t.x][t.y+1]!='F') {
                k=t;
                k.y++;
                k.step++;
                maze[k.x][k.y]='F';
                q.data[q.tail++]=k;
            }
        }
        else
        {
            
            //如果已经到边缘了
            if (t.x==0 || t.y==0 || t.x==R-1 || t.y==C-1) {
                sum=t.step+1;
                flag=1;
                return;
            }
            //上下左右
            if (t.x>0 && maze[t.x-1][t.y]=='.' && visit[t.x-1][t.y]==0) {
                k=t;
                k.step++;
                k.x--;
                visit[k.x][k.y]=1;
                q.data[q.tail++]=k;
            }
            if (t.x<R-1 && maze[t.x+1][t.y]=='.' && visit[t.x+1][t.y]==0) {
                k=t;
                k.step++;
                k.x++;
                visit[k.x][k.y]=1;
                q.data[q.tail++]=k;
            }
            if (t.y>0 && maze[t.x][t.y-1]=='.' && visit[t.x][t.y-1]==0) {
                k=t;
                k.step++;
                k.y--;
                visit[k.x][k.y]=1;
                q.data[q.tail++]=k;
            }
            if (t.y<C-1 && maze[t.x][t.y+1]=='.' && visit[t.x][t.y+1]==0) {
                k=t;
                k.step++;
                k.y++;
                visit[k.x][k.y]=1;
                q.data[q.tail++]=k;
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    cin >> T;
    while (T--) {
        cin >> R >> C;
        memset(maze, 0, sizeof(maze));
        memset(visit, 0, sizeof(visit));
        flag=0;
        Plz t;
        initqueue();
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                cin >> maze[i][j];
                if (maze[i][j]=='F') {
                    t.x=i;
                    t.y=j;
                    t.step=0;
                    t.fire=1;
                    q.data[q.tail++]=t;
                }
                if (maze[i][j]=='J') {
                    x=i;
                    y=j;
                    visit[i][j]=1;
                }
            }
        }
        bfs();
        if (flag) {
            cout << sum << endl;
        }
        else
            cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
