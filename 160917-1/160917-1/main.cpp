//
//  main.cpp
//  160917-1
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

int main(int argc, const char * argv[]) {
    long long int n,now;
    cin >> n;
    for (long long int i=1; i<=n; i++) {
        cin >> now;
        if (now&1) {
            cout << "Balanced" << endl;
        }
        else
            cout << "Bad" << endl;
    }
    return 0;
}
