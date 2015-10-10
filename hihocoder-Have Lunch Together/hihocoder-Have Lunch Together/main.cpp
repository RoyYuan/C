//
//  main.cpp
//  hihocoder-Have Lunch Together
//
//  Created by 袁子涵 on 15/10/8.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define minof(a,b)  ((a)>(b)?(b):(a))
#define Max 10005

using namespace std;
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int N,M,minout=Max;
char maze[105][105];
bool visit[105][105];
int s[105][105];

typedef struct coor
{
    int x,y;
}Coor;

typedef struct step
{
    Coor c;
    int step;
}Step;

typedef struct queue
{
    int head,tail;
    Step data[10005];
}Queue;

Coor start,temp;
Queue q;

void queue_init()
{
    q.head=q.tail=0;
    memset(q.data, 0, sizeof(q.data));
}

void queue_in(Step k)
{
    q.data[q.tail++]=k;
    visit[k.c.x][k.c.y]=1;
    s[k.c.x][k.c.y]=k.step;
}

Step queue_out()
{
    return q.data[q.head++];
}

bool queue_empty()
{
    if(q.head==q.tail)
    {
        return 1;
    }
    return 0;
}

bool coor_judge(Coor k)
{
    if (visit[k.x][k.y]==1) {
        return 0;
    }
    if (k.x<0 || k.x>N || k.y<0 || k.y>M) {
        return 0;
    }
    if (maze[k.x][k.y]=='#' || maze[k.x][k.y]=='P' ) {
        return 0;
    }
    return 1;
}

void bfs()
{
    Step k,t;
    queue_init();
    k.c=start;
    k.step=0;
    queue_in(k);
    while (!queue_empty()) {
        k=queue_out();
        for (int i=0; i<4; i++) {
            t=k;
            t.step++;
            t.c.x+=dir[i][0];
            t.c.y+=dir[i][1];
            if (coor_judge(t.c)) {
                if (maze[t.c.x][t.c.y]=='S') {
                    visit[t.c.x][t.c.y]=1;
                    s[t.c.x][t.c.y]=t.step;
                }
                else
                {
                    queue_in(t);
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    memset(maze, 0, sizeof(maze));
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> maze[i][j];
            s[i][j]=Max;
            if (maze[i][j]=='H') {
                start.x=i;
                start.y=j;
            }
        }
    }
    bfs();
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (maze[i][j]!='S') {
                continue;
            }
            for (int k=0; k<4; k++) {
                temp.x=i+dir[k][0];
                temp.y=j+dir[k][1];
                if (maze[temp.x][temp.y]=='S') {
                    minout=minof(minout, s[i][j]+s[temp.x][temp.y]);
                }
            }
        }
    }
    if (minout >=Max) {
        cout << "Hi and Ho will not have lunch." <<endl;
    }
    else
        cout << minout << endl;
    return 0;
}
