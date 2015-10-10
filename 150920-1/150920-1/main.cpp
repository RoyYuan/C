//
//  main.cpp
//  150920-1
//
//  Created by 袁子涵 on 15/9/20.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;
int T;
double k;
long long int sum;

int main(int argc, const char * argv[]) {
    double p=1,x=0;
    int s=0;
    scanf("%d",&T);
    sum=0;
    while (T--) {
        scanf("%lf",&k);
        x=0;
        p=0.5;
        sum=0;
        s=0;
        if (k==0) {
            printf("-1\n");
            continue;
        }
        else
        {
            while (k>x && s<=500) {
                sum+=4;
                p/=2;
                x+=p;
                s++;
            }
            if (k==x) {
                printf("-1\n");
                continue;
            }
            else
            {
                printf("%lld\n",sum);
                continue;
            }
        }
    }
    return 0;
}
