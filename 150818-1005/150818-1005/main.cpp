//
//  main.cpp
//  150818-1005
//
//  Created by 袁子涵 on 15/8/18.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

long long int num[100010];
long long int head[100010];
long long int tail[100010];
unsigned long long int sum;

int d1,d2;
long int n;

void dp(long int x)
{
    if (x==n) {
        return;
    }
    //d1
    if (num[x]==num[x-1]+d1) {
        head[x]=head[x-1]+1;
        tail[x]=1;
        dp(x+1);
        return;
    }
    //d2
    if (num[x]==num[x-1]+d2) {
        head[x]=1;
        tail[x]=tail[x-1]+head[x-1];
        dp(x+1);
        return;
    }
    //其他
    else
    {
        head[x]=1;
        tail[x]=1;
        dp(x+1);
    }
    return;
}

int main(int argc, const char * argv[]) {
    while (scanf("%ld%d%d",&n,&d1,&d2)!=EOF) {
        memset(num, 0, sizeof(num));
        memset(head, 0, sizeof(head));
        memset(tail, 0, sizeof(tail));
        sum=0;
        for (long int i=0; i<n; i++) {
            scanf("%lld",&num[i]);
        }
        head[0]=1;
        tail[0]=1;
        dp(1);
        for (long int i=0; i<n; i++) {
            sum+=(head[i]+tail[i]-1);
        }
        printf("%llu\n",sum);
    }
    return 0;
}
