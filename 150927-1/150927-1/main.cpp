//
//  main.cpp
//  150927-1
//
//  Created by 袁子涵 on 15/9/27.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

long long int T;
long long int D,s1,s2,sum;
long long int N,x;
bool flag;
long long int q,t;

long long int Count(long long int x)//计算n的二进制值中1的个数
{
    x=(x&0x55555555)+((x>>1)&0x55555555);
    x=(x&0x33333333)+((x>>2)&0x33333333);
    x=(x&0x0F0F0F0F)+((x>>4)&0x0F0F0F0F);
    x=(x&0x00FF00FF)+((x>>8)&0x00FF00FF);
    x=(x&0x0000FFFF)+((x>>16)&0x0000FFFF);
    return x;
}

int main(int argc, const char * argv[]) {
    scanf("%lld",&T);
    
    long long int p=T;
    while (p--) {
        scanf("%lld%lld%lld",&D,&s1,&s2);
        N=D+1;
        x=N;
        sum=0;
        flag=0;
        while (1) {
            sum=0;
            sum=Count(x);
            if (s1<=sum && s2>=sum) {
                printf("Case #%lld: %lld\n",T-p,N);
                break;
            }
            if (sum<s1) {
                q=s1-sum;
                t=1;
                while(q)
                {
                    if (N^t) {
                        N+=t;
                        q--;
                    }
                    t<<=1;
                }
            }
            else
            {
                N++;
            }
            x=N;
        }
    }
    return 0;
}
