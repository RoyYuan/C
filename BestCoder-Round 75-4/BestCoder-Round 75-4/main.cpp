//
//  main.cpp
//  BestCoder-Round 75-4
//
//  Created by 袁子涵 on 16/3/12.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace::std;
int T,n,k;
int day[205],mx;
bool flag;
int m,p,q;
int s[6],t[6];
long long int out;
int main(int argc, const char * argv[]) {
    cin >> T;
    while (T--) {
        cin >> n >> k;
        flag=1;
        mx=out=0;
        for (int i=1; i<=n; i++)
        {
            cin >> day[i];
            mx=max(day[i],mx);
        }
        cin >> m >> p >> q;
        for (int i=1; i<=m; i++)
            cin >> s[i] >> t[i];
        for (int i=1; i<p; i++) {
            if (day[i]>k) {
                flag=0;
                break;
            }
        }
        if (flag==0) {
            cout << "No solution" <<endl;
            continue;
        }
        if (mx>k) {
            out+=mx-k;
        }
        
    }
    return 0;
}
