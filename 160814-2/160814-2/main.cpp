//
//  main.cpp
//  160814-2
//
//  Created by 袁子涵 on 16/8/14.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <set>

using namespace std;
int num[11],t,n,cas,limit,total,now;
int main(int argc, const char * argv[]) {
    scanf("%d",&t);
    while (t--) {
        total=now=0;
        scanf("%d",&n);
        for (int i=1; i<=n; i++)
        {
            scanf("%d",&num[i]);
            now+=num[i];
        }
        limit=now/2;
        for (int i=1; i<n; i++) {
            if (num[i]==0)
                continue;
            for (int j=i+1; j<=n; j++) {
                while (num[i] && num[j] && total<limit) {
                    num[i]--,num[j]--;
                    total+=2;
                }
                if (total>limit) {
                    total--;
                }
            }
        }
        printf("Case #%d: %d\n",++cas,total);
    }
    return 0;
}
