//
//  main.cpp
//  POJ-3268-Silver Cow Party
//
//  Created by 袁子涵 on 15/11/26.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  63ms    8612KB

#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#define MAXN 1005
#define INF 0x7fffffff
using namespace std;
long long int N,M,X,go[MAXN],back[MAXN];
long long int cost[MAXN][MAXN];
bool vis1[MAXN],vis2[MAXN];

void Dijkstra(long long int beg)
{
    for (int i=1; i<=N; i++) {
        go[i]=back[i]=INF;
        vis1[i]=vis2[i]=0;
    }
    go[beg]=back[beg]=0;
    for (int j=1; j<=N; j++) {
        long long int k1=-1,k2=-1;
        long long int min1=INF,min2=INF;
        for (int i=1; i<=N; i++) {
            if (!vis1[i] && go[i]<min1) {
                min1=go[i];
                k1=i;
            }
            if (!vis2[i] && back[i]<min2) {
                min2=back[i];
                k2=i;
            }
        }
        if (k1==-1 && k2==-1)
            break;
        vis1[k1]=vis2[k2]=1;
        for (int i=1; i<=N; i++) {
            if (!vis1[i] && go[k1]+cost[k1][i]<go[i])
                go[i]=go[k1]+cost[k1][i];
            if (!vis2[i] && back[k2]+cost[i][k2]<back[i])
                back[i]=back[k2]+cost[i][k2];
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> N >> M >> X;
    long long int a,b,c,out=0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (i==j)
                cost[i][j]=0;
            else
                cost[i][j]=INF;
        }
    }
    for (long long int i=1; i<=M; i++) {
        scanf("%lld %lld %lld",&a,&b,&c);
        cost[a][b]=c;
    }
    Dijkstra(X);
    for (int i=1; i<=N; i++)
        out=max(go[i]+back[i],out);
    cout << out << endl;
    return 0;
}
