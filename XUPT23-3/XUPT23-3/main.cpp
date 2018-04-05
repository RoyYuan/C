//
//  main.cpp
//  XUPT23-3
//
//  Created by 袁子涵 on 17/2/13.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;
long long int n,now,total;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> n;
    long long int a;
    for (int i=0; i<n; i++) {
        cin >> a;
        total+=abs(a-now);
        now=a;
    }
    cout << total << endl;
    return 0;
}
