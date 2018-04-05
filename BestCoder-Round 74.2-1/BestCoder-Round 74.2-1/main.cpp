//
//  main.cpp
//  BestCoder-Round 74.2-1
//
//  Created by 袁子涵 on 16/3/5.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#define M 1000000007
using namespace std;

long long int t;
long long int n,out,now;
long long int a[100005];

int main(int argc, const char * argv[]) {
    cin >> t;
    while (t--) {
        cin >> n;
        a[0]=n;
        bool f=1;
        out=26;
        for (long long int i=1; i<n; i++) {
            scanf("%lld",&a[i]);
            if (a[i]>n-i) {
                f=0;
                continue;
            }
            if (i==1 || (a[i]==0 && a[i-1]<=1) || a[i]==a[i-1]-1 || (a[i]>0 && a[i-1]==0)) {
                continue;
            }
            else
                f=0;
        }
        if (f==0)
            cout << "0" << endl;
        else
        {
            if (a[1]==n-1) {
                cout << "26" << endl;
            }
            else
            {
                for (long long int i=1; i<n; i++) {
                    if (a[i]>0 && a[i-1]==0) {
                        i++;
                        while (a[i]==a[i-1]-1 && a[i]!=0) {
                            i++;
                        }
                    }
                    while (a[i]==0 && i<n) {
                        out*=25;
                        out%=M;
                        i++;
                    }
                }
                cout << out << endl;
            }
        }
    }
    return 0;
}
