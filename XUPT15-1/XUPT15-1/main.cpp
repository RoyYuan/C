//
//  main.cpp
//  XUPT15-1
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
long long int n,c;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> n >> c;
    long long int total=1,last,tmp;
    cin >> last;
    for (long long int i=1; i<n; i++) {
        cin >> tmp;
        if (tmp-last>c) {
            total=1;
            last=tmp;
        }
        else
        {
            total++;
            last=tmp;
        }
    }
    cout << total << endl;
    return 0;
}
