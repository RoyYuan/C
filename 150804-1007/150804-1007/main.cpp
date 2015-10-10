//
//  main.cpp
//  150804-1007
//
//  Created by 袁子涵 on 15/8/4.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

long long int N;

long long int a,b,c;

unsigned long int sum=1;


long long int maxs=0;

long long int mins=0;

int main(int argc, const char * argv[]) {
    scanf("%lld",&N);
    long long int T=N;
    while (T--) {
         scanf("%lld",&a);
        if (a==1) {
            scanf("%lld",&b);
            sum++;
            if (b>maxs) {
                maxs=b;
            }
            if (sum==2) {
                maxs=b;
                mins=b;
            }
            continue;
        }
        else
        {
            if (a==2) {
                if (sum==1) {
                    continue;
                }
                if (sum==2) {
                    sum=1;
                    maxs=0;
                    continue;
                }
                sum--;
                continue;
            }
            if (a==3) {
                if (sum==1) {
                    printf("0\n");
                    continue;
                }
                printf("%lld\n",maxs);
                continue;
            }
        }
    }
    return 0;
}
