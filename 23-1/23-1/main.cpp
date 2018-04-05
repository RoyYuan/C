//
//  main.cpp
//  23-1
//
//  Created by 袁子涵 on 16/4/23.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>

using namespace std;
int t;
int a,b,c,d;
int main(int argc, const char * argv[]) {
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        cout << c << " " << b+d << endl;
        cout << a << " " << b+d << endl;
    }
    return 0;
}
