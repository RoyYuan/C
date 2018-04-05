//
//  main.cpp
//  XUPT13-2
//
//  Created by 袁子涵 on 16/10/28.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <string>

using namespace::std;
string str;
vector<int>b,r;
int main(int argc, const char * argv[]) {
    int n,out1=0,out2=0;
    cin >> n;
    cin >> str;
    for (int i=0; i<n; i+=2) {
        if (str[i]=='r') {
            r.push_back(i);
        }
    }
    for (int i=1; i<n; i+=2) {
        if (str[i]=='b') {
            b.push_back(i);
        }
    }
    out1=r.size()-b.size();
    out1=abs(out1);
    out1+=min(r.size(),b.size());
    r.clear();
    b.clear();
    for (int i=0; i<n; i+=2) {
        if (str[i]=='b') {
            r.push_back(i);
        }
    }
    for (int i=1; i<n; i+=2) {
        if (str[i]=='r') {
            b.push_back(i);
        }
    }
    out2=r.size()-b.size();
    out2=abs(out2);
    out2+=min(r.size(),b.size());
    cout << min(out1,out2) << endl;
    return 0;
}
