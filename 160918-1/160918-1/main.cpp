//
//  main.cpp
//  160918-1
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
const int maxn=305;
long long int t,n;
long long int value[maxn],key[maxn];
long long int gcd(long long int a,long long int b)
{
    long long int c;
    while (a>0) {
        c=b%a;
        b=a;
        a=c;
    }
    return b;
}
long long int l[maxn][maxn],ans[maxn];
int main(int argc, const char * argv[]) {
    scanf("%lld",&t);
    while (t--) {
        scanf("%lld",&n);
        memset(l, -1, sizeof(l));
        memset(ans, 0, sizeof(ans));
        for (long long int i=1; i<=n; i++)
            scanf("%lld",&key[i]);
        for (long long int i=1; i<=n; i++)
            scanf("%lld",&value[i]);
        for (int i=2; i<=n; i++) {
            if (gcd(key[i-1], key[i])!=1) {
                l[i-1][i]=value[i-1]+value[i];
            }
        }
        for (int size=4; size<=n; size+=2) {
            for (int i=1; i+size<=n+1; i++) {
                for (int j=i+2; j<i+size; j+=2) {
                    if (l[i][j-1]!=-1 && l[j][i+size-1]!=-1) {
                        l[i][i+size-1]=max(l[i][i+size-1],l[i][j-1]+l[j][i+size-1]);
                    }
                }
                if (l[i+1][i+size-2]!=-1 && gcd(key[i], key[i+size-1])!=1) {
                    l[i][i+size-1]=max(l[i][i+size-1],l[i+1][i+size-2]+value[i]+value[i+size-1]);
                }
            }
        }
        for (int i=1; i<=n; i++) {
            ans[i]=max(ans[i],l[1][i]);
            for (int j=1; j<i; j++) {
                ans[i]=max(ans[i],ans[j]);
                ans[i]=max(ans[i],ans[j]+l[j+1][i]);
            }
        }
        printf("%lld\n",ans[n]);
    }
    return 0;
}
