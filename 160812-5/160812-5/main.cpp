//
//  main.cpp
//  160812-5
//
//  Created by 袁子涵 on 16/8/12.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace::std;
const double eps=1e-6;
int x[2][305],y[2][305],n,total;
double d[1005];
int main(int argc, const char * argv[]) {
    while (scanf("%d",&n)!=EOF) {
        total=0;
        bool flag=1;
        for (int i=0; i<2; i++)
            for (int j=0; j<n; j++)
                scanf("%d%d",&x[i][j],&y[i][j]);
        for (int i=0; i<n; i++) {
            if (!flag)
                break;
            if ((!(x[0][i]*x[1][i]) && (x[0][i]||x[1][i])) || (!(y[0][i]*y[1][i]) && (y[0][i]||y[1][i]))) {
                flag=0;
                break;
            }
            if(x[0][i]&&x[1][i])
                d[total++]=(double)x[0][i]/x[1][i];
            if(y[0][i]&&y[1][i])
                d[total++]=(double)y[0][i]/y[1][i];
        }
        for (int i=0; i<total-1; i++) {
            if (fabs(d[i]-d[i+1])>eps) {
                flag=0;
                break;
            }
        }
        if (flag)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
