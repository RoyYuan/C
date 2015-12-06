//
//  main.cpp
//  BestCoder-Round 65-3
//
//  Created by 袁子涵 on 15/12/5.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>


using namespace std;
long long int n,x[50005];
long long int num[50005],a[50005];
bool vis[50005];

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        memset(num, -1, sizeof(num));
        memset(a, 0, sizeof(a));
        memset(vis, 0, sizeof(vis));
        memset(x, 0, sizeof(x));
        for (long long int i=1; i<=n; i++) {
            scanf("%lld",&a[i]);
        }
        for (long long int i=n; i>=1; i--) {
            a[i]=a[i]-a[i-1];
            num[i]=n-a[i]-x[a[i]];
            for (long long int j=1; j<=a[i]; j++) {
                x[a[i]]++;
            }
        }
        for (long long int i=n; i>=1; i--) {
            if (vis[num[i]]) {
                while (vis[num[i]]) {
                    num[i]--;
                }
                vis[num[i]]=1;
            }
            else
                vis[num[i]]=1;
        }
        for (long long int i=1; i<=n; i++) {
            printf("%lld ",num[i]);
        }
        printf("\n");
    }
    return 0;
}
