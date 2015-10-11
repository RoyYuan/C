//
//  main.cpp
//  最短路练习-E-Currency Exchange
//
//  Created by 袁子涵 on 15/10/10.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct edge
{
    int A,B;
    double r,c;
}Edge;

int N,M,S,sum;
double V,dis[105];
Edge edge[205];

bool Bellman_ford()
{
    bool flag=0;
    memset(dis, 0, sizeof(dis));
    dis[S]=V;
    for (int i=0; i<N; i++) {
        flag=0;
        for (int j=0; j<sum; j++) {
            if (dis[edge[j].B]<(dis[edge[j].A]-edge[j].c)*edge[j].r) {
                dis[edge[j].B]=(dis[edge[j].A]-edge[j].c)*edge[j].r;
                flag=true;
            }
        }
        if (!flag) {
            break;
        }
    }
    for (int i=0; i<sum; i++) {
        if (dis[edge[i].B]<(dis[edge[i].A]-edge[i].c)*edge[i].r) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    int a,b;
    double ra,rb,ca,cb;
    cin >> N >> M >> S >> V;
    sum=0;
    for (int i=0; i<M; i++) {
        cin >> a >> b >> rb >> cb >> ra >> ca;
        edge[sum].A=a;
        edge[sum].B=b;
        edge[sum].c=cb;
        edge[sum++].r=rb;
        edge[sum].A=b;
        edge[sum].B=a;
        edge[sum].c=ca;
        edge[sum++].r=ra;
    }
    if (Bellman_ford()) {
        cout << "NO" << endl;
    }
    else
        cout << "YES" << endl;
    return 0;
}
