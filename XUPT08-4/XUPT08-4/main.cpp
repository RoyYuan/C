//
//  main.cpp
//  XUPT08-4
//
//  Created by 袁子涵 on 16/9/22.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>
#include <map>

using namespace std;
const int maxn=2e5+5;
map<long long int,long long int>M;
long long int l[maxn],r[maxn];
long long quickmod(long long a,long long b,long long m)
{
    long long ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*a)%m;
            b--;
        }
        b>>=1;
        a=a*a%m;
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    long long int mod=1e9+7;
    long long int mm=1e9+6,ans=1;
    long long int m,tmp,total;
    scanf("%lld",&m);
    for (int i=0; i<m; i++) {
        scanf("%lld",&tmp);
        M[tmp]++;
    }
    total=M.size();
    map<long long int,long long int>::iterator it=M.begin();
    l[0]=1;
    r[total+1]=1;
    for (long long int i=1; it!=M.end(); it++,i++)
        l[i]=(l[i-1]*(it->second+1))%mm;
    it=M.end();
    for (long long int i=total; i>0; i--)
    {
        it--;
        r[i]=(r[i+1]*(it->second+1))%mm;
    }
    for (long long int i=1; it!=M.end(); it++,i++) {
        long long int now=it->first;
        long long int times=it->second;
        long long int tt=(l[i-1]*1llu*r[i+1])%mm;
        tt=(tt*(((1+times)*times/2)%mm))%mm;
        ans=(ans*quickmod(now,tt,mod))%mod;
    }
    cout << ans << endl;
    return 0;
}
