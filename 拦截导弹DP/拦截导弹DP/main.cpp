//
//  main.cpp
//  拦截导弹DP
//
//  Created by 袁子涵 on 15/5/27.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>

#define maxof(a,b) ((a)>(b)?(a):(b))

int ld[21];
int li[21];
int height[21];
int n;

int lds()
{
    int max=1;
    int i,j;
    for (i=1; i<=n; i++) {
        ld[i]=1;
        for (j=1; j<i; j++) {
            if (height[j]>=height[i]) {
                ld[i]=maxof(ld[i],ld[j]+1);
            }
        }
        max=maxof(ld[i], max);
    }
    return  max;
}

int lis()
{
    int max=1;
    int i,j;
    for (i=1; i<=n; i++) {
        li[i]=1;
        for (j=1; j<i; j++) {
            if (height[j]<=height[i]) {
                li[i]=maxof(li[i], li[j]+1);
            }
        }
        max=maxof(max, li[i]);
    }
    return  max;
}

int main(int argc, const char * argv[]) {
    int i=0;
    int ds,is;
    while (scanf("%d",&height[++i])!=0);
    n=i-1;
    ds=lds();
    is=lis();
    printf("%d\n%d",ds,is);
    return 0;
}
