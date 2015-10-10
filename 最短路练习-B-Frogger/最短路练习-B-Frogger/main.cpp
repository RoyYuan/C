//
//  main.cpp
//  最短路练习-B-Frogger
//
//  Created by 袁子涵 on 15/10/1.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#define pow(x) (x*x)
using namespace std;

typedef struct coor
{
    int x,y;
}Coor;

double cal(Coor a,Coor b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int N;
bool visit[210];
double dis[210][210],length[210],maxs=8000000;
Coor stone[210];
double out=0;
int main(int argc, const char * argv[]) {
    double Min=maxs;
    int next=1,num=0;
    while (cin >> N && N != 0) {
        out=0.0;
        memset(visit, 0, sizeof(visit));
        memset(dis, 0, sizeof(dis));
        memset(length, 0, sizeof(length));
        memset(stone, 0, sizeof(stone));
        for (int i=1; i<=N; i++) {
            cin >> stone[i].x >> stone[i].y;
        }
        for (int i=1; i<=N; i++) {
            for (int j=i; j<=N; j++) {
                dis[i][j]=cal(stone[i], stone[j]);
                dis[j][i]=dis[i][j];
            }
        }
        visit[1]=1;
        for (int i=1; i<=N; i++) {
            length[i]=dis[1][i];
        }
        while (visit[2]==0) {
            Min=maxs;
            for (int i=1; i<=N; i++) {
                if (length[i]<=Min && visit[i]==0) {
                    Min=length[i];
                    next=i;
                }
            }
            visit[next]=1;
            for (int i=1; i<=N; i++) {
                if (length[i]>dis[next][i]) {
                    length[i]=dis[next][i];
                }
            }
            if (out < Min) {
                out=Min;
            }
        }
        num++;
        printf("Scenario #%d\n",num);
        printf("Frog Distance = %.3f\n\n",out);
        getchar();
    }
    return 0;
}
