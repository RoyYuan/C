//
//  main.cpp
//  RE1
//
//  Created by 袁子涵 on 17/7/18.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <map>
using namespace::std;
map<long long int,int> NUM;
const int maxn=1e5+5;
int n,k,total,a;
long long int list[60],sum[maxn],ans;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> a;
        sum[i]=sum[i-1]+a;
    }
    if (k==1 || k==-1)
        for (int i=0; i<n; i++) {
            if (k==-1)
                NUM[sum[i]-1]++;
            NUM[sum[i]+1]++;
            ans+=NUM[sum[i+1]];
        }
    else
    {
        long long int now=1;
        while (abs(now)<=1e15) {
            list[++total]=now;
            now*=k;
        }
        for (int i=0; i<n; i++) {
            for (int j=1; j<=total; j++)
                NUM[sum[i]+list[j]]++;
            ans+=NUM[sum[i+1]];
        }
    }
    cout << ans << endl;
    return 0;
}
