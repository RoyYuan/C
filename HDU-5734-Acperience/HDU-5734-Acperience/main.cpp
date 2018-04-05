//
//  main.cpp
//  HDU-5734-Acperience
//
//  Created by 袁子涵 on 16/7/21.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>

using namespace::std;
int t;
long long int n,s,fa,tmp,fz,fm,yue;
long long int gcd(long long int a,long long int b)
{
    if (b==0)
        return a;
    return gcd(b, a%b);
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n;
        s=fa=0;
        for (long long int i=0; i<n ; i++) {
            cin >> tmp;
            fa+=tmp*tmp;
            s+=abs(tmp);
        }
        fz=-s*s+n*fa;
        fm=n;
        yue=gcd(fz, fm);
        cout << fz/yue << '/' << fm/yue << endl;
    }
    return 0;
}
