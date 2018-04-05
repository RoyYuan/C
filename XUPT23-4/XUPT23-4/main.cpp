//
//  main.cpp
//  XUPT23-4
//
//  Created by 袁子涵 on 17/2/13.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>

using namespace std;
long long int a,b;
long long int bit;
long long int quick_pow(long long int num,long long int x)
{
    long long int out=1;
    while (x) {
        if (x&1) {
            out*=num;
        }
        x>>=1;
        num*=num;
    }
    return out;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int l,x,tmp;
    cin >> l >> x;
    bit=quick_pow(x, l-1);
    for (int i=0; i<l; i++) {
        cin >> tmp;
        a+=tmp*bit;
        bit/=x;
    }
    cin >> l >> x;
    bit=quick_pow(x, l-1);
    for (int i=0; i<l; i++) {
        cin >> tmp;
        b+=tmp*bit;
        bit/=x;
    }
    if (a>b) {
        cout << ">" << endl;
    }
    else if (a==b)
    {
        cout << "=" << endl;
    }
    else
        cout << "<" << endl;
    return 0;
}
