//
//  main.cpp
//  160918-2
//
//  Created by 袁子涵 on 16/9/18.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <utility>
#include <map>
#include <string>

using namespace std;
#define C(a,b) ((f1[(a)]*f[(b)]%mod)*f[(a)-(b)]%mod)
const int mod=1e9+7;
const int maxn=1e6+5;
long long int f[maxn],f1[maxn],f2[maxn],t,n,m,k,ans;
int main(int argc, const char * argv[]) {
    scanf("%lld",&t);
    f[1]=f1[1]=f2[1]=1;
    for (long long int i=2; i<maxn; i++)
    {
        f1[i]=f1[i-1]*i%mod;
        f2[i]=f2[mod%i]*(mod-mod/i)%mod;
        f[i]=f[i-1]*f2[i]%mod;
    }
    f[0]=f1[0]=1;
    while (t--) {
        scanf("%lld%lld%lld",&n,&m,&k);
        if (m==1) {
            printf("%lld\n",n);
            continue;
        }
        ans=0;
        for (long long int i=k; i<n-(k+1)*(m-1); i++)
            ans=(ans+C(n-i-k*(m-1),m-2)*(i+1)%mod)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
