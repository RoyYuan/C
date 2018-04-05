//
//  main.cpp
//  2015-ccpc-L
//
//  Created by 袁子涵 on 15/11/20.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  0ms 1584kb

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(int argc, const char * argv[]) {
    int T,now=0;
    long long int n;
    cin >> T;
    while (now<T) {
        cin >> n;
        n=2*n-1;
        now++;
        printf("Case #%d: %lld\n",now,n);
    }
    return 0;
}
