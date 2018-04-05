//
//  main.cpp
//  XUPT02-2
//
//  Created by 袁子涵 on 16/5/31.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <utility>
#include <stack>
using namespace std;
typedef long long int LL;
int main(int argc, const char * argv[]) {
    int a, b, c, d, n;
    scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
    int e = max(a,d) + max(b,c);
    int f = min(a,d) + min(b,c);
    if(1-f>n-e){
        cout << 0 << endl;
        return 0;
    }
    LL r = (n-e)-(1-f)+1;
    r = r*((LL)n);
    cout << r << endl;
    return 0;
}
