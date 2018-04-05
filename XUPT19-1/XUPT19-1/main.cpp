//
//  main.cpp
//  XUPT19-1
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
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    long long int n,a,b,c,ans=0x7fffffffffffffff;
    cin >> n >> a >> b >> c;
    long long int tmpb,tmpc;
    tmpb=min(a*2,b);
    tmpc=min(c,a*3);
    tmpc=min(tmpc,a+b);
    b=tmpb;
    c=tmpc;
    switch (n%4) {
        case 0:
            ans=0;
            break;
        case 1:
            ans=min(c,min(a*3,a+b));
            break;
        case 2:
            ans=min(a*2,min(b,c*2));
            break;
        case 3:
            ans=min(a,min(c*3,b+c));
            break;
    }
    cout << ans << endl;
    return 0;
}
