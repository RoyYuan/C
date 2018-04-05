//
//  main.cpp
//  并查集-A-Wireless Network
//
//  Created by 袁子涵 on 16/1/18.
//  Copyright © 2016年 袁子涵. All rights reserved.
//
//  3313ms  4792kb

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXN 1005

struct Nd{
    int x,y;
};

using namespace std;

vector<int>dis[MAXN];
Nd nd[MAXN];
int N,d,num1,num2;
bool vis[MAXN];
int pre[MAXN];

double distc(Nd a,Nd b)
{
    double dist;
    dist=sqrt((double)((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
    return dist;
}

int find(int num)
{
    int root,now=num,tmp;
    while (pre[now]!=now)
        now=pre[now];
    root=now;
    now=num;
    while (pre[now]!=now) {
        tmp=pre[now];
        pre[now]=root;
        now=tmp;
    }
    return root;
}

void join(int a,int b)
{
    int ra=find(a),rb=find(b);
    if (ra!=rb)
        pre[ra]=rb;
}

int main(int argc, const char * argv[]) {
    scanf("%d%d",&N,&d);
    memset(nd, 0, sizeof(Nd));
    memset(vis, 0, sizeof(vis));
    for (int i=1; i<=N; i++)
    {
        scanf("%d%d",&nd[i].x,&nd[i].y);
        pre[i]=i;
    }
    for (int i=1; i<=N; i++)
        for (int j=i+1; j<=N; j++) {
            double dist=distc(nd[i], nd[j]);
            if (dist<=(double)d) {
                dis[i].push_back(j);
                dis[j].push_back(i);
            }
        }
    char op;
    while (scanf("%c",&op)!=EOF) {
        if (op=='O') {
            scanf("%d",&num1);
            vis[num1]=1;
            for (int i=0; i<dis[num1].size(); i++) {
                if (vis[dis[num1][i]]) {
                    join(dis[num1][i], num1);
                }
            }
        }
        else if(op=='S')
        {
            scanf("%d%d",&num1,&num2);
            if (find(num1)==find(num2))
                printf("SUCCESS\n");
            else
                printf("FAIL\n");
        }
    }
    return 0;
}
