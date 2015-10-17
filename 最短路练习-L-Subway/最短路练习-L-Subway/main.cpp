//
//  main.cpp
//  最短路练习-L-Subway
//
//  Created by 袁子涵 on 15/10/17.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cmath>

#define Maxin 205
#define INF 0xFFFFFFFF
#define minof(a,b)  ((a)>(b)?(b):(a))

using namespace std;

typedef struct coor
{
    long long int x,y;
}Coor;

Coor start,fin,node[Maxin];
double dis[Maxin],map[Maxin][Maxin];
bool visit[Maxin];
int n=2;
double v1=40000.0/60,v2=10000.0/60;

double distances(Coor a,Coor b)
{
    return sqrt((double)(a.x-b.x)*(a.x-b.x)+(double)(a.y-b.y)*(a.y-b.y));
}

void dijkstra()
{
    double mins;
    int next=-1;
    for (int i=0; i<n; i++) {
        dis[i]=map[0][i];
    }
    visit[0]=1;
    for (int i=0; i<n; i++) {
        mins=INF;
        for (int j=0; j<n; j++) {
            if (visit[j]==0 && mins>dis[j]) {
                mins=dis[j];
                next=j;
            }
        }
        if (next==-1) {
            break;
        }
        visit[next]=1;
        for (int j=0; j<n; j++) {
            if (dis[j]>map[next][j]+dis[next] && visit[j]==0) {
                dis[j]=map[next][j]+dis[next];
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    long long int x,y;
    bool flag=0;
    cin >> start.x >> start.y >> fin.x >> fin.y;
    node[0]=start;
    node[1]=fin;
    memset(visit, 0, sizeof(visit));
    memset(map, 0, sizeof(map));
    for (int i=0; i<Maxin; i++) {
        for (int j=0; j<Maxin; j++) {
            map[i][j]=INF;
        }
        dis[i]=INF;
        map[i][i]=0;
    }
    dis[0]=0;
    visit[0]=1;
    while (scanf("%lld%lld",&x,&y)==2) {
        if (x==-1 && y==-1) {
            flag=0;
            continue;
        }
        node[n].x=x;
        node[n].y=y;
        if (flag==1) {
            map[n][n-1]=map[n-1][n]=minof(distances(node[n], node[n-1])/v1,map[n][n-1]);
        }
        flag=1;
        n++;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            map[i][j]=map[j][i]=minof(distances(node[i], node[j])/v2, map[i][j]);
        }
    }
    dijkstra();
    printf("%.0lf\n",dis[1]);
    return 0;
}
