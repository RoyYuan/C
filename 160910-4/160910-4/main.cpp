//
//  main.cpp
//  160910-4
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
long long int m,n;
int main(int argc,const char * argv[]) {
    while (scanf("%lld%lld",&m,&n)!=EOF) {
        long long int out=ceil((double)m/2)*floor((double)m/2);
        if (out>n)
            printf("F\n");
        else
            printf("T\n");
    }
    return 0;
}
