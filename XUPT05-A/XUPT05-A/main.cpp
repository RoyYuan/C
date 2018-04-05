//
//  main.cpp
//  XUPT05-A
//
//  Created by 袁子涵 on 16/9/9.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;
int main(int argc, const char * argv[]) {
    double out=1e10;
    int fx,fy,a,b,v,n;
    cin >> fx >> fy >> n;
    for (int i=1; i<=n; i++) {
        cin >> a >> b >> v;
        out=min(out,sqrt((double)(a-fx)*(a-fx)+(b-fy)*(b-fy))/v);
    }
    printf("%.20f\n",out);
    return 0;
}
