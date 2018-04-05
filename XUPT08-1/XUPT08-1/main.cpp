//
//  main.cpp
//  XUPT08-1
//
//  Created by 袁子涵 on 16/9/22.
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
#include <utility>
#include <vector>
#include <map>

using namespace std;
const int maxn=105;
bool vis[maxn];
int main(int argc, const char * argv[]) {
    int n,m,tmp1,tmp2,total=0;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> tmp1;
        for (int j=1; j<=tmp1; j++) {
            cin >> tmp2;
            if (vis[tmp2]) {
                continue;
            }
            total++;
            vis[tmp2]=1;
        }
    }
    if (total==m) {
        cout << "YES" << endl;
    }
    else
        cout << "NO" <<endl;
    return 0;
}
