//
//  main.cpp
//  长大15acm-B
//
//  Created by 袁子涵 on 15/12/7.
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
    long long int t;
    cin >> t;
    while (t--) {
        long long int n,m;
        cin >> n >> m;
        if (n%(m+1)==0)
            cout << "Bob" << endl;
        else
            cout << "Alex" << endl;
    }
    return 0;
}
