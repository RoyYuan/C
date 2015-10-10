//
//  main.cpp
//  最短路练习-C-Heavy Transportation
//
//  Created by 袁子涵 on 15/10/9.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define maxof(a,b)  ((a)>(b)?(a):(b))
#define minof(a,b)  ((a)>(b)?(b):(a))

using namespace std;

int t,n;
long long int m,map[1005][1005],dis[1005],Max,out;
bool book[1005];

void dijkstra()
{
    int next=0;
    book[0]=1;
    for (int i=0; i<n; i++) {
        dis[i]=map[0][i];
    }
    for (int i=0; i<n; i++) {
        Max=0;
        for (int j=0; j<n; j++) {
            if (dis[j]>=Max && book[j]==0) {
                Max=dis[j];
                next=j;
            }
        }
        book[next]=1;
        for (int j=0; j<n; j++) {
            if (dis[j]<minof(map[next][j], dis[next])) {
                dis[j]=minof(map[next][j], dis[next]);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    scanf("%d",&t);
    int a,b;
    long long int c;
    int k=t;
    while (k--) {
        scanf("%d%lld",&n,&m);
        memset(map, 0, sizeof(map));
        memset(book, 0, sizeof(book));
        memset(dis, 0, sizeof(dis));
        for (int i=0; i<m; i++) {
            scanf("%d%d%lld",&a,&b,&c);
            map[a-1][b-1]=c;
            map[b-1][a-1]=c;
        }
        dijkstra();
        printf("Scenario #%d:\n",t-k);
        printf("%lld\n\n",dis[n-1]);
    }
    return 0;
}
