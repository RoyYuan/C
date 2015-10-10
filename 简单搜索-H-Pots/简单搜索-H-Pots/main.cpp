//
//  main.cpp
//  简单搜索-H-Pots
//
//  Created by 袁子涵 on 15/8/2.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int A,B,C;
int sum;
int flag=0;
bool visit[101][101];

typedef struct data
{
    int op;
    int x,y;
    int a,b;
    int step;
    struct data  *father;
    struct data  *next;
}Data;

typedef struct queue
{
    int head,tail;
    Data data[10001];
}Queue;

Queue q;
Data *m,*n;

bool queue_empty()
{
    if (q.head==q.tail) {
        flag=-1;
        return 0;
    }
    return 1;
}

void queue_init()
{
    q.head=0;
    q.tail=0;
}

void queue_En(Data t)
{
    visit[t.a][t.b]=1;
    q.data[q.tail++]=t;
}

Data queue_De()
{
    Data t;
    t=q.data[q.head++];
    return t;
}

void bfs()
{
    Data t,k;
    t.step=0;
    t.a=0;
    t.b=0;
    t.x=0;
    t.y=0;
    t.op=0;
    t.father=NULL;
    t.next=NULL;
    queue_init();
    queue_En(t);
    while (queue_empty()) {
        t=queue_De();
        if (t.a==C || t.b==C) {
            sum=t.step;
            *m=t;
            flag=1;
            return;
        }
        //FILL
        if (t.a<A && t.b<B) {
            k=t;
            k.a=A;
            k.op=1;
            k.x=1;
            k.father=&q.data[q.head-1];
            k.step++;
            if (!visit[k.a][k.b])
                queue_En(k);
        }
        if (t.b<B && t.a<A) {
            k=t;
            k.b=B;
            k.op=1;
            k.x=2;
            k.father=&q.data[q.head-1];
            k.step++;
            if (!visit[k.a][k.b])
                queue_En(k);
        }
        //DROP
        if (t.a>0 && t.b>0) {
            k=t;
            k.a=0;
            k.op=2;
            k.x=1;
            k.father=&q.data[q.head-1];
            k.step++;
            if (!visit[k.a][k.b])
                queue_En(k);
        }
        if (t.b>0 && t.a>0) {
            k=t;
            k.b=0;
            k.op=2;
            k.x=2;
            k.father=&q.data[q.head-1];
            k.step++;
            if (!visit[k.a][k.b])
                queue_En(k);
        }
        //POUR
        if (t.a>0 && t.b<B) {
            k=t;
            k.op=3;
            k.x=1;
            k.y=2;
            int w1;
            if (k.a>=B-k.b) {
                w1=B-k.b;
                k.a-=w1;
                k.b=B;
            }
            else
            {
                k.b+=k.a;
                k.a=0;
            }
            k.father=&q.data[q.head-1];
            if (!visit[k.a][k.b])k.step++;
                queue_En(k);
        }
        if (t.b>0 && t.a<A) {
            k=t;
            k.op=3;
            k.x=2;
            k.y=1;
            int w1;
            if (k.b>=A-k.a) {
                w1=A-k.a;
                k.b-=w1;
                k.a=A;
            }
            else
            {
                k.a+=k.b;
                k.b=0;
            }
            k.father=&q.data[q.head-1];
            k.step++;
            if (!visit[k.a][k.b])
                queue_En(k);
        }
    }
    
}

int main(int argc, const char * argv[]) {
    cin >> A >> B >> C;
    if (C > A && C > B) {
        cout << "impossible" << endl;
        return 0;
    }
    sum=-1;
    m=(Data*)malloc(sizeof(Data));
    n=(Data*)malloc(sizeof(Data));
    bfs();
    if (flag!=-1) {
        cout << sum << endl;
        n=m->father;
        while (n!=NULL) {
            n->next=m;
            m=n;
            n=m->father;
        }
        m=&q.data[0];
        n=m->next;
        while (m!=NULL) {
            n=m->next;
            switch (m->op) {
                case 1:
                    printf("FILL(%d)\n",m->x);
                    break;
                case 2:
                    printf("DROP(%d)\n",m->x);
                    break;
                case 3:
                    printf("POUR(%d,%d)\n",m->x,m->y);
                    break;
                default:
                    break;
            }
            m=n;
        }
    }
    if (flag==-1)
    {
        cout << "impossible" << endl;
    }
    return 0;
}
