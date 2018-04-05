//
//  main.cpp
//  170125-1
//
//  Created by 袁子涵 on 17/1/25.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <utility>

using namespace std;

int tri[31][31];
int main(int argc, const char * argv[]) {
    int n;
    for (int i=1; i<=30; i++) {
        tri[i][1]=1;
        for (int j=2; j<=i; j++)
            tri[i][j]=tri[i-1][j-1]+tri[i-1][j];
    }
    while (cin >> n) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<i; j++)
                cout << tri[i][j] << " ";
            cout << 1 << endl;
        }
        cout << endl;
    }
    return 0;
}
