//
//  main.cpp
//  150730-1002
//
//  Created by 袁子涵 on 15/7/30.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;
#define Maxof(a,b) ((a)>(b)?(a):(b))

int T;

unsigned long int n;
unsigned long long int a[1000010];

int main(int argc, const char * argv[]) {
    cin >> T;
    unsigned long long int x=0,y=0;
    long long int p=0;
    double q=0;
    unsigned long long int ap=1,gp=1;
    long long int maxs=1;
    unsigned long long int la,ra,lg,rg;
    while (T--) {
        cin >> n;
        memset(a, 0, sizeof(a));
        ap=1;
        gp=1;
        maxs=1;
        la=1;
        lg=1;
        if (n<=2) {
            for (int i=1; i<=n; i++) {
                cin >> a[i];
            }
            cout << n << endl;
            continue;
        }
        for (unsigned long int i=1; i<=2; i++) {
            cin >> a[i];
            if (i==2) {
                x=a[2];
                y=a[2];
                p=a[2]-a[1];
                q=(double)(a[2])/(double)(a[1]);
                ra=2;
                rg=2;
            }
        }
        for (unsigned long int i=3; i<=n; i++) {
             scanf("%llu",&a[i]);
                if (a[i]-x==p) {
                    x=a[i];
                    ra=i;
                }
                else
                {
                    ap++;
                    x=a[i];
                    p=a[i]-a[i-1];
                    ra=i-1;
                    maxs=Maxof(maxs, ra-la+1);
                    la=i-1;
                }
                if ((double)(a[i])/(double)(y)==q) {
                    y=a[i];
                    rg=i;
                }
                else
                {
                    gp++;
                    y=a[i];
                    q=(double)(a[i])/(double)(a[i-1]);
                    rg=i-1;
                    maxs=Maxof(maxs, rg-lg+1);
                    lg=i-1;
                }
        }
        cout << maxs <<endl;
    }
    return 0;
}
