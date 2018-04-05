//
//  main.cpp
//  XUPT12-B
//
//  Created by 袁子涵 on 16/10/19.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>
#include <string>
#include <queue>

using namespace std;
long long int n,tmp;
int main(int argc, const char * argv[]) {
    cin >> n;
    bool last=0,flag=1;
    for (long long int i=1; i<=n; i++) {
        cin >> tmp;
        if (last) {
            if (tmp<=0) {
                flag=0;
                break;
            }
            tmp--;
            last=0;
        }
        if (tmp&1) {
            last=1;
        }
        else
            last=0;
    }
    if (last) {
        flag=0;
    }
    if (flag) {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
