//
//  main.cpp
//  XUPT04-A
//
//  Created by 袁子涵 on 16/9/8.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>

using namespace std;
long long int n,b,d,a,now,out;
int main(int argc, const char * argv[]) {
    cin >> n >> b >> d;
    for (long long int i=1; i<=n; i++) {
        scanf("%lld",&a);
        if (a>b)
            continue;
        now+=a;
        if (now>d) {
            out++;
            now=0;
        }
    }
    printf("%lld\n",out);
    return 0;
}
