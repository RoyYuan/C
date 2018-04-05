//
//  main.cpp
//  BestCoder-Round 62.2-2
//
//  Created by 袁子涵 on 15/11/14.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <stdlib.h>


int T;
double x[5],y[5];
double dis[5][5];
bool flag=0;

double dist(double x1,double y1,double x2,double y2)
{
    double dis;
    dis=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    return dis;
}

int cmp( const void *a , const void *b )
{
    return *(double *)a > *(double *)b ? 1 : -1;
}

int main(int argc, const char * argv[]) {
    std::cin >> T;
    while (T--) {
        flag=1;
        memset(dis, 0, sizeof(dis));
        for (int i=0; i<5; i++) {
            std::cin >> x[i] >> y[i];
        }
        for (int i=0; i<5; i++) {
            for (int j=i+1; j<5; j++) {
                dis[i][j]=dis[j][i]=dist(x[i],y[i],x[j],y[j]);
            }
        }
        for (int i=0; i<5; i++) {
            qsort(&dis[i], 5, sizeof(double), cmp);
            if (fabs(dis[i][1]-dis[i][2])>0.0001 || fabs(dis[i][3]-dis[i][4])>0.0001) {
                flag=0;
                break;
            }
        }
        if (flag) {
            printf("Yes\n");
        }
        else
            printf("No\n");
    }
    return 0;
}
