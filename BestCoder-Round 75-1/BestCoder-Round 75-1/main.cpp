//
//  main.cpp
//  BestCoder-Round 75-1
//
//  Created by 袁子涵 on 16/3/12.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
int t;
long long int n,m,out,a,b;
int main(int argc, const char * argv[]) {
    cin >> t;
    while (cin >> n >> m) {
        out=0;
        a=min(n,m);
        b=max(n,m);
        while (a>0 && b>0) {
            if (a==b) {
                out++;
                break;
            }
            b-=a;
            out++;
            if (a>b) {
                swap(a, b);
            }
        }
        cout << out << endl;
    }
    return 0;
}
