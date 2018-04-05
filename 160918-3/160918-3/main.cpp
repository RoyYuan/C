//
//  main.cpp
//  160918-3
//
//  Created by 袁子涵 on 16/9/18.
//  Copyright :copyright: 2016年 袁子涵. All rights reserved.
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
long long int n,y,x,s;
long long int mod;
long long int q_pow(long long int a,long long int b,long long int mod)
{
    long long int ret = 1;
    while (b) {
        if (b&1)
            ret=ret*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ret;
}
long long int eular(long long int num)
{
    long long int ans=num;
    for (long long int i=2; i*i<=num; i++) {
        if (num%i==0) {
            ans-=ans/i;
            while (num%i==0)
                num/=i;
        }
    }
    if (num>1)
        ans-=ans/num;
    return ans;
}

struct matrix{
    long long mm[6][6];
    matrix(){
        memset(mm, 0, sizeof(mm));
    }
};
matrix mul(matrix a, matrix b){
    matrix c;
    for(int i = 0; i < 6; i ++){
        for(int j = 0; j < 6; j ++){
            for(int k = 0; k < 6; k ++){
                c.mm[i][j] += (a.mm[i][k] * b.mm[k][j]) % mod;
            }
            c.mm[i][j] %= mod;
        }
    }
    return c;
}

long long poww(matrix x, long long t){
    long long ans = 0;
    matrix res;
    res.mm[0][0] = res.mm[1][1] = res.mm[2][2] = res.mm[3][3] = res.mm[4][4] = res.mm[5][5] =1;
    for(; t; t >>= 1){
        if(t & 1)
            res = mul(res, x);
        x = mul(x, x);
    }
    ans += res.mm[5][0] % mod;
    ans += res.mm[5][2] % mod;
    ans += res.mm[5][5] % mod;
    return ans % mod;
}

long long getG(long long n){
    matrix base;
    int a=2,b=1;
    a %= mod, b %= mod;
    base.mm[0][0] = base.mm[5][0] = a*a%mod;
    base.mm[0][1] = base.mm[5][1] = 2*a*b%mod;
    base.mm[0][4] = base.mm[5][4] = b*b%mod;
    base.mm[1][0] = a ;
    base.mm[1][1] = b;
    base.mm[2][2] = a ;
    base.mm[2][3] = b;
    base.mm[3][2] = base.mm[4][0] = 1;
    base.mm[5][5] = 1;
    return poww(base, n);
}
int main(int argc, const char * argv[]) {
    int t;
    long long int out,fm;
    scanf("%d",&t);
    while (t--) {
        scanf("%lld%lld%lld%lld",&n,&y,&x,&s);
        mod=eular(s+1);
        fm=getG(y*n-1);
        out=q_pow(x, fm, s+1);
        printf("%lld\n",out);
    }
    return 0;
}