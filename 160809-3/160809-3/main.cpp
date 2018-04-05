//
//  main.cpp
//  160809-3
//
//  Created by 袁子涵 on 16/8/9.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
const int mod=100;
int pow(int a,unsigned long long int b)
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
    int t,cas;
    while (scanf("%d",&t) && t!=0){
        cas=0;
        while (t--) {
            unsigned long long int n;
            scanf("%llu",&n);
            printf("Case %d: %d\n",++cas,(pow(4, n-1)+pow(2, n-1)+100)%mod);
        }
        puts("");
    }
    return 0;
}
