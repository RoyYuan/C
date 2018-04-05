//
//  main.cpp
//  XUPT14-2
//
//  Created by 袁子涵 on 16/11/3.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <utility>

using namespace std;
int n;
map<int,bool>vis;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> n;
    int tmp,total=0,mins=0x7fffffff,maxs=0,mid=0;
    for (int i=1; i<=n; i++) {
        cin >> tmp;
        if (vis[tmp]) {
            continue;
        }
        else
        {
            total++;
            if (total>3) {
                cout << "NO" << endl;
                return 0;
            }
            if (tmp<mins) {
                mid=mins;
                mins=tmp;
            }
            if (tmp>maxs) {
                mid=maxs;
                maxs=tmp;
            }
            if (tmp>mins && tmp<maxs) {
                mid=tmp;
            }
            vis[tmp]=1;
        }
    }
    if (total<3) {
        cout << "YES" << endl;
    }
    else
    {
        if (mins+maxs==2*mid) {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
