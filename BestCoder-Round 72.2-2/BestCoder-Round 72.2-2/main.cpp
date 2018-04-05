//
//  main.cpp
//  BestCoder-Round 72.2-2
//
//  Created by 袁子涵 on 16/2/13.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAXN 1000005
using namespace std;

int t;
long long int maxn=0;
long long int n,seed;
long long int x[MAXN],y[MAXN],node[MAXN];
inline long long rand(long long l, long long r) {
    static long long mo=1e9+7, g=78125;
    return l+((seed*=g)%=mo)%(r-l+1);
}

int main(int argc, const char * argv[]) {
    cin >> t;
    while (t--) {
        maxn=0;
        cin >> n >> seed;
        for (long long int i=0; i<n; i++) {
            x[i] = rand(-1000000000, 1000000000);
            y[i] = rand(-1000000000, 1000000000);
        }
        for (long long int i=0; i<n; i++) {
            node[i]=x[i]+y[i];
        }
        sort(node+0,node+n);
        maxn=max(maxn,node[n-1]-node[0]);
        for (long long int i=0; i<n; i++) {
            node[i]=x[i]-y[i];
        }
        sort(node+0,node+n);
        maxn=max(maxn,node[n-1]-node[0]);
        for (long long int i=0; i<n; i++) {
            node[i]=-x[i]-y[i];
        }
        sort(node+0,node+n);
        maxn=max(maxn,node[n-1]-node[0]);
        for (long long int i=0; i<n; i++) {
            node[i]=-x[i]+y[i];
        }
        sort(node+0,node+n);
        maxn=max(maxn,node[n-1]-node[0]);
        cout << maxn << endl;
    }
    return 0;
}
