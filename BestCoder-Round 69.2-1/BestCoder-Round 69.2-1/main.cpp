//
//  main.cpp
//  BestCoder-Round 69.2-1
//
//  Created by 袁子涵 on 16/1/23.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;


int t,a,b,c,num1,num2,t1,t2,now;
int main(int argc, const char * argv[]) {
    cin >> t;
    while (t--) {
        scanf("%d%d%d",&a,&b,&c);
        if (c%2) {
            printf("Impossible\n");
            continue;
        }
        num1=num2=0;
        c=c/2;
        t1=max(a,b);
        t2=min(a,b);
        now=0;
        while (now<=c) {
            now+=t1;
        }
        now-=t1;
        if (now==c) {
            num1=c/t1;
            num1*=2;
            if (t1==a) {
                printf("%d %d\n",num1,num2);
            }
            else
                printf("%d %d\n",num2,num1);
        }
        else
        {
            while ((c-now)%t2!=0 && now>=0) {
                now-=t1;
            }
            if (now<0) {
                printf("Impossible\n");
                continue;
            }
            else
            {
                num1=now/t1;
                num2=(c-now)/t2;
                num1*=2;
                num2*=2;
                if (t1==a) {
                    printf("%d %d\n",num1,num2);
                }
                else
                    printf("%d %d\n",num2,num1);
            }
        }
    }
    return 0;
}
