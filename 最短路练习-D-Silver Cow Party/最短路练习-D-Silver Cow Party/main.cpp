//
//  main.cpp
//  最短路练习-D-Silver Cow Party
//
//  Created by 袁子涵 on 15/10/10.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Max 999999999
#define maxof(a,b)  ((a)>(b)?(a):(b))
#define minof(a,b)  ((a)>(b)?(b):(a))

using namespace std;

long long int M,N,X,map[1005][1005],dis1[1005],dis2[1005],out;
bool book1[1005],book2[1005];
long long int min1,min2;

void dijkstra()
{
    int next1=0,next2=0;
    book1[X]=1;
    book2[X]=1;
    for (int i=0; i<N; i++) {
        dis1[i]=map[X][i];
        dis2[i]=map[i][X];
    }
    for (int i=0; i<N; i++) {
        min1=min2=Max;
        for (int j=0; j<N; j++) {
            if (min1>dis1[j] && book1[j]==0) {
                min1=dis1[j];
                next1=j;
            }
            if (min2>dis2[j] && book2[j]==0) {
                min2=dis2[j];
                next2=j;
            }
        }
        book1[next1]=1;
        book2[next2]=1;
        for (int j=0; j<N; j++) {
            if (dis1[next1]+map[next1][j]<dis1[j]) {
                dis1[j]=dis1[next1]+map[next1][j];
            }
            if (dis2[next2]+map[j][next2]<dis2[j]) {
                dis2[j]=dis2[next2]+map[j][next2];
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    long long int a,b,t;
    cin >> N >> M >> X;
    X--;
    memset(book1, 0, sizeof(book1));
    memset(book2, 0, sizeof(book2));
    memset(map, 0, sizeof(map));
    memset(dis1, 0, sizeof(dis1));
    memset(dis2, 0, sizeof(dis2));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            map[i][j]=Max;
        }
        map[i][i]=0;
    }
    for (long long int i=0; i<M; i++) {
        scanf("%lld%lld%lld",&a,&b,&t);
        map[a-1][b-1]=minof(map[a-1][b-1], t);
    }
    dijkstra();
    out=0;
    for (int i=0; i<N; i++) {
        out=maxof(out, dis1[i]+dis2[i]);
    }
    cout << out << endl;
    return 0;
}
