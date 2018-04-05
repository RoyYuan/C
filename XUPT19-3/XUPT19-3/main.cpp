//
//  main.cpp
//  XUPT19-3
//
//  Created by 袁子涵 on 16/11/24.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;
const int inf=0x7fffffff;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int n,m,l,r,ans=inf;
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        cin >> l >> r;
        ans=min(ans,r-l+1);
    }
    cout << ans << endl;
    for (int i=1; i<=n; i++)
        cout << i%ans << ' ';
    cout << endl;
    return 0;
}