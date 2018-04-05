//
//  main.cpp
//  BestCoder-Round 71.2-2
//
//  Created by 袁子涵 on 16/2/6.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;
unsigned long long int t,n,out;

int main(int argc, const char * argv[]) {
    cin >> t;
    while (t--) {
        cin >> n;
        if (n<=3) {
            cout << n << endl;
        }
        else
        {
            out=n*(n-1)/2*(n-2)/3*(n-3)/4+n;
            cout << out << endl;
        }
    }
    return 0;
}
