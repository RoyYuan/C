//
//  main.cpp
//  160809-4
//
//  Created by 袁子涵 on 16/8/9.
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
#include <map>

using namespace std;
const int mod=10007;
int pow(int a,int b)
{
    int out=1;
    while (b) {
        if (b&1)
            out=out*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return out;
}
int main(int argc, const char * argv[]) {
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        printf("%d\n",(pow(4, n-1)+pow(2,n-1))%mod);
    }
    return 0;
}
