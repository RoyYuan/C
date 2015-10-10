//
//  main.cpp
//  1004 四子连棋
//
//  Created by 袁子涵 on 15/7/26.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

char maze[5][5];

typedef struct Node
{
    unsigned long int step;
    char map[5][5];
}node;

typedef struct Queue
{
    unsigned long int head,tail;
    node q[100000];
}queue;

queue q;

void initqueue()
{
    q.head=0;
    q.tail=0;
}

void Enqueue(char t[5][5],int num)
{
    for (int i=1; i<5; i++) {
        for (int j=1; j<5; j++) {
            q.q[q.tail].map[i][j]=t[i][j];
        }
    }
    q.q[q.tail++].step=num;
}

char* Dequeue()
{
    char *t;
    t=(char*)malloc(sizeof(maze));
    for (int i=1; i<5; i++) {
        for (int j=1; j<5; j++) {
            *(t+i+j)=q.q[q.head].map[i][j];
        }
    }
    q.head++;
    return t;
}

int isqueueempty()
{
    if (q.head==q.tail) {
        return 0;
    }
    return 1;
}

int over(char *t)
{
    int bf=0,wf=0;
    for (int i=1; i<5; i++) {
        for (int j=1; j<5; j++) {
            if (*(t+i+j)=='B') {
                while (*(t+i+j+1)=='B' && ) {
                    <#statements#>
                }
            }
        }
    }
}

void bfs()
{
    char*t;
    Enqueue(maze, 0);
    while (isqueueempty()) {
        t=Dequeue();
        if (over(t)) {
            return;
        }
        
    }
}

int main(int argc, const char * argv[]) {
    memset(maze, 0, sizeof(maze));
    for (int i=1; i<5; i++) {
        for (int j=1; j<5; j++) {
            cin >> maze[i][j];
        }
    }
    bfs();
    return 0;
}
