//
//  main.cpp
//  XUPT02-3
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
long long int n,num[100005],last,now;
map<long long int,long long int>Book;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> n;
    long long int out=n;
    for (long long int i=1; i<=n; i++) {
        cin >> num[i];
        now=last+num[i];
        Book[now]++;
        out=min(out,n-Book[now]);
        last=now;
    }
    cout << out << endl;
    return 0;
}