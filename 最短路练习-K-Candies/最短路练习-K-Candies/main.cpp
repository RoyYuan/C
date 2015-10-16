//
//  main.cpp
//  最短路练习-K-Candies
//
//  Created by 袁子涵 on 15/10/16.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXPT 30005
#define MAXEG 150005
#define INF 0xFFFFFFFF

using namespace std;

typedef struct edge
{
    long long int fin,wt,next;
}Edge;

Edge eg[MAXEG];
bool visit[MAXPT];
long long int N,M,dis[MAXPT],pre[MAXPT];

typedef struct stack
{
    long long int top,data[MAXPT];
}Stack;

Stack s;

void spfa()
{
    long long int now;
    s.top=0;
    memset(visit, 0, sizeof(visit));
    for (long long int i=0; i<N; i++) {
        dis[i]=INF;
    }
    dis[0]=0;
    s.data[s.top++]=0;
    visit[0]=1;
    while (s.top!=0) {
        now=s.data[--s.top];
        visit[now]=0;
        for (long long int i=pre[now]; i!=-1; i=eg[i].next) {
            if (dis[eg[i].fin]>dis[now]+eg[i].wt) {
                dis[eg[i].fin]=dis[now]+eg[i].wt;
                if (visit[eg[i].fin]==0) {
                    s.data[s.top++]=eg[i].fin;
                    visit[eg[i].fin]=1;
                }
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    long long int a,b,c;
    cin >> N >> M ;
    memset(pre, -1, sizeof(pre));
    for (long long int i=0; i<M; i++) {
        scanf("%lld%lld%lld",&a,&b,&c);
        eg[i].fin=b-1;
        eg[i].wt=c;
        eg[i].next=pre[a-1];
        pre[a-1]=i;
    }
    spfa();
    cout << dis[N-1] << endl;
    return 0;
}
