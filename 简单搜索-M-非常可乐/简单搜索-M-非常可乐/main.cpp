//
//  main.cpp
//  简单搜索-M-非常可乐
//
//  Created by 袁子涵 on 15/8/17.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int s,m,n;
bool visit[105][105][105];
unsigned long long int sum,aim;

typedef struct dt
{
    int s,m,n;
    unsigned long long int times;
}Data;

typedef struct queue
{
    unsigned long long int head,tail;
    Data data[1000000];
}Queue;

Queue q;

void bfs()
{
    q.head=0;
    q.tail=0;
    dt t,k;
    t.s=s;
    t.m=0;
    t.n=0;
    t.times=0;
    q.data[q.tail++]=t;
    while (q.head!=q.tail) {
        t=q.data[q.head++];
        if ((t.s==aim && t.m==aim) || (t.s==aim && t.n==aim) || (t.m==aim && t.n==aim)) {
            sum=t.times;
            return;
        }
        //6种状况
        //s->m
        if (t.s!=0 && t.m<m) {
            k=t;
            //尽
            if (m-t.m>=t.s) {
                k.m+=k.s;
                k.s=0;
                k.times++;
                if (visit[k.s][k.m][k.n]==0) {
                    visit[k.s][k.m][k.n]=1;
                    q.data[q.tail++]=k;
                }
            }
            //不尽
            else
            {
                k.s=k.s-(m-k.m);
                k.m=m;
                k.times++;
                if (visit[k.s][k.m][k.n]==0) {
                    visit[k.s][k.m][k.n]=1;
                    q.data[q.tail++]=k;
                }
            }
        }
        //s->n
        if (t.s!=0 && t.n<n) {
            k=t;
            //尽
            if (n-t.n>=t.s) {
                k.n+=k.s;
                k.s=0;
                k.times++;
                if (visit[k.s][k.m][k.n]==0) {
                    visit[k.s][k.m][k.n]=1;
                    q.data[q.tail++]=k;
                }
            }
            //不尽
            else
            {
                k.s=k.s-(n-k.n);
                k.n=n;
                k.times++;
                if (visit[k.s][k.m][k.n]==0) {
                    visit[k.s][k.m][k.n]=1;
                    q.data[q.tail++]=k;
                }
            }
        }
        //m->n
        if (t.m!=0 && t.n<n) {
            k=t;
            //尽
            if (n-t.n>=t.m) {
                k.n+=k.m;
                k.m=0;
                k.times++;
                if (visit[k.s][k.m][k.n]==0) {
                    visit[k.s][k.m][k.n]=1;
                    q.data[q.tail++]=k;
                }
            }
            //不尽
            else
            {
                k.m=k.m-(n-k.n);
                k.n=n;
                k.times++;
                if (visit[k.s][k.m][k.n]==0) {
                    visit[k.s][k.m][k.n]=1;
                    q.data[q.tail++]=k;
                }
            }
        }
        //m->s
        if (t.m!=0 && t.s<s) {
            k=t;
            //尽
            if (s-t.s>=t.m) {
                k.s+=k.m;
                k.m=0;
                k.times++;
                if (visit[k.s][k.m][k.n]==0) {
                    visit[k.s][k.m][k.n]=1;
                    q.data[q.tail++]=k;
                }
            }
            //不尽
            else
            {
                k.m=k.m-(s-k.s);
                k.s=s;
                k.times++;
                if (visit[k.s][k.m][k.n]==0) {
                    visit[k.s][k.m][k.n]=1;
                    q.data[q.tail++]=k;
                }
            }
        }
        //n->s
        if (t.n!=0 && t.s<s) {
            k=t;
            //尽
            if (s-t.s>=t.n) {
                k.s+=k.n;
                k.n=0;
                k.times++;
                if (visit[k.s][k.m][k.n]==0) {
                    visit[k.s][k.m][k.n]=1;
                    q.data[q.tail++]=k;
                }
            }
            //不尽
            else
            {
                k.n=k.n-(s-k.s);
                k.s=s;
                k.times++;
                if (visit[k.s][k.m][k.n]==0) {
                    visit[k.s][k.m][k.n]=1;
                    q.data[q.tail++]=k;
                }
            }
        }
        //n->m
        if (t.n!=0 && t.m<m) {
            k=t;
            //尽
            if (m-t.m>=t.n) {
                k.m+=k.n;
                k.n=0;
                k.times++;
                if (visit[k.s][k.m][k.n]==0) {
                    visit[k.s][k.m][k.n]=1;
                    q.data[q.tail++]=k;
                }
            }
            //不尽
            else
            {
                k.n=k.n-(m-k.m);
                k.m=m;
                k.times++;
                if (visit[k.s][k.m][k.n]==0) {
                    visit[k.s][k.m][k.n]=1;
                    q.data[q.tail++]=k;
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    while (1) {
        cin >> s >> m >> n;
        if (s==0) {
            return 0;
        }
        memset(visit, 0, sizeof(visit));
        sum=0;
        if (s%2) {
            cout << "NO" << endl;
            continue;
        }
        else
            aim=s/2;
        bfs();
        if (sum) {
            cout << sum << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
