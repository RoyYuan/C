//
//  main.cpp
//  并查集-B-The Suspects
//
//  Created by 袁子涵 on 16/1/31.
//  Copyright © 2016年 袁子涵. All rights reserved.
//
//  16ms    892kb

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>

using namespace std;

int n,m,k,first;
int set[30005];
int stk[30005];

int find(int num)
{
    int tmp=0,now=num;
    while (set[now]!=now)
    {
        stk[tmp++]=now;
        now=set[now];
    }
    while (tmp)
        set[stk[--tmp]]=now;
    return now;
}

void join(int num1,int num2)
{
    int f1=find(num1),f2=find(num2);
    set[f1]=set[f2];
}

int main(int argc, const char * argv[]) {
    while (scanf("%d %d",&n,&m)&& (n!=0 || m!=0)) {
        int total=0;
        for (int i=0; i<n; i++)
            set[i]=i;
        for (int i=1; i<=m; i++) {
            int tmp;
            scanf("%d",&k);
            if (k==0) {
                continue;
            }
            scanf("%d",&first);
            for (int j=1; j<k; j++) {
                scanf("%d",&tmp);
                join(first, tmp);
            }
        }
        for (int i=0; i<n; i++) {
            if (find(i)==set[0]) {
                total++;
            }
        }
        cout << total << endl;
    }
    return 0;
}
