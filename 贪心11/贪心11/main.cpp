//
//  main.cpp
//  贪心11
//
//  Created by 袁子涵 on 17/2/24.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <list>
#include <map>
#include <stack>
using namespace::std;
int main(int argc, const char * argv[]) {
    int n;
    long long int l,r,out,tmp;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> l >> r;
        out=(1ll<<62)-1;
        tmp=1ll<<62;
        for (int i=62; i>0; i--) {
            tmp>>=1;
            if (out<=r) break;
            if (out-tmp>=l) out-=tmp;
        }
        cout << out << endl;
    }
    return 0;
}
