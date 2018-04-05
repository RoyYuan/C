//
//  main.cpp
//  160805-2
//
//  Created by ??? on 16/8/5.
//  Copyright © 2016? ???. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=20005;
int t,n,m,out,total[maxn],tree[maxn];
int main(int argc, const char * argv[]) {
    scanf("%d",&t);
    int cas=0,u,v;
    while (t--) {
        memset(total, 0, sizeof(total));
        memset(tree, 0, sizeof(tree));
        out=INF;
        scanf("%d%d",&n,&m);
        for (int i=1; i<n; i++) {
            scanf("%d%d",&u,&v);
            total[u]++,total[v]++,tree[u]++,tree[v]++;
        }
        for (int i=n; i<=m; i++) {
            scanf("%d%d",&u,&v);
            total[u]++,total[v]++;
        }
        for (int i=1; i<=n; i++)
            if (tree[i]==1)
                out=min(out,total[i]);
        printf("Case #%d: %d\n",++cas,out);
    }
    return 0;
}