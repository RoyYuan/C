//
//  main.cpp
//  Codeforces-Round-345.2-1
//
//  Created by 袁子涵 on 16/3/7.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
using namespace std;
int a1,a2;
long long int out,now;

int main(int argc, const char * argv[]) {
    cin >> a1 >> a2;
    out=0;
    if (a1<a2)
        swap(a1, a2);
    now=(a1-1)/2;
    while (a1>0 && a2>0) {
        a2+=now;
        a1-=now*2;
        out+=now;
        if (a1<a2)
            swap(a1, a2);
        now=(a1-1)/2;
        if (now==0) {
            if (a1==a2 && a1==1) {
                ;
            }
            else
            {
                out++;
            }
            break;
        }
    }
    cout << out << endl;
    return 0;
}
