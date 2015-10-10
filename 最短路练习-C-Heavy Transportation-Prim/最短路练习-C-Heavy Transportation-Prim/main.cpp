//
//  main.cpp
//  最短路练习-C-Heavy Transportation-Prim
//
//  Created by 袁子涵 on 15/10/9.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define minof(a,b)  ((a)>(b)?(b):(a))
#define N  999999999

using namespace std;

int n,t;
long long int m,map[1005][1005],dis[1005],Max,out=N;
bool book[1005];

void prim()
{
    int next=0;
    book[0]=1;
    for (int i=0; i<n; i++) {
        dis[i]=map[0][i];
    }
    while (book[n-1]==0) {
        Max=0;
        for (int i=0; i<n; i++) {
            if (Max<=dis[i] && book[i]==0) {
                Max=dis[i];
                next=i;
            }
        }
        book[next]=1;
        out=minof(out,Max);
        for (int i=0; i<n; i++) {
            if (dis[i]<map[next][i]) {
                dis[i]=map[next][i];
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    scanf("%d",&t);
    int k=t,a,b;
    long long int c;
    while (k--) {
        out=N;
        memset(book, 0, sizeof(book));
        memset(map, 0, sizeof(map));
        scanf("%d%lld",&n,&m);
        for (int i=0; i<m; i++) {
            scanf("%d%d%lld",&a,&b,&c);
            map[a-1][b-1]=c;
            map[b-1][a-1]=c;
        }
        prim();
        printf("Scenario #%d:\n",t-k);
        printf("%lld\n\n",out);
    }
    return 0;
}
