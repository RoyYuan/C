//
//  main.cpp
//  最短路练习-M-昂贵的聘礼
//
//  Created by 袁子涵 on 15/10/18.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define maxof(a,b)  ((a)>(b)?(a):(b))
#define minof(a,b)  ((a)>(b)?(b):(a))
#define INF 0xFFFFFFF
#define MAXIN 105

using namespace std;

long long int N,map[MAXIN][MAXIN],dis[MAXIN],mins,out=INF;
bool visit[MAXIN];
int lv[MAXIN],M;

long long int dijkstra()
{
    for (int i=0; i<=N; i++) {
        if (visit[i]==0) {
            dis[i]=map[0][i];
        }
        else
            dis[i]=INF;
    }
    visit[0]=1;
    for (int i=0; i<=N; i++) {
        long long int min=INF;
        int next=-1;
        for (int j=0; j<=N; j++) {
            if (visit[j]==0 && min>dis[j]) {
                min=dis[j];
                next=j;
            }
        }
        if (next==-1) {
            break;
        }
        visit[next]=1;
        for (int j=0; j<=N; j++) {
            if (visit[j]==0 && dis[j]>dis[next]+map[next][j]) {
                dis[j]=dis[next]+map[next][j];
            }
        }
    }
    return dis[1];
}

int main(int argc, const char * argv[]) {
    int t,s,lvmax;
    long long int p;
    cin >> M >> N;
    memset(visit, 0, sizeof(visit));
    for (int i=0; i<=N; i++) {
        for (int j=0; j<=N; j++) {
            map[i][j]=INF;
        }
        map[i][i]=0;
    }
    for (int i=1; i<=N; i++) {
        scanf("%lld %d %d",&map[0][i],&lv[i],&t);
        while (t--) {
            scanf("%d %lld",&s,&p);
            map[s][i]=minof(p,map[i][s]);
        }
    }
    for (int i=1; i<=N; i++) {
        memset(visit, 0, sizeof(visit));
        lvmax=lv[i]+M;
        for (int j=1; j<=N; j++) {
            if (lv[j]>lvmax || lv[j]<lv[i]) {
                visit[j]=1;
            }
        }
        mins=dijkstra();
        out=minof(out,mins);
    }
    cout << out << endl;
    return 0;
}
