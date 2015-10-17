//
//  main.cpp
//  BC-151017-1001
//
//  Created by 袁子涵 on 15/10/17.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define maxof(a,b) ((a)>(b)?(a):(b))

using namespace std;

long long int T,N;
int a,b,c;
long long int p[65],q[65];
unsigned long long int sum;

int comp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}

int main(int argc, const char * argv[]) {
    long long int temp,max=-0xFFFFFFF;
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld",&N);
        memset(p, 0, sizeof(p));
        memset(q, 0, sizeof(q));
        a=0;
        b=0;
        c=0;
        sum=1;
        for (int i=0; i<N; i++) {
            scanf("%lld",&temp);
            max=maxof(max,temp);
            if (temp>=0) {
                if (temp==0) {
                    c++;
                }
                else
                    p[a++]=temp;
            }
            else
            {
                q[b++]=temp;
            }
        }
        if (N==1) {
            printf("%lld\n",temp);
            continue;
        }
        if (a==0 && b<=1 && c>0) {
            printf("0\n");
            continue;
        }
        for (int i=0; i<a; i++) {
            sum*=p[i];
        }
        qsort(q,b, sizeof(long long int), comp);
        for (int i=0; i<b/2 ;i++) {
            sum*=abs(q[2*i]);
            sum*=abs(q[2*i+1]);
        }
        printf("%llu\n",sum);
        
    }
    return 0;
}
