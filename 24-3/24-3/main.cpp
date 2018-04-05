//
//  main.cpp
//  24-3
//
//  Created by 袁子涵 on 16/4/24.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define fix ('a'-'A')
using namespace std;
string str,tmp;
int n,m;
int main(int argc, const char * argv[]) {
    while (cin >> n >> m) {
        str.clear();
        for (int i=0; i<n; i++) {
            cin >> tmp;
            str+=tmp;
        }
        cin >> tmp;
        for (int i=0; i<str.size(); i++) {
            if (str[i]>'Z') {
                str[i]-=fix;
            }
        }
        for (int i=0; i<tmp.size(); i++) {
            if (tmp[i]>'Z') {
                tmp[i]-=fix;
            }
        }
        if (str.find(tmp)!=std::string::npos) {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}
