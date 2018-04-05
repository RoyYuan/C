//
//  main.cpp
//  BC-86-3
//
//  Created by 袁子涵 on 16/8/6.
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
#include <queue>
#include <stack>
#include <map>

using namespace std;

long long int a[200005],V[200005],total;
int main(int argc, const char * argv[]) {
    long long int t,n,m,k,out;
    scanf("%lld",&t);
    while (t--) {
        memset(V, 0, sizeof(V));
        V[0]=0;
        total=0;
        out=0;
        scanf("%lld%lld%lld",&n,&m,&k);
        for (long long int i=1; i<=n; i++)
        {
            scanf("%lld",&a[i]);
            if (a[i]>=m)
                V[++total]=i;
        }
        for (long long int i=1; i<=total-k+1; i++)
            out+=(V[i]-V[i-1])*(n-V[i+k-1]+1);
        printf("%lld\n",out);
    }
    return 0;
}
