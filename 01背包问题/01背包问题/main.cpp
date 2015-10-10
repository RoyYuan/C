//
//  main.cpp
//  01背包问题
//
//  Created by 袁子涵 on 15/5/25.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define v(x) (*(f+x-1))
#define d(x) (*(d+x))
#define max(a,b) ((a)>(b)?(a):(b))

int n,S;
int *f;
int *d;

int dp(int s)
{
    int & ans=d(s);
    if (ans!=-1) {
        return ans;
    }
    ans=-(1<<30);
    for (int i=1; i<=n; i++) {
        if (s>=v(i)) {
            ans=max(ans,dp(s-v(i))+1);
        }
    }
    return ans;
    
}

int main(int argc, const char * argv[]) {
    int maxnum;
    scanf("%d%d",&n,&S);
    f=(int*)malloc(sizeof(int)*n);
    d=(int*)malloc(sizeof(int)*(S+1));
    for (int i=0; i<n; i++) {
        scanf("%d",f+i);
    }
    memset(d, -1, sizeof(int)*(S+1));
    d(0)=0;
    maxnum=dp(S);
    printf("%d\n",maxnum);
    return 0;
}
