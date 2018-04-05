//
//  main.cpp
//  XUPT02-5
//
//  Created by 袁子涵 on 16/5/31.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <utility>
#include <stack>
#include <map>
using namespace std;
long long int n,out,a[100005],num[100005],now,last,step;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> n;
    for (long long int i=1; i<n; i++) {
        cin >> a[i];
    }
    now=last=step=1;
    while (now!=n) {
        now=a[now];
        for (long long int i=last+1; i<=now; i++) {
            num[i]=step;
        }
        step++;
        last=now;
    }
    for (long long int i=2; i<=n; i++) {
        for (long long int j=i; j<=n; j++) {
            out+=num[j];
        }
        for (long long int j=i+1; j<=n; j++)
            if (num[j]>1) {
                num[j]--;
            }
    }
    cout << out << endl;
    return 0;
}
