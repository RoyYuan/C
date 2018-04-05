//
//  main.cpp
//  RE-3-1
//
//  Created by 袁子涵 on 17/8/2.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <utility>
using namespace std;
int s,v1,v2,t1,t2,a1,a2;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> s >> v1 >> v2 >> t1 >> t2;
    a1=2*t1+v1*s;
    a2=2*t2+v2*s;
    if (a2>a1) {
        cout << "First" << endl;
    }
    else if(a2==a1)
        cout << "Friendship" << endl;
    else
        cout << "Second" << endl;
    return 0;
}
