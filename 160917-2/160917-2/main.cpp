//
//  main.cpp
//  160917-2
//
//  Created by 袁子涵 on 16/9/17.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <utility>
#include <map>

using namespace std;
const long long int inf=1e9+5;
set<long long int>S;
int out[4][35];
int main(int argc, const char * argv[]) {
    set<long long int>::iterator it;
    long long int now,last1,last2,last3,last4;
    now=last1=last2=last3=last4=1;
    for (; now<inf; now*=2,last1*=2) {
        last2=1;
        for (; now<inf; now*=3,last2*=3) {
            last3=1;
            for (; now<inf; now*=5,last3*=5) {
                last4=1;
                for (; now<inf; now*=7,last4*=7) {
                    S.insert(now);
                }
                now/=last4;
            }
            now/=last3;
        }
        now/=last2;
    }
    long long int t;
    scanf("%lld",&t);
    for (long long int i=1; i<=t; i++) {
        scanf("%lld",&now);
        it=S.lower_bound(now);
        printf("%lld\n",*it);
    }
    return 0;
}
