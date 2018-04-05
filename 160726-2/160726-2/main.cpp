//
//  main.cpp
//  160726-2
//
//  Created by 袁子涵 on 16/7/26.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;
double out=0;
int n,tmp;
int main(void) {
    while (cin >> n) {
        out=0;
        if (n==0) {
            cout << 0 << endl;
            continue;
        }
        if (n==1) {
            cin >> tmp;
            cout << tmp << endl;
            continue;
        }
        else
        {
            cin >> tmp;
            out+=(double)tmp*0.5;
            for (int i=2; i<n; i++) {
                cin >> tmp;
                out+=(double)tmp*(1.0/3);
            }
            cin >> tmp;
            out+=(double)tmp*0.5;
            printf("%f\n",out);
        }
    }
    return 0;
}
