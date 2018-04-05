//
//  main.cpp
//  XUPT02-1
//
//  Created by 袁子涵 on 16/5/31.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <utility>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if(c == 0){
        if(a == b){
            cout << "YES" << endl;
            return 0;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }
    if((b-a)/c >= 0 && (b-a) % c == 0){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
