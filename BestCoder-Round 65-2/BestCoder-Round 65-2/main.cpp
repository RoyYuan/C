//
//  main.cpp
//  BestCoder-Round 65-2
//
//  Created by 袁子涵 on 15/12/5.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    long long int t,n;
    cin >> t;
    while (t--) {
        scanf("%lld",&n);
        printf("%lld\n",n%2);
    }
    return 0;
}
