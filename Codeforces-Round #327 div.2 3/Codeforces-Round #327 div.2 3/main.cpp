//
//  main.cpp
//  Codeforces-Round #327 div.2 3
//
//  Created by 袁子涵 on 15/10/25.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#define MAX 10

using namespace std;

long long int n;
int num[2][MAX],t=0,x,flag;
bool k;
int main(int argc, const char * argv[]) {
    scanf("%lld",&n);
    memset(num, 0, sizeof(num));
    for (long long int i=1; i<=n; i++) {
        scanf("%d",&num[0][i]);
    }
    num[1][1]=num[0][1];
    num[1][n]=num[0][n];
    k=1;
    while (1) {
        flag=1;
        for (long long int i=2; i<n; i++) {
            if (num[!k][i]!=num[!k][i-1] && num[!k][i]!=num[!k][i+1]) {
                num[k][i]=!num[!k][i];
                flag=0;
            }
        }
        for (long long int i=1; i<=n; i++) {
            printf("%d ",num[k][i]);
        }
        getchar();
        if (flag || t>100000) {
            break;
        }
        k=!k;
        t++;
    }
    if (t>100000) {
        printf("-1");
        return 0;
    }
    printf("%d\n",t);
    for (long long int i=1; i<=n; i++) {
        printf("%d ",num[k][i]);
    }
    return 0;
}
