//
//  main.cpp
//  160917-3
//
//  Created by 袁子涵 on 16/9/17.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <utility>
#include <map>

using namespace std;
const int maxn=1000005;
double ans[maxn];
int main(int argc, const char * argv[]) {
    long long int now=1,tt;
    for (int i=1; i<=1e6; i++)
    {
        ans[i]=ans[i-1]+(double)1/(double)(1.0*now*now);
        now++;
    }
    printf("%.5lf\n",ans[150000]);
    string str;
    while (cin >> str) {
        if (str.length()>=7) {
            cout << 1.64493 << endl;
            continue;
        }
        now=0;
        tt=1;
        for (int i=str.length()-1; i>=0; i--) {
            now+=(str[i]-'0')*tt;
            tt*=10;
        }
        cout << ans[now] << endl;
    }
    return 0;
}
