//
//  main.cpp
//  160811-1
//
//  Created by 袁子涵 on 16/8/11.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <utility>

using namespace::std;
const int maxn=130005;
int num[maxn];
int main(int argc, const char * argv[]) {
    int n,m,l,r;
    scanf("%d%d",&n,&m);
    for (int i=1; i<=n; i++)
        num[i]=i;
    for (int i=1; i<=m; i++) {
        scanf("%d%d",&l,&r);
        for (int x=l,y=r; x<y; x++,y--)
            swap(num[x], num[y]);
    }
    for (int i=1; i<=n; i++)
        printf("%d ",num[i]);
    puts("");
    return 0;
}
