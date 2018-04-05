//
//  main.cpp
//  160807-1
//
//  Created by 袁子涵 on 16/8/7.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;
int num[200005];
int main(int argc, const char * argv[]) {
    int n;
    while (scanf("%d",&n)!=EOF && n!=0) {
        int sum=0;
        for (int i=1; i<=n; i++) {
            scanf("%d",&num[i]);
            sum^=num[i];
        }
        if (sum==0) {
            puts("No");
            continue;
        }
        else
            puts("Yes");
        for (int i=1; i<=n; i++) {
            sum^=num[i];
            if (num[i]>=sum)
                printf("%d %d\n",num[i],sum);
            sum^=num[i];
        }
    }
    return 0;
}
