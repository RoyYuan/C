//
//  main.cpp
//  150806-1011
//
//  Created by 袁子涵 on 15/8/6.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

unsigned long long int T;
unsigned long long int n;
unsigned long long int a,b,c;

long long result(long long a,long long b,long long m)
{
    long long d,t;
    
    d=1;
    t=a;
    while (b>0)
    {
        if (b%2==1)
            d=(d*t)%m;
        b/=2;
        t=(t*t)%m;
    }
    return d;
}

int main(int argc, const char * argv[]) {
    cin >> T;
    while (T--) {
        scanf("%llu",&n);
        if (n==1) {
            printf("0\n");
            continue;
        }
        b=result(2, n-1, 1000000007);
        cout << (b-1) << endl;
    }
    return 0;
}
