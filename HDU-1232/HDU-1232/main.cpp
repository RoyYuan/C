//
//  main.cpp
//  HDU-1232
//
//  Created by 袁子涵 on 16/1/18.
//  Copyright © 2016年 袁子涵. All rights reserved.
//
//  31ms    1600kb

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXNODE 1005
using namespace std;

int pre[MAXNODE],sum,num1,num2,total,tmp1,tmp2;
bool vis[MAXNODE];
void init(int num)
{
    for (int i=1; i<=num; i++)
    {
        pre[i]=i;
        vis[i]=0;
    }
}

int find(int x)
{
    int root,now=x,tmp;
    while (pre[now]!=now)
        now=pre[now];
    root=now;
    now=x;
    while (pre[now]!=now) {
        tmp=pre[now];
        pre[now]=root;
        now=tmp;
    }
    return root;
}

void join(int x,int y)
{
    int nowx=find(x),nowy=find(y);
    if (nowx!=nowy)
        pre[nowx]=nowy;
}

int main(int argc, const char * argv[]) {
    while (scanf("%d",&num1)!=EOF && num1!=0) {
        sum=0;
        scanf("%d",&num2);
        init(num1);
        for (long long int i=1; i<=num2; i++) {
            scanf("%d %d",&tmp1,&tmp2);
            join(tmp1, tmp2);
        }
        for (int i=1; i<=num1; i++)
            vis[find(i)]=1;
        for (int i=1; i<=num1; i++) {
            if (vis[i])
                sum++;
        }
        cout << sum-1 << endl;
    }
    return 0;
}
