//
//  main.cpp
//  POJ-1860-Currency Exchange
//
//  Created by 袁子涵 on 15/11/26.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  172ms   724KB

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f

using namespace std;

int N,M,S;
double V,dis[105];
typedef struct {
    int a,b;
    double R,C;
}Edge;
vector<Edge>E;
bool bellman_ford(int start)
{
    for (int i=1; i<=N; i++)
        dis[i]=0;
    dis[start]=V;
    for (int i=1; i<N; i++) {
        bool flag=0;
        for (int j=0; j<E.size(); j++) {
            int u=E[j].a;
            int v=E[j].b;
            double cost=(dis[u]-E[j].C)*E[j].R;
            if (dis[v]<cost)
            {
                dis[v]=cost;
                flag=true;
            }
        }
        if (!flag)
            return 1;
    }
    for (int j=0; j<E.size(); j++) {
        int u=E[j].a;
        int v=E[j].b;
        double cost=(dis[u]-E[j].C)*E[j].R;
        if (dis[v]<cost)
            return 0;
    }
    return 1;
}
int main(int argc, const char * argv[]) {
    Edge tmp1,tmp2;
    int a,b;
    double r1,r2,c1,c2;
    cin >> N >> M >> S >> V;
    for (int i=1; i<=M; i++) {
        cin >> a >> b >> r1 >> c1 >> r2 >> c2;
        tmp1.a=tmp2.b=a;
        tmp1.b=tmp2.a=b;
        tmp1.R=r1;  tmp2.R=r2;
        tmp1.C=c1;  tmp2.C=c2;
        E.push_back(tmp1);
        E.push_back(tmp2);
    }
    if (bellman_ford(S)==0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
