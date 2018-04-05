//
//  main.cpp
//  cf-368-2-1
//
//  Created by 袁子涵 on 16/8/20.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <utility>
#include <map>

using namespace std;
int n,m;
char c;
int main(int argc, const char * argv[]) {
    bool flag=0;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> c;
            if (c=='B' || c=='G' || c=='W') {
                continue;
            }
            flag=1;
        }
    }
    if (flag) {
        cout << "#Color" << endl;
    }
    else
        cout << "#Black&White" << endl;
    return 0;
}
