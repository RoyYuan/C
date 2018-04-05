//
//  main.cpp
//  BestCoder-Round 71.2-1
//
//  Created by 袁子涵 on 16/2/6.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int t;
long long int n;
long long int x;
long long int a,b,c,sum;
int main(int argc, const char * argv[]) {
    cin >> t;
    while (t--) {
        scanf("%lld",&n);
        a=1;
        b=2;
        x=3;
        sum=1;
        if (n<3) {
            cout << "1" << endl;
            continue;
        }
        while (x<=n) {
            sum++;
            x+=a+b;
            c=b;
            b=a+b;
            a=c;
        }
        cout << sum << endl;
    }
    return 0;
}
