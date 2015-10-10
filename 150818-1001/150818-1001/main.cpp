//
//  main.cpp
//  150818-1001
//
//  Created by 袁子涵 on 15/8/18.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int n;
long long int num[110],cpy[110];
bool visit[110];
long long int sum;
char op[110],cop[110];

long long int opt(long long int a,long long int b,char c)
{
    switch (c) {
        case '+':
            return a+b;
            break;
        case '-':
            return a-b;
            break;
        case '*':
            return a*b;
            break;
        default:
            break;
    }
    return 0;
}

void dfs(int step,int x)
{
    long long int cpy1;
    char cpy2;
    int next=0,flag=0;;
    if (step==n-1) {
        sum+=num[x];
        if (sum<0) {
            sum+=1000000007;
        }
        sum=sum%1000000007;
        return;
    }
    for (int i=x+1; i<n; i++) {
        if (visit[i]==0) {
            flag=1;
            next=i;
            break;
        }
    }
    if (flag==0) {
        return;
    }
    cpy1=num[x];
    cpy2=op[x];
    num[x]=opt(num[x], num[next], op[x]);
    op[x]=op[next];
    visit[next]=1;
    for (int i=0; i<n; i++) {
        if (visit[i]==0) {
            dfs(step+1, i);
        }
    }
    num[x]=cpy1;
    op[x]=cpy2;
    visit[next]=0;
}

int main(int argc, const char * argv[]) {
    while (scanf("%d",&n)!=EOF) {
        memset(num, 0, sizeof(num));
        memset(op, 0, sizeof(op));
        memset(visit, 0, sizeof(visit));
        sum=0;
        for (int i=0; i<n; i++) {
            scanf("%lld",&num[i]);
        }
        int c;
        while((c = getchar()) != '\n' && c != EOF);
        for (int i=0; i<n-1; i++) {
            scanf("%c",&op[i]);
        }
        memcpy(cpy, num, sizeof(num));
        memcpy(cop, op, sizeof(op));
        for (int i=0; i<n; i++) {
            dfs(0, i);
        }
        cout << sum << endl;
    }
    return 0;
}
