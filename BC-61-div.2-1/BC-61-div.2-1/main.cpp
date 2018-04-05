//
//  main.cpp
//  BC-61-div.2-1
//
//  Created by 袁子涵 on 15/10/31.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int n,a[105];
bool flag=0;

int comp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}

int main(int argc, const char * argv[]) {
    while (scanf("%d",&n)!=EOF) {
        memset(a, 0, sizeof(a));
        for (int i=0; i<n; i++) {
            scanf("%d",&a[i]);
        }
        flag=0;
        qsort(a, n, sizeof(int), comp);
        for (int i=n-1; i>=2; i--) {
            for (int j=i-1; j>=1; j--) {
                for (int k=j-1; k>=0; k--) {
                    if (a[i]==a[j]+a[k]) {
                        flag=1;
                        break;
                    }
                }
                if (flag) {
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        if (flag) {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}
