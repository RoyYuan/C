//
//  main.cpp
//  XUPT21-1
//
//  Created by 袁子涵 on 16/12/1.
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
double a[105];
int n;
int main(int argc, const char * argv[]) {
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    for (int i=n; i>1; i--)
        a[i-1]=2*sqrt(a[i]*a[i-1]);
    printf("%.3f\n",a[1]);
    return 0;
}
