//
//  main.cpp
//  160726-3
//
//  Created by 袁子涵 on 16/7/26.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;
int a,v1,v2;
double out;
int main(int argc, const char * argv[]) {
    while (cin >> a >> v1 >> v2) {
        if (a==0) {
            cout << 0 << endl;
        }
        else if (v1<=v2 || v1==0)
        {
            cout << "Infinity" << endl;
        }
        else
        {
            out=a*v1;
            out/=(double)(v1*v1-v2*v2);
            printf("%f\n",out);
        }
    }
    return 0;
}
