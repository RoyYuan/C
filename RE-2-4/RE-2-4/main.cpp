//
//  main.cpp
//  RE-2-4
//
//  Created by 袁子涵 on 17/7/28.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <string>

using namespace std;
int n,x,y,a,b;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> n;
    cout << "YES" << endl;
    while (n--) {
        
        cin >> x >> y >> a >> b;
        cout << 1+2*(abs(x)%2)+abs(y)%2 << endl;
    }
    return 0;
}
