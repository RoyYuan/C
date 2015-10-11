//
//  main.cpp
//  最短路练习-F-Wormholes
//
//  Created by 袁子涵 on 15/10/11.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define INF 999999999

using namespace std;

typedef struct edge
{
    int S,E;
    long long int T;
}Edge;

int F,N,M,W;
Edge eg[10000];
long long int sum=0,dis[1000];

bool bellman_ford()
{
    bool flag=0;
    for (int i=1; i<N; i++) {
        dis[i]=INF;
    }
    dis[0]=0;
    for (int i=0; i<N; i++) {
        flag=0;
        for (int j=0; j<sum; j++) {
            if (dis[eg[j].E]>dis[eg[j].S]+eg[j].T && dis[eg[j].S]<INF) {
                dis[eg[j].E]=dis[eg[j].S]+eg[j].T;
                flag=1;
            }
        }
        if (flag==0) {
            break;
        }
    }
    for (int i=0; i<sum; i++) {
        if (dis[eg[i].E]>dis[eg[i].S]+eg[i].T && dis[eg[i].S]<INF) {
            dis[eg[i].E]=dis[eg[i].S]+eg[i].T;
            return 1;
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    cin >> F;
    int s,e,t;
    while (F--) {
        cin >> N >> M >> W;
        sum=0;
        for (int i=0; i<M; i++) {
            cin >> s >> e >> t;
            eg[sum].S=s-1;
            eg[sum].E=e-1;
            eg[sum++].T=t;
            eg[sum].S=e-1;
            eg[sum].E=s-1;
            eg[sum++].T=t;
        }
        for (int i=0; i<W; i++) {
            cin >> s >> e >> t;
            eg[sum].S=s-1;
            eg[sum].E=e-1;
            eg[sum++].T=-t;
        }
        if (bellman_ford()) {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
        
    }
    return 0;
}
