//
//  main.cpp
//  最短路练习-A-Til The Cows Come Home
//
//  Created by 袁子涵 on 15/9/30.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define Max 10000001
#define minof(a,b) ((a)>(b)?(b):(a))

using namespace std;

bool book[1010];
int T,N;
long long int dis[1010][1010],length[1010],mins;

int main(int argc, const char * argv[]) {
    long long int a,b,c,d=0;
    cin >> T >> N;
    memset(book, 0, sizeof(book));
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++)
            dis[i][j]=Max;
        dis[i][i]=Max;
    }
    for (int i=1; i<=T; i++) {
        cin >> a >> b >> c;
        dis[a][b]=dis[b][a]=minof(dis[a][b],c);
    }
    for (int i=1; i<=N; i++)
        length[i]=dis[i][N];
    book[N]=1;
    for (int i=1; i<=N; i++) {
        mins=Max;
        for (int j=1; j<=N; j++)
            if (book[j]==0 && length[j]<mins) {
                d=j;
                mins=length[j];
            }
        book[d]=1;
        for (int j=1; j<=N; j++)
            if (book[j]==0 && length[j]>mins + dis[d][j])
                length[j]=mins + dis[d][j];
    }
    cout << length[1] << endl;
    return 0;
}
