//
//  main.cpp
//  简单搜索-K-迷宫问题
//
//  Created by 袁子涵 on 15/8/9.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

bool maze[6][6];
bool visit[6][6];

typedef struct node
{
    int x,y;
    struct node *pre;
}Node;

typedef struct queue
{
    int head,tail;
    Node data[50];
}Queue;

Queue q;
Node final,out[50];

void init_queue()
{
    q.head=0;
    q.tail=0;
}

bool empty_queue()
{
    if (q.head==q.tail) {
        return 0;
    }
    return 1;
}

void bfs()
{
    Node t;
    q.data[0].x=0;
    q.data[0].y=0;
    visit[0][0]=1;
    q.tail++;
    while (empty_queue()) {
        t=q.data[q.head];
        //判断是否到终点
        if (t.x==4 && t.y==4) {
            final=q.data[q.head];
            return;
        }
        //上下左右
        if (t.x>0 && visit[t.x-1][t.y]==0 && maze[t.x-1][t.y]==0) {
            q.data[q.tail].x=t.x-1;
            q.data[q.tail].y=t.y;
            q.data[q.tail].pre=&q.data[q.head];
            q.tail++;
            visit[t.x-1][t.y]=1;
        }
        if (t.x<4 && visit[t.x+1][t.y]==0 && maze[t.x+1][t.y]==0) {
            q.data[q.tail].x=t.x+1;
            q.data[q.tail].y=t.y;
            q.data[q.tail].pre=&q.data[q.head];
            q.tail++;
            visit[t.x+1][t.y]=1;
        }
        if (t.y>0 && visit[t.x][t.y-1]==0 && maze[t.x][t.y-1]==0) {
            q.data[q.tail].x=t.x;
            q.data[q.tail].y=t.y-1;
            q.data[q.tail].pre=&q.data[q.head];
            q.tail++;
            visit[t.x][t.y-1]=1;
        }
        if (t.y<4 && visit[t.x][t.y+1]==0 && maze[t.x][t.y+1]==0) {
            q.data[q.tail].x=t.x;
            q.data[q.tail].y=t.y+1;
            q.data[q.tail].pre=&q.data[q.head];
            q.tail++;
            visit[t.x][t.y+1]=1;
        }
        q.head++;
    }
}

int main(int argc, const char * argv[]) {
    Node *p1,*p2;
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            cin >> maze[i][j];
        }
    }
    bfs();
    p1=&final;
    int t=0;
    while (p1!=NULL) {
        p2=p1->pre;
        out[t].x=p1->x;
        out[t].y=p1->y;
        t++;
        p1=p2;
    }
    while (t--) {
        printf("(%d, %d)\n",out[t].x,out[t].y);
    }
    return 0;
}
