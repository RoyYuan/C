//
//  main.cpp
//  贪心10
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
    int n,cost=0,a,p,now=0x7fffffff;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a >> p;
        now=min(now,p);
        cost+=a*now;
    }
    cout << cost << endl;
    return 0;
}
