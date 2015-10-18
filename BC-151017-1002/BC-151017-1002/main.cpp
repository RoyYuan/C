//
//  main.cpp
//  BC-151017-1002
//
//  Created by 袁子涵 on 15/10/17.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int T;
unsigned long long int N,M,sum=0;
unsigned long long int p,q;

unsigned long long int gcd(unsigned long long int a,unsigned long long int b)
{
    return (b>0)?gcd(b,a%b):a;
}

int main(int argc, const char * argv[]) {
    scanf("%d",&T);
    while (T--) {
        scanf("%llu%llu",&N,&M);
        sum=0;
        if (N==0 || M%N!=0 || (N==1 && M!=1) || N>M) {
            printf("-1\n");
            continue;
        }
        while (N!=M) {
            p=M/N;
            q=N;
            q=gcd(q, p);
            N*=q;
            sum++;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
