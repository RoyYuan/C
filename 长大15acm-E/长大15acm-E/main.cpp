//
//  main.cpp
//  长大15acm-E
//
//  Created by 袁子涵 on 15/12/7.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;
long long int n;
long long int price[100005];
int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        long long int out=0,now=0,maxs=0,pre=0;
        cin >> n;
        for (long long int i=1; i<=n; i++) {
            scanf("%lld",&price[i]);
            if (price[i]>=maxs) {
                maxs=price[i];
                now=i;
            }
        }
        for (long long int i=1; i<=now; i++)
            out+=maxs-price[i];
        while (now!=n) {
            pre=now;
            maxs=0;
            for (long long int i=now+1; i<=n; i++) {
                if (price[i]>=maxs) {
                    maxs=price[i];
                    now=i;
                }
            }
            for (long long int i=pre+1; i<=now; i++)
                out+=maxs-price[i];
        }
        cout << out << endl;
    }
    return 0;
}
