//
//  main.cpp
//  XUPT19-2
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
int a[105];
int main(int argc, const char * argv[]) {
    int n,m,l,r;
    long long int ans=0;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=m; i++) {
        cin >> l >> r;
        long long int tmp=0;
        for (int j=l; j<=r; j++) {
            tmp+=a[j];
        }
        if (tmp>0) {
            ans+=tmp;
        }
    }
    cout << ans << endl;
    return 0;
}
