//
//  main.cpp
//  XUPT06-1
//
//  Created by 袁子涵 on 16/9/14.
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
#include <queue>
#include <vector>
#include <utility>
#include <map>

using namespace std;
int n;
int a,b;
int fa,fb;
int main(int argc, const char * argv[]) {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a >> b;
        if (a==b)
            continue;
        else if (a>b)
            fa++;
        else
            fb++;
    }
    if (fa>fb)
        cout << "Mishka" << endl;
    else if (fb>fa)
        cout << "Chris" << endl;
    else
        cout << "Friendship is magic!^^" << endl;
    return 0;
}
