//
//  main.cpp
//  XUPT18-3
//
//  Created by 袁子涵 on 16/11/18.
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
int num[5005],n;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int tmp1,tmp2,tmp3;
    cin >> n;
    cout << "? 1 2" << endl;
    cin >> tmp1;
    cout << "? 1 3" << endl;
    cin >> tmp2;
    cout << "? 2 3" << endl;
    cin >> tmp3;
    num[2]=(tmp3+tmp1-tmp2)>>1;
    num[1]=tmp1-num[2];
    num[3]=tmp3-num[2];
    for (int i=4; i<=n; i++) {
        cout << "? 1 " << i << endl;
        cin >> tmp1;
        num[i]=tmp1-num[1];
    }
    cout << "!";
    for (int i=1; i<=n; i++) {
        cout << " " << num[i];
    }
    cout << endl;
    return 0;
}
