//
//  main.cpp
//  RE-2-1
//
//  Created by 袁子涵 on 17/7/26.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <utility>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    long long int t,a,b,p,q;
    cin >> t;
    while (t--) {
        long long int x;
        cin >> a >> b >> p >> q;
        if (a!=0 && p==0) {
            cout << -1 << endl;
            continue;
        }
        if (a!=b && p==q) {
            cout << -1 << endl;
            continue;
        }
        if (a*q==b*p) {
            cout << 0 << endl;
            continue;
        }
        x=max((long long int)ceil((double)(a*1.0/p)),(long long int)ceil((double)((b-a)*1.0/(q-p))));
        cout << x*q-b << endl;
    }
    return 0;
}
