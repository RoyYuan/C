//
//  main.cpp
//  长大15acm-A
//
//  Created by 袁子涵 on 15/12/7.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(int argc, const char * argv[]) {
    long long int t,n;
    cin >> t;
    while (t--) {
        cin >> n;
        long long int tmp=1,total=0;
        while (tmp<=n)
            tmp*=2;
        while (n) {
            while (n<tmp)
                tmp/=2;
            n-=tmp;
            total++;
        }
        cout << total << endl;
    }
    return 0;
}
