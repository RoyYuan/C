//
//  main.cpp
//  150723-2
//
//  Created by 袁子涵 on 15/7/23.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>

#define minof(a,b) ((a)>(b)?(b):(a))
#define maxof(a,b) ((a)>(b)?(a):(b))

using namespace std;
unsigned long long int n,m,x,y;
int s;

int main(int argc, const char * argv[]) {
    unsigned long long int max,min;
    unsigned long long int centerx,centery;
    unsigned long long int bigger,smaller;
    while (scanf("%llu %llu %llu %llu",&n,&m,&x,&y)!=EOF) {
        min=minof(n, m);
        if (min%2==0) {
            max=min/2;
        }
        else
            max=min/2+1;
        if (n>=m) {
            s=1;
        }
        else
            s=2;
        if (n%2 && m%2) {
            centerx=n/2+1;
            centery=m/2+1;
            if (x==centerx && y==centery && x==y) {
                max--;
                cout << max << endl;
                continue;
            }
        }
        if (s==1) {
            bigger=maxof(y-1, m-y);
            smaller=minof(x, n-x+1);
            max=maxof(minof(bigger, smaller), max);
        }
        if (s==2) {
            bigger=maxof(x-1, n-x);
            smaller=minof(y, m-y+1);
            max=maxof(minof(bigger, smaller), max);
        }
        cout << max <<endl;
    }
    return 0;
}
