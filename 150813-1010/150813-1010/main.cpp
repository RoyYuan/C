//
//  main.cpp
//  150813-1010
//
//  Created by 袁子涵 on 15/8/13.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int T;
unsigned long int n;
unsigned long int t[10];
unsigned long int m[10][2];
unsigned long int g[10];
unsigned long long int sum=0,sumt=1;
unsigned long long int x1,x2;
int a,b;

void success()
{
    sumt=1;
    x1=0;
    x2=0;
    for (int i=1; i<10; i++) {
        x1+=m[i][0]*i;
    }
    if ((x1-1)%9+1!=a && x1!=0) {
        return;
    }
    for (int i=1; i<10; i++) {
        x2+=m[i][1]*i;
    }
    if ((x2-1)%9+1!=b && x2!=0) {
        return;
    }
    for (int i=1; i<10; i++) {
        if (g[i]!=0) {
            sumt*=g[i];
        }
    }
    sum+=sumt;
    sum=sum%258280327;
    return;
}

unsigned long long int  c(unsigned long int n,unsigned long int k)
{
    unsigned long int i = 1;
    unsigned long int temp1 = 1,temp2 =1;
    if (n==k)
    {
        return 1;
    }
    else
    {
        for (i=1;i<=k;i++)
        {
            temp1 *= n-i+1;
            temp2 *=i;
        }
        if (temp2!=0) {
            temp1 /=temp2;
        }
        return temp1;
    }
}

void dfs(int num)
{
    if (num==10) {
        success();
        return;
    }
    if (t[num]==0) {
        g[num]=0;
        dfs(num+1);
        return;
    }
    for (unsigned long int i=0; i<=t[num]; i++) {
        m[num][0]=i;
        m[num][1]=t[num]-i;
        if (i==0) {
            g[num]=1;
        }
        else
        {
            g[num]=c(t[num],i);
        }
        dfs(num+1);
    }
    return;
}

int main(int argc, const char * argv[]) {
    cin >> T;
    int k;
    while (T--) {
        scanf("%lu%d%d",&n,&a,&b);
        memset(t, 0, sizeof(t));
        memset(m, 0, sizeof(m));
        memset(g, 0, sizeof(g));
        sum=0;
        for (unsigned long int i=1; i<=n; i++) {
            scanf("%d",&k);
            t[k]++;
        }
        dfs(1);
        cout << sum << endl;
    }
    return 0;
}
