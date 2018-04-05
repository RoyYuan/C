//
//  main.cpp
//  Codeforces Round #327 Div.2 1
//
//  Created by 袁子涵 on 15/10/25.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>

using namespace::std;

int l,p,q;

int main(int argc, const char * argv[]) {
    scanf("%d%d%d",&l,&p,&q);
    double t;
    t=(double)(l)/(double)(p+q);
    printf("%lf",t*(double)p);
    return 0;
}
