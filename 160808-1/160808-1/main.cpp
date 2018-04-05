//
//  main.cpp
//  160808-1
//
//  Created by 袁子涵 on 16/8/8.
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
#include <utility>
using namespace::std;

int main(int argc, const char * argv[]) {
    int m,f,mi,tmp,cas=0;
    while (~scanf("%d%d",&m,&f) && (m!=0 || f!=0)) {
        cas++;
        mi=10000;
        for (int i=1; i<=m; i++) {
            scanf("%d",&tmp);
            mi=min(mi,tmp);
        }
        for (int i=1; i<=f; i++)
            scanf("%d",&tmp);
        if (m<=f)
            printf("Case %d: 0\n",cas);
        else
            printf("Case %d: %d %d\n",cas,m-f,mi);
    }
    return 0;
}
