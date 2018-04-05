//
//  main.cpp
//  160910-2
//
//  Created by 袁子涵 on 16/9/10.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <utility>

using namespace std;
long long int m,b,sc,ma;
bool ff;
long long int total;
int main(int argc, const char * argv[]) {
    while (scanf("%lld",&m)!=EOF) {
        for (long long int i=1; i<=m; i++) {
            scanf("%lld",&b);
            total=0;
            ff=1;
            ma=2*(b-1);
            for (int i=1; i<=b; i++) {
                scanf("%lld",&sc);
                total+=sc;
                if (sc>ma)
                    ff=0;
            }
            if (total!=b*(b-1)) {
                printf("F\n");
                continue;
            }
            if (!ff) {
                printf("F\n");
                continue;
            }
            printf("T\n");
        }
    }
    return 0;
}
