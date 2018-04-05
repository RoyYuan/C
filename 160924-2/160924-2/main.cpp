//
//  main.cpp
//  160924-2
//
//  Created by 袁子涵 on 16/9/24.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <utility>
#include <complex>

using namespace std;
const int maxn=5e5+5;
long long int n,m,k,out;
long long int num[maxn],tmp[maxn];
bool check(int l,int r)
{
    if (r>n) {
        r=n;
    }
    long long int total=0;
    for (int i=l; i<=r; i++) {
        tmp[i-l+1]=num[i];
    }
    sort(tmp+1, tmp-l+r+2);
    for (int i=1; 2*i<r-l+2 && i<=m; i++) {
        total+=(tmp[r-l+2-i]-tmp[i])*(tmp[r-l+2-i]-tmp[i]);
    }
    if (total<=k) {
        return 1;
    }
    else
        return 0;
}
int main(int argc, const char * argv[]) {
    int t,z;
    scanf("%d",&t);
    while (t--) {
        out=0;
        scanf("%lld%lld%lld",&n,&m,&k);
        for (int i=1; i<=n; i++) {
            scanf("%lld",&num[i]);
        }
        for (int i=1; i<=n; i+=z) {
            out++;
            for (int j=2; j<=n-i+1 && check(i, i+j-1); j<<=1) {
                for (j>>=1,z=0; j>0; j>>=1) {
                    if (check(i,i+j+z-1)) {
                        z+=j;
                    }
                }
            }
        }
        cout << out << endl;
    }
    return 0;
}