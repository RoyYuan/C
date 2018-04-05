//
//  main.cpp
//  贪心8
//
//  Created by 袁子涵 on 17/2/21.
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
using namespace::std;
long long int n,m,out,now;
int main(int argc, const char * argv[]) {
    cin >> n >> m;
    now=n;
    if (now<=1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i=1; i<=m; i++) {
        out+=2*now-3;
        now-=2;
        if (now<=1) {
            break;
        }
    }
    cout << out << endl;
    return 0;
}
