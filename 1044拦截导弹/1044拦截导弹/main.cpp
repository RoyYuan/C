//
//  main.cpp
//  1044拦截导弹
//
//  Created by 袁子涵 on 15/5/21.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#define f(x) (*(data+x))

int sum;
int max;
int *data;
int n=0;
int longest;

void times(int num,int last,int s)
{
    if (num==n) {
        if (s>longest) {
            longest=s;
        }
        return;
    }
    if (f(num)>=last) {
        last=f(num);
        times(num+1,last,s+1);
    }
    else
    {
        times(num+1, last, s);
    }
    return;
}

void dfs(int limit,int num,int s)
{
    if (num==n) {
        if (s>max) {
            max=s;
        }
        return;
    }
    if (limit-*(data+num)>=0) {
        dfs(f(num), num+1, s+1);
    }
    dfs(limit, num+1, 1);
    return;
}

int main(int argc, const char * argv[]) {
    max=0;
    data=(int*)malloc(sizeof(int)*20);
    while (scanf("%d",(data+n))!=0) {
        n++;
    }
    dfs(30000, 0, 0);
    times(0, f(0), 1);
    printf("%d\n%d",max,longest);
    return 0;
}
