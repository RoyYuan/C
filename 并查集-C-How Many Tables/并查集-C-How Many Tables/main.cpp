//
//  main.cpp
//  并查集-C-How Many Tables
//
//  Created by 袁子涵 on 16/1/31.
//  Copyright © 2016年 袁子涵. All rights reserved.
//
//  0ms    1784kb

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int T,n,m;
int set[1005],stk[1005];
bool vis[1005];

int find(int num)
{
    int now=num,top=0;
    while (set[now]!=now)
    {
        stk[top++]=now;
        now=set[now];
    }
    while (top)
        set[stk[--top]]=now;
    return now;
}

void join(int num1,int num2)
{
    int f1=find(num1),f2=find(num2);
    set[f1]=set[f2];
}

int main(int argc, const char * argv[]) {
    scanf("%d",&T);
    while (T--) {
        int total=0;
        scanf("%d%d",&n,&m);
        for (int i=1; i<=n; i++)
        {
            set[i]=i;
            vis[i]=0;
        }
        int a,b;
        for (int i=1; i<=m; i++) {
            scanf("%d%d",&a,&b);
            join(a, b);
        }
        for (int i=1; i<=n; i++)
            vis[find(i)]=1;
        for (int i=1; i<=n; i++) {
            if (vis[i]) {
                total++;
            }
        }
        cout << total << endl;
    }
    return 0;
}
