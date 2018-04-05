//
//  main.cpp
//  24-2
//
//  Created by 袁子涵 on 16/4/24.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
long long int now,plz,n,out,num[310],candy[310];
bool vis[310];
int main(int argc, const char * argv[]) {
    while (cin >> n) {
        for (int i=0; i<n; i++)
            cin >> num[i];
        now=10005;
        memset(candy, 0, sizeof(candy));
        memset(vis, 0, sizeof(vis));
        for (int i=0; i<n; i++) {
            now=10005;
            for (int j=0; j<n; j++) {
                if (now>num[j] && vis[j]==0) {
                    now=num[j];
                    plz=j;
                }
            }
            vis[plz]=1;
            if (plz>0) {
                if (vis[plz-1]) {
                    candy[plz]=max(candy[plz],candy[plz-1]+1);
                }
                else
                    candy[plz]=max(candy[plz],(long long)1);
            }
            if (plz<n-1) {
                if (vis[plz+1]) {
                    candy[plz]=max(candy[plz],candy[plz+1]+1);
                }
                else
                    candy[plz]=max(candy[plz],(long long)1);
            }
        }
        out=0;
        for (int i=0; i<n; i++) {
            out+=candy[i];
        }
        cout << out << endl;
    }
    return 0;
}
