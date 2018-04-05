//
//  main.cpp
//  XUPT06-3
//
//  Created by 袁子涵 on 16/9/14.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <utility>
#include <map>

using namespace std;
long long int n,w,v,u;
int main(int argc, const char * argv[]) {
    long long int x,y;
    double ans=0;
    bool flag1=1,flag2=1;
    scanf("%lld%lld%lld%lld",&n,&w,&v,&u);
    for (long long int i=1; i<=n; i++) {
        scanf("%lld%lld",&x,&y);
        if ((double)x/(double)v>(double)y/(double)u)
            flag1=0;
        if ((double)x/(double)v<(double)y/(double)u)
            flag2=0;
        ans=max(ans,(double)x/(double)v+(double)(w-y)/(double)u);
    }
    if (flag1 || flag2)
        printf("%.8lf\n",(double)((double)w/(double)u));
    else
        printf("%.8lf\n",ans);
    return 0;
}