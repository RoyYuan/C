//
//  main.cpp
//  HDU-5630-Rikka with Chess
//
//  Created by 袁子涵 on 16/2/24.
//  Copyright © 2016年 袁子涵. All rights reserved.
//
//  0ms 1600KB

#include <iostream>

using namespace::std;

int main(int argc, const char * argv[]) {
    long long int t,n,m,out;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        out=0;
        out+=n/2;
        out+=m/2;
        cout << out << endl;
    }
    return 0;
}
