//
//  main.cpp
//  简单搜索-N-Find a Way
//
//  Created by 袁子涵 on 15/8/17.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define minof(a,b) ((a)>(b)?(b):(a))
using namespace std;

typedef struct dt
{
    int x,y;
    long int step;
}Data;

typedef struct queue
{
    long int head,tail;
    Data data[50000];
}Queue;

Queue q;

int n,m;
char map[210][210];
bool visit1[210][210];
bool visit2[210][210];
long int step1[210][210];
long int step2[210][210];
int dir[2][4]={-1,1,0,0,0,0,-1,1};
unsigned long long int sum;

void bfs(int i,int j,bool visit[210][210],long int step[210][210])
{
    q.head=0;
    q.tail=0;
    dt t,k;
    t.x=i;
    t.y=j;
    t.step=0;
    q.data[q.tail++]=t;
    while (q.head!=q.tail) {
        t=q.data[q.head++];
        for (int i=0; i<4; i++) {
            k=t;
            k.x+=dir[0][i];
            k.y+=dir[1][i];
            k.step++;
            if (k.x>=0 && k.x<n && k.y>=0 && k.y<m && visit[k.x][k.y]==0 && map[k.x][k.y]!='#') {
                step[k.x][k.y]=k.step;
                visit[k.x][k.y]=1;
                q.data[q.tail++]=k;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    while (scanf("%d%d",&n,&m)!=EOF) {
        memset(map, 0, sizeof(map));
        memset(visit1, 0, sizeof(visit1));
        memset(visit2, 0, sizeof(visit2));
        memset(step1, 0, sizeof(step1));
        memset(step2, 0, sizeof(step2));
        sum=40000;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> map[i][j];
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m ; j++) {
                if (map[i][j]=='Y') {
                    visit1[i][j]=1;
                    step1[i][j]=0;
                    bfs(i,j,visit1,step1);
                }
                if (map[i][j]=='M') {
                    visit2[i][j]=1;
                    step2[i][j]=0;
                    bfs(i,j,visit2,step2);
                }
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (map[i][j]=='@' && visit1[i][j] && visit2[i][j]) {
                    sum=minof(step1[i][j]+step2[i][j],sum);
                }
            }
        }
        sum*=11;
        cout << sum << endl;
    }
    return 0;
}
