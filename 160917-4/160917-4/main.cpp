//
//  main.cpp
//  160917-4
//
//  Created by 袁子涵 on 16/9/17.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <utility>
#include <map>

using namespace std;
const int maxn=100005;
long long int t,n,m,a[maxn],du[maxn],total,ans,tmp;
int main(int argc, const char * argv[]) {
    long long int u,v,x,y;
    scanf("%lld",&t);
    while (t--) {
        total=ans=tmp=x=y=0;
        memset(du, 0, sizeof(du));
        scanf("%lld%lld",&n,&m);
        for (long long int i=1; i<=n; i++)
            scanf("%lld",&a[i]);
        for (long long int i=1; i<=m; i++) {
            scanf("%lld%lld",&u,&v);
            du[u]++,du[v]++;
        }
        for (long long int i=1; i<=n; i++) {
            if (du[i]&1)
            {
                if (x) {
                    y=i;
                }
                else
                    x=i;
                continue;
            }
            total++;
        }
        if (total==n) {
            bool flag=0;
            for (long long int i=1; i<=n; i++) {
                if (du[i]%4) {
                    tmp^=a[i];
                }
                else
                {
                    flag=1;
                }
            }
            if (flag) {
                printf("%lld\n",tmp);
            }
            else
            {
                for (long long int i=1; i<=n; i++) {
                    ans=max(ans,tmp^a[i]);
                }
                printf("%lld\n",ans);
            }
        }
        else if (total==n-2)
        {
            for (long long int i=1; i<=n; i++) {
                if (du[i]%4) {
                    ans^=a[i];
                }
            }
            printf("%lld\n",ans);
        }
        else
        {
            printf("Impossible\n");
        }
    }
    return 0;
}
