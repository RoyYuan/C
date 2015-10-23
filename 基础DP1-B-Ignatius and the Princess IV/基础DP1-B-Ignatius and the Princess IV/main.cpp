//
//  main.cpp
//  基础DP1-B-Ignatius and the Princess IV
//
//  Created by 袁子涵 on 15/10/22.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>

long long int N;
int sum,num,out;

int main(int argc,const char*argv[])
{
    while (scanf("%lld",&N)!=EOF) {
        sum=0;
        for (long long int i=0; i<N; i++) {
            scanf("%d",&num);
            if (sum==0) {
                sum++;
                out=num;
            }
            else
            {
                if (num!=out) {
                    sum--;
                }
                else
                    sum++;
            }
        }
        printf("%d\n",out);
    }
}