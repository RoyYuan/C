//
//  main.cpp
//  XUPT02-4
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

int n, a, b, tmp;
map<int,int> times, plz;
map<int,int>::iterator now;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> n;
    plz[0] = -1;
    for(int i=0; i<n; ++i) {
        cin >> tmp;
        times[tmp]=1,plz[tmp]=i;
        now=times.find(tmp);
        if (now==times.begin())
            a=0;
        else
        {
            now--;
            a=now->first;
            now++;
        }
        now++;
        if (now==times.end())
            b=0;
        else
            b=now->first;
        if (i)
            cout << (plz[a]>plz[b]?a:b) << " ";
    }
    cout << endl;
    
    return 0;
}