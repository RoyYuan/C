//
//  main.cpp
//  cf-369-2-1
//
//  Created by 袁子涵 on 16/8/29.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <map>

using namespace std;
const int MAXN=1005;
int n;
char a[MAXN],b[MAXN],c[MAXN],d[MAXN];
int main(int argc, const char * argv[]) {
    bool flag=0;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> c[i] >> d[i];
        if (!flag) {
            if (a[i]==b[i] && a[i]=='O') {
                flag=1;
                a[i]=b[i]='+';
            }
            else if (c[i]==d[i] && c[i]=='O')
            {
                flag=1;
                c[i]=d[i]='+';
            }
        }
    }
    if (flag) {
        puts("YES");
        for (int i=1; i<=n; i++) {
            cout << a[i] << b[i] << '|' << c[i] << d[i] << endl;
        }
    }
    else
        puts("NO");
    return 0;
}
