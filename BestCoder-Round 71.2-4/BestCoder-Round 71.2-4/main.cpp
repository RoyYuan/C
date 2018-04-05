//
//  main.cpp
//  BestCoder-Round 71.2-4
//
//  Created by 袁子涵 on 16/2/6.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int n, a[50005], f[50005];
int t;

int main(int argc, const char * argv[]){
    cin >> t;
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a+0, a+n);
        for (int i=0; i < n; ++i)
            f[i] = max(a[i] - f[i - 1], f[i - 1]);
        printf("%d\n", f[n-1]);
    }
    
    return 0;
}