//
//  main.cpp
//  最短路练习-N-Tram
//
//  Created by 袁子涵 on 15/10/18.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXIN 105
#define INF 0xffff
#define minof(a,b)  ((a)>(b)?(b):(a))

using namespace std;

int N,A,B;
bool visit[MAXIN];
int dis[MAXIN],map[MAXIN][MAXIN];

void dijkstra(int num)
{
    for (int i=1; i<=N; i++) {
        dis[i]=map[num][i];
    }
    visit[num]=1;
    for (int i=1; i<=N; i++) {
        int mins=INF,next=-1;
        for (int j=1; j<=N; j++) {
            if (visit[j]==0 && mins>dis[j]) {
                mins=dis[j];
                next=j;
            }
        }
        if (next==-1) {
            break;
        }
        visit[next]=1;
        for (int j=1; j<=N; j++) {
            if (visit[j]==0 && dis[j]>dis[next]+map[next][j]) {
                dis[j]=dis[next]+map[next][j];
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int s,p;
    cin >> N >> A >> B;
    memset(visit, 0, sizeof(visit));
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            map[i][j]=INF;
        }
        map[i][i]=0;
    }
    for (int i=1; i<=N; i++) {
        cin >> s;
        for (int j=0; j<s; j++) {
            cin >> p;
            if (j==0) {
                map[i][p]=0;
            }
            else
                map[i][p]=minof(map[i][p],1);
        }
    }
    dijkstra(A);
    if (dis[B]!=INF) {
        cout << dis[B] << endl;
    }
    else
        cout << "-1" << endl;
    return 0;
}
