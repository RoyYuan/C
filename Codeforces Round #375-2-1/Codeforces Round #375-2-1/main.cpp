//
//  main.cpp
//  Codeforces Round #375-2-1
//
//  Created by 袁子涵 on 16/10/3.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <utility>
#include <queue>
#include <vector>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    long long int x[4];
    for (int i=0; i<3; i++) {
        cin >> x[i];
    }
    sort(x+0,x+3);
    cout << x[2]-x[0] << endl;
    return 0;
}
