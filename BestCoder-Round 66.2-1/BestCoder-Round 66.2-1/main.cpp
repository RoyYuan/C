//
//  main.cpp
//  BestCoder-Round 66.2-1
//
//  Created by 袁子涵 on 15/12/12.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x7fffffff
using namespace std;
long long int a,b,c,l,r;
long long int f(long long int x)
{
    return a*x*x+b*x+c;
}

int main(int argc, const char * argv[]) {
    int t;
    long long int maxs,mins;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> l >> r;
        maxs=f(l);
        mins=f(l);
        for (long long int i=l; i<=r; i++) {
            mins=min(mins,f(i));
            maxs=max(maxs,f(i));
        }
        printf("%lld %lld\n",maxs,mins);
    }
    return 0;
}
