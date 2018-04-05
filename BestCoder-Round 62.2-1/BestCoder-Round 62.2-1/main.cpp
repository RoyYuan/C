//
//  main.cpp
//  BestCoder-Round 62.2-1
//
//  Created by 袁子涵 on 15/11/14.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int T;
long long int n,big;
long long int v[100010];

int main(int argc, const char * argv[]) {
    cin >> T;
    while (T--) {
        long long int sum=0;
        cin >> n >> big;
        for (long long int i=0; i<n; i++) {
            scanf("%lld",&v[i]);
        }
        sort(v+0,v+n);
        int x=0;
        while (big>0) {
            big-=v[x++];
            sum++;
        }
        sum--;
        cout << sum << endl;
    }
    return 0;
}
