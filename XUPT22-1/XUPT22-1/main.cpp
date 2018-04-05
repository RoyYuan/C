//
//  main.cpp
//  XUPT22-1
//
//  Created by 袁子涵 on 16/12/2.
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
long long int n,a,ans;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    long long int tmp;
    cin >> n;
    cin >> a;
    for (long long int i=1; i<=n; i++) {
        cin >> tmp;
        if (tmp<0) {
            if (a&1)
                continue;
            ans+=tmp*tmp;
        }
        else
            ans+=pow(tmp, a);
    }
    cout << ans << endl;
    return 0;
}