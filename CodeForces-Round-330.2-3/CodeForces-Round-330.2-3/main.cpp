//
//  main.cpp
//  CodeForces-Round-330.2-3
//
//  Created by 袁子涵 on 15/11/9.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

long long int num[200005],dis[200005];

int main(int argc, const char * argv[]) {
    long long int n;
    cin >> n;
    for (long long int i=0; i<n; i++) {
        scanf("%lld",&num[i]);
    }
    sort(num+0, num+n);
    dis[0]=num[1]-num[0];
    dis[n-1]=num[n-1]-num[n-2];
    for (long long int i=1; i<n-1; i++) {
        dis[i]=min(num[i]-num[i-1],num[i+1]-num[i]);
    }
    for (long long int i=1; i<n-2; i++) {
        if (i%2) {
            long long int q=0,x=0;
            for (long long int i=0; i<n; i++) {
                if (dis[i]>=x) {
                    x=dis[i];
                    q=i;
                }
            }
            dis[q]=-1;
        }
    }
    return 0;
}
