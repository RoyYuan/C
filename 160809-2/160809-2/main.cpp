//
//  main.cpp
//  160809-2
//
//  Created by 袁子涵 on 16/8/9.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
const int maxm=1e5+5;
const int mod=1e9+7;
int out[maxm],num[maxm];
void init()
{
    for (int i=1; i<=5*1e4; i++) {
        num[i*2-1]=i*(3*i-1)/2;
        num[i*2]=i*(3*i+1)/2;
    }
    out[0]=1;
    for (int i=1; i<=1e5; i++) {
        for (int j=1; num[j]<=i; j++) {
            if (((j+1)/2)&1)
                out[i]=(out[i]+out[i-num[j]])%mod;
            else
                out[i]=(out[i]-out[i-num[j]]+mod)%mod;
        }
    }
}
int main(int argc, const char * argv[]) {
    int t,n,k;
    scanf("%d",&t);
    init();
    while (t--) {
        scanf("%d%d",&n,&k);
        int tmp=0;
        for (int i=0; num[i]*k<=n; i++) {
            if ((i+1)/2&1)
                tmp=(tmp-out[n-num[i]*k]+mod)%mod;
            else
                tmp=(tmp+out[n-num[i]*k])%mod;
        }
        printf("%d\n",tmp);
    }
    return 0;
}
