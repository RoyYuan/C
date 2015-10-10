//
//  main.cpp
//  150811-1007
//
//  Created by 袁子涵 on 15/8/11.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")

#define maxof(a,b)  ((a)>(b)?(a):(b))

using namespace std;

long long int T;
char num[300010];
int a[300010];
unsigned long long int s;

void sum(unsigned long long int n)
{
    unsigned long long int ss=0;
    if (num[0]=='1') {
        ss+=a[0];
    }
    for (unsigned long int i=1; i<n; i++) {
        if (num[i]!=num[i-1]) {
            ss+=a[i];
        }
    }
    s=maxof(s,ss);
    
}

void dfs(unsigned long int step,unsigned long long int n)
{
    if (step==n) {
        sum(n);
        return;
    }
    if (num[step]!='?') {
        dfs(step+1,n);
        return;
    }
    else
    {
        if (step==0) {
            num[step]='1';
            dfs(step+1,n);
            num[step]='0';
            dfs(step+1,n);
            num[step]='?';
            return;
        }
        if (step==n-1) {
            num[step]=(num[step-1]=='0'?'1':'0');
            dfs(step+1,n);
            num[step]='?';
            return;
        }
        if (num[step-1]=='1' && (num[step+1]=='1' || num[step+1]=='?')) {
            num[step]='0';
            dfs(step+1,n);
            num[step]='?';
            return;
        }
        if (num[step-1]=='0' && (num[step+1]=='0' || num[step+1]=='?')) {
            num[step]='1';
            dfs(step+1,n);
            num[step]='?';
            return;
        }
        num[step]='1';
        dfs(step+1,n);
        num[step]='0';
        dfs(step+1,n);
        num[step]='?';
        return;
    }
}

int main(int argc, const char * argv[]) {
    cin >> T;
    long long int t=1;
    unsigned long int n;
    while (T--) {
        memset(num, 0, sizeof(num));
        memset(a, 0, sizeof(a));
        s=0;
        scanf("%s",num);
        n=strlen(num);
        for (unsigned long int i=0; i<n; i++) {
            scanf("%d",&a[i]);
        }
        dfs(0,n);
        printf("Case #%lld: %llu\n",t++,s);
    }
    return 0;
}
