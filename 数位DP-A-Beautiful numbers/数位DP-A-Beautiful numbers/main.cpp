//
//  main.cpp
//  数位DP-A-Beautiful numbers
//
//  Created by 袁子涵 on 15/10/28.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;
long long int l,r,sum;

void DP(long long int l,long long int r)
{
    
}

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        sum=0;
        cin >> l >> r;
        DP(l,r);
    }
    return 0;
}
