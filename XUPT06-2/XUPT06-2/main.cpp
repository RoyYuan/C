//
//  main.cpp
//  XUPT06-2
//
//  Created by 袁子涵 on 16/9/14.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <utility>
#include <map>

using namespace std;
#define ll long long int
const int maxn=100005;
ll n,k,tmp;
ll c[maxn],all;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    ll ans=0;
    for (ll i=1; i<=n; i++) {
        cin >> c[i];
        all+=c[i];
    }
    for (ll i=1; i<=k; i++) {
        cin >> tmp;
        all-=c[tmp];
        ans+=c[tmp]*all;
        c[tmp]=0;
    }
    for (ll i=2; i<=n; i++)
        ans+=c[i]*c[i-1];
    ans+=c[1]*c[n];
    cout << ans << endl;
    return 0;
}
