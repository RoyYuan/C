//
//  main.cpp
//  160807-4
//
//  Created by 袁子涵 on 16/8/7.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=20005;
int t,n,price[maxn];
long long int out;
int main(int argc, const char * argv[]) {
    scanf("%d",&t);
    while (t--) {
        out=0;
        scanf("%d",&n);
        for (int i=1; i<=n; i++) {
            scanf("%d",&price[i]);
        }
        sort(price+1,price+1+n);
        for (int i=n-2; i>=1; i-=3) {
            out+=price[i];
        }
        printf("%lld\n",out);
    }
    return 0;
}
