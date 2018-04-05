//
//  main.cpp
//  160807-8
//
//  Created by 袁子涵 on 16/8/7.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
int SG(int now,int N)
{
    double tmp=(double)(-1+sqrt(1+4*N))/2.0;
    int X=tmp;
    while (X*X+X>=N)
        X--;
    do X++; while(X*X+X<N);
    X--;
    if (now>X)
        return N-now;
    else
        return SG(now, X);
}
int main(int argc, const char * argv[]) {
    int n,total,s,c,cas=0;
    while (scanf("%d",&n)!=EOF && n!=0) {
        total=0;
        cas++;
        for (int i=1; i<=n; i++) {
            scanf("%d%d",&s,&c);
            total^=SG(c, s);
        }
        printf("Case %d:\n",cas);
        if (total) {
            puts("Yes");
        }
        else
            puts("No");
    }
    return 0;
}
