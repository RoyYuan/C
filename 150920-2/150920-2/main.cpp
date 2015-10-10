//
//  main.cpp
//  150920-2
//
//  Created by 袁子涵 on 15/9/20.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int T;
int M,N;
bool flag=1;
typedef struct coor
{
    double x,y;
}Coor;
Coor pt[105];
double dis[105][105];
int r[105];

double distance(Coor a,Coor b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int cmp( const void *a , const void *b )
{
    return *(double *)a > *(double *)b ? 1 : -1;
}

int comp ( const void *a , const void *b )
{
    return *(int *)a - *(int *)b;
}

int main(int argc, const char * argv[]) {
    scanf("%d",&T);
    int x;
    while (T--) {
        flag=1;
        scanf("%d%d",&M,&N);
        memset(dis, 0, sizeof(dis));
        for (int i=0; i<M; i++) {
            scanf("%lf%lf",&pt[i].x,&pt[i].y);
        }
        if (N>M) {
            printf("-1\n");
            continue;
        }
        for (int i=0; i<M; i++) {
            for (int j=i+1; j<M; j++) {
                dis[i][j]=distance(pt[i], pt[j]);
                dis[j][i]=dis[i][j];
            }
        }
        memset(r, -1, sizeof(r));
        for (int i=0; i<M; i++) {
            qsort(dis[i], M, sizeof(dis[0][0]), cmp);
            r[i]=0;
            r[i]=ceil(dis[i][N-1]);
            if (dis[i][N-1]-ceil(dis[i][N-1])==0) {
                r[i]++;
            }
            if (dis[i][N]<=r[i] && N<M) {
                r[i]=-1;
            }
        }
        qsort(r, M, sizeof(int), comp);
        x=0;
        while (r[x]==-1 && x<M) {
            x++;
        }
        printf("%d\n",r[x]);
    }
    return 0;
}
