//
//  main.cpp
//  简单搜索-C-Catch That Cow
//
//  Created by 袁子涵 on 15/7/26.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <string.h>
#include <iostream>

#define minof(a,b)  ((a)>(b)?(b):(a))

using namespace std;

typedef struct node
{
    unsigned long int step;
    unsigned long int num;
}Node;

//队列
typedef struct queue
{
    unsigned long long int head;
    unsigned long long int tail;
    Node data[1000000];
}Queue;

unsigned long int N,K;
Queue q;
Node origin,final;
int map[1000010];

//初始化
void initqueue()
{
    q.head=0;
    q.tail=0;
}

//入队
void Enqueue(Node t)
{
    q.data[q.tail]=t;
    q.tail++;
}

//出队
Node Dequeue()
{
    return q.data[q.head++];
}

//判断空队列
int queueempty()
{
    if (q.head==q.tail) {
        return 0;
    }
    return 1;
}

//检查数范围
int checknum(unsigned long int a)
{
    if (a<=110000 && a>0 && map[a]==0) {
        return 1;
    }
    return 0;
}

void bfs()
{
    Node t,y;
    Enqueue(origin);
    while (queueempty()) {
        t=Dequeue();
        map[t.num]=1;
        if (t.num==final.num) {
            final.step=minof(final.step, t.step);
            break;
        }
        y.step=t.step+1;
        y.num=t.num+1;
        if (checknum(y.num)) {
            Enqueue(y);
        }
        y.num=t.num-1;
        if (checknum(y.num)) {
            Enqueue(y);
        }
        y.num=t.num*2;
        if (checknum(y.num)) {
            Enqueue(y);
        }
    }
}

int main()
{
    cin >> N >> K;
    initqueue();
    memset(map, 0, sizeof(map));
    origin.num=N;
    origin.step=0;
    final.step=100000;
    final.num=K;
    bfs();
    cout << final.step <<endl;
    
}