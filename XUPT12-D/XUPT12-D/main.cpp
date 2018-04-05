//
//  main.cpp
//  XUPT12-D
//
//  Created by 袁子涵 on 16/10/19.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;
const int maxn=200005;
int n,a[maxn];
long long int total[maxn*2];
long long int num[maxn];
bool vis[maxn];
int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    int inf=0;
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
        inf=max(inf,a[i]);
        num[a[i]]++;
    }
    for (int i=inf; i>0; i--)
        total[i]=(long long int)total[i+1]+(long long int)num[i];
    long long int ans=0;
    for (int i=1; i<=n; i++) {
        int now=a[i];
        if (vis[a[i]])  continue;
        long long int tmp=0;
        while (now<=inf) {
            vis[now]=1;
            tmp+=(total[now]-total[now+a[i]])*now;
            now+=a[i];
        }
        ans=max(tmp,ans);
    }
    printf("%lld\n",ans);
    return 0;
}