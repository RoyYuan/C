//
//  main.cpp
//  150813-1008
//
//  Created by 袁子涵 on 15/8/13.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int h,m,s;
int T;
long long int h1,h2,m1,m2,s1,s2;
int x[61];
long long int a1,a2,b1,b2,c1,c2;
long long int g1,g2,g3;

long long int gcd(long long int a,long long int b)
{
    long long int c;
    while(b!=0)  /* 余数不为0，继续相除，直到余数为0 */
    { c=a%b; a=b;  b=c;}
    return a;
}

int main(int argc, const char * argv[]) {
    cin >> T;
    for (int i=0; i<61; i++) {
        x[i]=i*6;
    }
    while (T--) {
        scanf("%2d:%2d:%2d",&h,&m,&s);
        s1=x[s];
        s2=1;
        m1=x[m]*60+s1;
        m2=60;
        h1=h*1440*30+m*720+s*12;
        h2=1440;
        if (h1>=360*h2) {
            h1-=360*h2;
        }
        a2=1440;
        a1=abs(h1-m1*24);
        if (a1>180*a2) {
            a1=360*a2-a1;
        }
        b1=abs(h1-s1*1440);
        b2=1440;
        if (b1>180*b2) {
            b1=360*b2-b1;
        }
        c1=abs(m1-s1*60);
        c2=60;
        if (c1>180*c2) {
            c1=360*c2-c1;
        }
        g1=gcd(a1, a2);
        if (a2/g1==1) {
            printf("%lld ",a1/g1);
        }
        else
        {
            printf("%lld/%lld ",a1/g1,a2/g1);
        }
        g2=gcd(b1, b2);
        if (b2/g2==1) {
            printf("%lld ",b1/g2);
        }
        else
            printf("%lld/%lld ",b1/g2,b2/g2);
        g3=gcd(c1, c2);
        if (c2/g3==1) {
            printf("%lld ",c1/g3);
        }
        else
        {
            printf("%lld/%lld ",c1/g3,c2/g3);
        }
        cout << endl;
    }
    return 0;
}
