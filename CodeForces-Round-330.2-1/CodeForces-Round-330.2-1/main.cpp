//
//  main.cpp
//  CodeForces-Round-330.2-1
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

int main(int argc, const char * argv[]) {
    int n,m,a,b;
    long long int sum=0;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d%d",&a,&b);
            if (a+b) {
                sum++;
            }
        }
    }
    cout << sum << endl;
    return 0;
}
