//
//  main.cpp
//  XUPT13-1
//
//  Created by 袁子涵 on 16/10/28.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <map>

using namespace::std;

int main(int argc, const char * argv[]) {
    int flag=-1,now,last=-1;
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> now;
        if (i>1) {
            if (now>last) {
                flag=1;
            }
            else
            {
                flag=0;
            }
        }
        last=now;
    }
    if (now==15) {
        flag=0;
    }
    if (now==0) {
        flag=1;
    }
    if (flag==0) {
        cout << "DOWN" << endl;
    }
    else if (flag==1)
        cout << "UP" << endl;
    else
        cout << -1 << endl;
    return 0;
}
