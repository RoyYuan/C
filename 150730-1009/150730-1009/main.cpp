//
//  main.cpp
//  150730-1009
//
//  Created by 袁子涵 on 15/7/30.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

unsigned long int sum;
unsigned long int s[1000];
int T;
int n,m;
bool map[1010][1010];
bool out[1000][1000010];

typedef struct data
{
    int x,y;
    bool num[1000010];
    unsigned long int sum=0;
    bool flag=0;
}Data;

typedef struct queue
{
    unsigned long int head,tail;
    Data data[1000010];
}Queue;

Queue q;

//初始化
void initqueue()
{
    q.head=0;
    q.tail=0;
}

//判断空队列
int queueempty()
{
    if (q.head==q.tail) {
        return 0;
    }
    return 1;
}

void Enqueue(int x,int y,bool t[1010][1010],bool k[1000010])
{
    q.data[q.tail].x=x;
    q.data[q.tail].y=y;
    memcpy(q.data[q.tail].visit,t,sizeof(q.data[q.tail].visit));
    memcpy(q.data[q.tail].num, k, sizeof(q.data[q.tail].num));
    q.data[q.tail].num[q.data[q.tail].sum++]=map[x][y];
    if (q.data[q.tail].flag==0) {
        if (map[x][y]) {
            q.data[q.tail].flag=1;
        }
    }
    q.tail++;
    
}


void bfs()
{
    Data t;
    memset(t.num, 0, sizeof(t.num));
    memset(t.visit, 0, sizeof(t.visit));
    memset(out, 0, sizeof(out));
    initqueue();
    sum=0;
    t.num[0]=map[0][0];
    t.visit[0][0]=1;
    Enqueue(0, 0, t.visit,t.num);
    while (queueempty()) {
        memcpy(t.visit, q.data[q.head].visit, sizeof(q.data[q.head].visit));
        memcpy(t.num, q.data[q.head].num, sizeof(q.data[q.head].num));
        t.x=q.data[q.head].x;
        t.y=q.data[q.head].y;
        t.flag=q.data[q.head].flag;
        if (t.x==n && t.y==m) {
            memcpy(out[sum], t.num, sizeof(t.num));
            s[sum]=t.sum;
            sum++;
            
        }
        if (t.flag) {
            if (t.x<n-1 && t.visit[t.x+1][t.y]==0) {
                t.visit[t.x+1][t.y]=1;
                t.num[++t.sum]=map[t.x+1][t.y];
                Enqueue(t.x+1, t.y, t.visit, t.num);
                t.visit[t.x+1][t.y]=0;
                t.num[t.sum--]=0;
            }
            if (t.y<m-1 && t.visit[t.x][t.y+1]==0) {
                t.visit[t.x][t.y+1]=1;
                t.num[++t.sum]=map[t.x][t.y+1];
                Enqueue(t.x, t.y+1, t.visit, t.num);
                t.visit[t.x][t.y+1]=0;
                t.num[t.sum--]=0;
            }
        }
        else
        {
            if (t.x<n-1 && t.visit[t.x+1][t.y]==0) {
                t.visit[t.x+1][t.y]=1;
                t.num[++t.sum]=map[t.x+1][t.y];
                Enqueue(t.x+1, t.y, t.visit, t.num);
                t.visit[t.x+1][t.y]=0;
                t.num[t.sum--]=0;
            }
            if (t.y<m-1 && t.visit[t.x][t.y+1]==0) {
                t.visit[t.x][t.y+1]=1;
                t.num[++t.sum]=map[t.x][t.y+1];
                Enqueue(t.x, t.y+1, t.visit, t.num);
                t.visit[t.x][t.y+1]=0;
                t.num[t.sum--]=0;
            }
            if (t.x>0 && t.visit[t.x-1][t.y]==0) {
                t.visit[t.x-1][t.y]=1;
                t.num[++t.sum]=map[t.x-1][t.y];
                Enqueue(t.x-1, t.y, t.visit, t.num);
                t.visit[t.x-1][t.y]=0;
                t.num[t.sum--]=0;
            }
            if (t.y>0 && t.visit[t.x][t.y-1]==0) {
                t.visit[t.x][t.y-1]=1;
                t.num[++t.sum]=map[t.x][t.y-1];
                Enqueue(t.x, t.y-1, t.visit, t.num);
                t.visit[t.x][t.y-1]=0;
                t.num[t.sum--]=0;
            }
        }
        
    }
    
}

int main(int argc, const char * argv[]) {
    cin >> T;
    char k[1010];
    while (T--) {
        cin >> n >> m;
        for (int i=0; i<n; i++) {
            memset(k, 0, sizeof(k));
            scanf("%s",k);
            for (int j=0; j<m; j++) {
                map[i][j]=k[j];
            }
        }
        bfs();
        for (int i=0; i<sum; i++) {
            for (unsigned long int j=0; j<s[i]; j++) {
                cout << out[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
