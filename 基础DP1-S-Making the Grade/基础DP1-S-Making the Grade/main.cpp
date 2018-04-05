//
//  main.cpp
//  基础DP1-S-Making the Grade
//
//  Created by 袁子涵 on 15/10/28.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  125ms   32108KB

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#define minof(A,B)  ((A)>(B)?(B):(A))

using namespace std;

int N;
long long int height[2002],sh[2002];
long long int dp[2002][2002];

int comp(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}

long long int ABS(long long int num)
{
    if (num>=0) {
        return num;
    }
    else
        return -num;
}

void DP()
{
    for (int i=0; i<N; i++) {
        dp[0][i]=ABS(height[0]-sh[i]);
    }
    for (int i=1; i<N; i++) {
        long long int k=dp[i-1][0];
        for (int j=0; j<N; j++) {
            long long int temp=ABS(height[i]-sh[j]);
            k=minof(k, dp[i-1][j]);
            dp[i][j]=k+temp;
        }
    }
}

int main(int argc, const char * argv[]) {
    long long int out=0x7fffffff;
    scanf("%d",&N);
    for (int i=0; i<N; i++) {
        scanf("%lld",&height[i]);
        sh[i]=height[i];
    }
    qsort(sh, N, sizeof(long long int), comp);
    DP();
    for (int i=0; i<N; i++) {
        out=minof(dp[N-1][i],out);
    }
    printf("%lld\n",out);
    return 0;
}
