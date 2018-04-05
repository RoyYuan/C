//
//  main.cpp
//  RE-2-2
//
//  Created by 袁子涵 on 17/7/28.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
using namespace std;
const double INF=0x7fffffffffffffff;
const int maxn=1e5+5;
const double eps=1e-5;
int n,p,tmp1,tmp2,a[maxn],b[maxn];
long long int A;
double l=0,r=INF,mid,tmp,c;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> n >> p;
    for (int i=0; i<n; i++)
    {
        cin >> a[i] >> b[i];
        A+=a[i];
    }
    if (p>=A) {
        cout << -1 << endl;
        return 0;
    }
    while (r-l>=eps) {
        mid=(r+l)/2.0;
        tmp=p*mid;
        for (int i=0; i<n; i++) {
            c=b[i]-a[i]*mid;
            if (c<0)
                tmp+=c;
            if (tmp<0)
                break;
        }
        if (tmp>0)
            l=mid;
        else if (tmp<0)
            r=mid;
        else
            break;
    }
    cout << mid << endl;
    return 0;
}
