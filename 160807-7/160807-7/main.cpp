//
//  main.cpp
//  160807-7
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
#include <map>
#include <vector>
#include <utility>

using namespace::std;
int main(int argc, const char * argv[]) {
    int r,a,b,cas=0;
    while (~scanf("%d",&r) && r!=0) {
        scanf("%d%d",&a,&b);
        cas++;
        if (4*r*r>=a*a+b*b)
            printf("Pizza %d fits on the table.\n",cas);
        else
            printf("Pizza %d does not fit on the table.\n",cas);
    }
    return 0;
}
