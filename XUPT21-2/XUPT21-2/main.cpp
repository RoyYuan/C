//
//  main.cpp
//  XUPT21-2
//
//  Created by 袁子涵 on 16/12/1.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;
int s[15],t[15],n;
int main(int argc, const char * argv[]) {
    while (cin >> n && n!=-1) {
        for (int i=1; i<=n; i++) {
            cin >> s[i] >> t[i];
        }
        int total=0,now=0;
        for (int i=1; i<=n; i++) {
            total+=s[i]*(t[i]-now);
            now=t[i];
        }
        cout << total << " miles" << endl;
    }
    return 0;
}
