//
//  main.cpp
//  XUPT15-3
//
//  Created by 袁子涵 on 16/11/4.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <utility>

using namespace std;
long long int n;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> n;
    n++;
    long long int k=2;
    printf("2\n");
    while (k<n) {
        printf("%lld\n",k*k*k+2*k*k+1);
        k++;
    }
    return 0;
}
