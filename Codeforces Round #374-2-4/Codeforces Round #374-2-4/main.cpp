//
//  main.cpp
//  Codeforces Round #374-2-4
//
//  Created by 袁子涵 on 16/9/30.
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
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;
int a[1005];
int main(int argc, const char * argv[]) {
//    int a[105];
    int n,k;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        string tmp;
        cin >> tmp;
        a[tmp.size()]++;
    }
    string tmp;
    cin >> tmp;
    int ln=tmp.size();
    int xx=0,yy=0;
    for (int i=1; i<ln; i++) {
        xx+=a[i],yy+=a[i];
    }
    yy+=a[ln];
    xx++;
    xx+=((xx-1)/k)*5;
    yy+=((yy-1)/k)*5;
    cout << xx << " " << yy << endl;
    return 0;
}
