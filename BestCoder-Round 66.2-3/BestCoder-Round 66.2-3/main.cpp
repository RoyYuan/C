//
//  main.cpp
//  BestCoder-Round 66.2-3
//
//  Created by 袁子涵 on 15/12/12.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

long long int n,x;
long long int eular(long long int t)
{
    long long int ans=t;
    for (long long int i=2; i*i<=t; i++) {
        if (t%i==0) {
            ans-=ans/i;
            while (t%i==0) {
                t/=i;
            }
        }
    }
    if (t>1) {
        ans-=ans/t;
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    while (scanf("%lld%lld",&n,&x)!=EOF) {
        cout << eular(x+n+1) << endl;
    }
    return 0;
}
