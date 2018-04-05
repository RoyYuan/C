//
//  main.cpp
//  160910-5
//
//  Created by 袁子涵 on 16/9/10.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <utility>

using namespace std;
long long mult_mod(long long a,long long b,long long c) {
    a %= c;
    b %= c;
    long long ret = 0;
    long long tmp = a;
    ￼while(b) {
        if(b & 1) {
            ret += tmp;
            if(ret > c)ret -= c;//直接取模慢很多
        }
            tmp <<= 1;
            if(tmp > c)tmp -= c; b >>= 1;
        }
        return ret;
}
long long pow_mod(long long a,long long n,long long mod) {
    long long ret = 1;
    long long temp = a%mod; while(n)
    {
        if(n & 1)
            ret = mult_mod(ret,temp,mod);
        temp = mult_mod(temp,temp,mod);
        n >>= 1;
    }
    return ret; }
long long inv(long long a,long long mod)//mod为素数
{
    return pow_m(a,mod-2,mod);
}
int main(int argc, const char * argv[]) {
    
    return 0;
}
