//
//  main.cpp
//  XUPT14-1
//
//  Created by 袁子涵 on 16/11/3.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <utility>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    long long int l1,l2,r1,r2,k,out;
    cin >> l1 >> r1 >> l2 >> r2 >> k;
    l1=max(l1,l2);
    r1=min(r1,r2);
    out=r1-l1+1;
    if (k>=l1 && k<=r1) {
        out--;
    }
    if (out<0) {
        cout << 0 << endl;
    }
    else
        cout << out << endl;
    return 0;
}
