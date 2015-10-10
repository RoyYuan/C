//
//  main.cpp
//  简单搜索-F-Prime Path
//
//  Created by 袁子涵 on 15/8/2.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int n,m;
int a,b;
bool visit[10000];

typedef struct data
{
    int num;
    int step;
}Data;

typedef struct queue
{
    int head,tail;
    Data data[10000];
}Queue;

Queue q;

void initqueue()
{
    q.head=0;
    q.tail=0;
}

bool prime(int digit)
{
    if(digit==2 || digit==3)
        return true;
    else if(digit<=1 || digit%2==0)
        return false;
    else if(digit>3)
    {
        for(int i=3;i*i<=digit;i+=2)
            if(digit%i==0)
                return false;
    }
    return true;
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
    int t;
    int k;
    int x,y;
    initqueue();
    memset(visit, 0, sizeof(visit));
    q.data[q.tail].num=a;
    q.data[q.tail++].step=0;
    visit[a]=1;
    while (emptyqueue()) {
        t=q.data[q.head].num;
        if (t==b) {
            m=q.data[q.head].step;
        }
        x=t%10;
        y=t-x;
        for (int i=1; i<10; i+=2) {
            if (i==x) {
                continue;
            }
            k=y+i;
            if (prime(k) && visit[k]==0) {
                q.data[q.tail].num=k;
                q.data[q.tail++].step=q.data[q.head].step+1;
                visit[k]=1;
            }
        }
        if (x%2!=0) {
            x=(t%100)/10;
            y=t-x*10;
            for (int i=0; i<10; i++) {
                if (i==x) {
                    continue;
                }
                k=y+i*10;
                if (prime(k) && visit[k]==0) {
                    q.data[q.tail].num=k;
                    q.data[q.tail++].step=q.data[q.head].step+1;
                    visit[k]=1;
                }
            }
            x=(t/100)%10;
            y=t-x*100;
            for (int i=0; i<10; i++) {
                if (i==x) {
                    continue;
                }
                k=y+i*100;
                if (prime(k) && visit[k]==0) {
                    q.data[q.tail].num=k;
                    q.data[q.tail++].step=q.data[q.head].step+1;
                    visit[k]=1;
                }
            }
            x=t/1000;
            y=t%1000;
            for (int i=1; i<10; i++) {
                if (i==x) {
                    continue;
                }
                k=i*1000+y;
                if (prime(k) && visit[k]==0) {
                    q.data[q.tail].num=k;
                    q.data[q.tail++].step=q.data[q.head].step+1;
                    visit[k]=1;
                }
            }
        }
        q.head++;
    }
}

int main(int argc, const char * argv[]) {
    cin >> n;
    while (n--) {
        cin >> a >> b;
        bfs();
        cout << m << endl;
    }
    return 0;
}
