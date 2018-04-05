//
//  main.cpp
//  cf-368-2-3
//
//  Created by 袁子涵 on 16/8/20.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <utility>
#include <map>

using namespace std;
long long int now,a,b,c;
int main(int argc, const char * argv[]) {
    cin >> a;
    if (a<3) {
        cout << -1 << endl;
        return 0;
    }
    if (a&1) {
        b=(a*a-1)/2;
        c=(a*a+1)/2;
        cout << b << " " << c << endl;
    }
    else
    {
        b=a*a/4-1;
        c=a*a/4+1;
        cout << b << " " << c << endl;
    }
    return 0;
}
