//
//  main.cpp
//  贪心5
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
int main(int argc, const char * argv[]) {
    int a,b,ans=0;
    cin >> a >> b;
    while ((a>1 || b>1) && a>0 && b>0) {
        if (a<b)    swap(a, b);
        a-=2;
        b++;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
