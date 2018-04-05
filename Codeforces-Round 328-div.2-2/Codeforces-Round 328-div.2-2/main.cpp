//
//  main.cpp
//  Codeforces-Round 328-div.2-2
//
//  Created by 袁子涵 on 15/11/1.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

unsigned long int n;

int main(int argc, const char * argv[]) {
    cin >> n;
    if (n<3) {
        cout << "0" << endl;
        return 0;
    }
    n=(n-2)*(n-2);
    cout << n << endl;
    return 0;
}
