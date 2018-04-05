//
//  main.cpp
//  RE5
//
//  Created by 袁子涵 on 17/7/18.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;
map<int,int> Hole;
const int maxn=1e6+5;
int C[maxn];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int n,m,k,h,u,v;
    cin >> n >> m >> k;
    C[1]=1;
    for (int i=1; i<=m; i++) {
        cin >> h;
        Hole[h]=1;
    }
    if (Hole[1]) {
        cout << 1 << endl;
        return 0;
    }
    for (int i=1; i<=k; i++) {
        cin >> u >> v;
        swap(C[u], C[v]);
        if (C[u]) {
            if (Hole[u]) {
                cout << u << endl;
                return 0;
            }
        }
        if (C[v]) {
            if (Hole[v]) {
                cout << v << endl;
                return 0;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (C[i]) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
