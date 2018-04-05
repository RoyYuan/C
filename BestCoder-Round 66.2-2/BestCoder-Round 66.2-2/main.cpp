//
//  main.cpp
//  BestCoder-Round 66.2-2
//
//  Created by 袁子涵 on 15/12/12.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#define MAXN 50005
using namespace std;
long long int n,m;
bool vis[MAXN];
long long int times[MAXN];
long long int group[MAXN],b[MAXN];
int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        long long int out=0,c;
        memset(b, 0, sizeof(b));
        memset(vis, 0, sizeof(vis));
        memset(group, 0, sizeof(group));
        memset(times, 0, sizeof(times));
        for (long long int i=1; i<=n; i++) {
            scanf("%lld%lld",&group[i],&b[i]);
            
        }
        for (long long int i=1; i<=m; i++) {
            scanf("%lld",&c);
            times[c]++;
        }
        for (long long int i=1; i<=n; i++) {
            for (long long int j=i-1; j>=1; j--) {
                if (group[j]!=group[i] && b[j]<b[i]) {
                    vis[j]=1;
                }
            }
            if (times[i]>0) {
                for (long long int j=1; j<=i; j++) {
                    b[j]+=times[i];
                }
            }
        }
        for (long long int i=1; i<=n; i++) {
            if (vis[i]!=0) {
                continue;
            }
            out++;
        }
        cout << out << endl;
    }
    return 0;
}
