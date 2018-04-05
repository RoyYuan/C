//
//  main.cpp
//  160917-6
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
int main(int argc, const char * argv[]) {
    long long int l,r;
    while (scanf("%lld%lld",&l,&r)!=EOF) {
        if (l==r && (l==0 || l==1)) {
            printf("0\n");
        }
        else if (l==r && l==2)
        {
            printf("1\n");
        }
        else if (l==0 && r==1)
        {
            printf("0\n");
        }
        else if (l==1 && r==2)
    }
    return 0;
}