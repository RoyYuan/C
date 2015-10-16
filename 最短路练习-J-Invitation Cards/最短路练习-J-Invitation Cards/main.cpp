//
//  main.cpp
//  最短路练习-J-Invitation Cards
//
//  Created by 袁子涵 on 15/10/16.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue>

#define minof(a,b)  ((a)>(b)?(b):(a))
#define INF 0xFFFFFFFF
#define MAXIN 1000005

using namespace std;

typedef struct edge
{
    long long int fin,wt,next;
}Edge;


queue<long long int>Stl;

Edge eg[2][MAXIN];
long long int pre[2][MAXIN];
long long dis[2][MAXIN];
long long int N,P,Q,sum=0;
bool visit[MAXIN];

void spfa(int num)
{
    for (long long int i=1; i<=P; i++) {
        dis[num][i]=INF;
    }
    dis[num][0]=0;
    long long int now;
    memset(visit, 0, sizeof(visit));
    Stl.push(0);
    visit[0]=1;
    while(!Stl.empty())
    {
        now=Stl.front();
        Stl.pop();
        visit[now]=0;
        for (long long int i=pre[num][now]; i!=-1; i=eg[num][i].next) {
            if (dis[num][eg[num][i].fin]>=eg[num][i].wt+dis[num][now]) {
                dis[num][eg[num][i].fin]=eg[num][i].wt+dis[num][now];
                if (visit[eg[num][i].fin]==0) {
                    Stl.push(eg[num][i].fin);
                    visit[eg[num][i].fin]=1;
                }
            }
        }
    }
    
    
}


int main(int argc, const char * argv[]) {
    long long int come,fin ,weight;
    scanf("%lld",&N);
    while (N--) {
        sum=0;
        memset(pre, -1, sizeof(pre));
        memset(dis, 0, sizeof(dis));
        scanf("%lld%lld",&P,&Q);
        for (long long int i=0; i<Q; i++) {
            scanf("%lld%lld%lld",&come,&fin,&weight);
            eg[0][i].fin=fin-1;
            eg[0][i].wt=weight;
            eg[0][i].next=pre[0][come-1];
            pre[0][come-1]=i;
            eg[1][i].fin=come-1;
            eg[1][i].wt=weight;
            eg[1][i].next=pre[1][fin-1];
            pre[1][fin-1]=i;
        }
        spfa(0);
        spfa(1);
        for (long long int i=0; i<P; i++) {
            sum+=dis[0][i];
            sum+=dis[1][i];
        }
        printf("%lld\n",sum);
    }
    return 0;
}
