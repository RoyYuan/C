//
//  main.cpp
//  基础DP1-R-Milking Time
//
//  Created by 袁子涵 on 15/10/28.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  16ms    748KB

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#define MAX 1005

using namespace std;

typedef struct {
    long long int start,end,ef;
}interval;

long long int N,M,R;
interval inter[MAX];
long long int dp[MAX];

int comp(interval a,interval b)
{
    return a.start<b.start;
}

long long int DP(long long int num)
{
    for (long long int i=1; i<=num-1; i++)
        if (inter[i].end+R<=inter[num].start)
            dp[num]=max(dp[num],dp[i]+inter[num].ef);
    return dp[num];
}

int main(int argc, const char * argv[]) {
    long long int out=0;
    scanf("%lld%lld%lld",&N,&M,&R);
    for (long long int i=1; i<=M; i++) {
        scanf("%lld%lld%lld",&inter[i].start,&inter[i].end,&inter[i].ef);
    }
    sort(inter+1, inter+1+M, comp);
    for (long long int i=1; i<=M; i++)
        dp[i]=inter[i].ef;
    for (long long int i=1; i<=M; i++) {
        out=max(out,DP(i));
    }
    printf("%lld\n",out);
    return 0;
}
