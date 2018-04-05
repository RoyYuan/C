//
//  main.cpp
//  XUPT23-6
//
//  Created by 袁子涵 on 17/2/13.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    int x[3];
    cin >> x[0] >> x[1] >> x[2];
    sort(x+0, x+3);
    cout << x[2]-x[0] << endl;
    return 0;
}
