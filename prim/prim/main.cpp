//
//  main.cpp
//  prim
//
//  Created by 袁子涵 on 15/11/30.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#define MAXN 505
#define INF 0x3f3f3f3f
using namespace std;

long long int dist[MAXN][MAXN];

int main()
{
    int n,m;
    int a,b,c;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            if(i==j)
                dist[i][j]=0;
            else
                dist[i][j]=dist[j][i]=INF;
        }
    for(int i=1;i<=m;i++)
    {
        cin >> a >> b >> c;
        dist[a][b]=dist[b][a]=c;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
                continue;
            printf("%d->%d:%lld\t",i,j,dist[i][j]);
        }
        printf("\n");
    }
    return 0;
}

