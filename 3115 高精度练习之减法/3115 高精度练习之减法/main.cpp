//
//  main.cpp
//  3115 高精度练习之减法
//
//  Created by 袁子涵 on 15/6/5.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxof(a,b) ((a)>(b)?(a):(b))

char a[500];
char b[500];
char c[500];

void swap(char*x,char*y)
{
    char t;
    t=*x;
    *x=*y;
    *y=t;
}

int main(void) {
    int i,m,n;
    int x,y,z,k,t;
    int flag=1;
    int zero=0;
    scanf("%s %s",a,b);
    m=(int)strlen(a);
    n=(int)strlen(b);
    for (i=0; i<m/2; i++) {
        swap(&a[i],&a[m-1-i]);
    }
    for (i=0; i<n/2; i++) {
        swap(&b[i],&b[n-1-i]);
    }
    k=maxof(m, n);
    t=0;
    z=0;
    if (m<n) {
        flag=0;
    }
    else if (m==n)
    {
        i=m-1;
        while (i>-1) {
            if (a[i]<b[i]) {
                flag=0;
                break;
            }
            i--;
        }
    }
    if (flag) {
        for (i=0; i<k; i++) {
            x=0;
            y=0;
            if (a[i]) {
                x=a[i]-48;
            }
            if (b[i]) {
                y=b[i]-48;
            }
            if (x-y-t<0) {
                z=10+x-y-t;
                t=1;
            }
            else
            {
                z=x-y-t;
                t=0;
            }
            c[i]=z+48;
        }
    }
    else
    {
        for (i=0; i<k; i++) {
            x=0;
            y=0;
            if (a[i]) {
                x=a[i]-48;
            }
            if (b[i]) {
                y=b[i]-48;
            }
            if (y-x-t<0) {
                z=10+y-x-t;
                t=1;
            }
            else
            {
                z=y-x-t;
                t=0;
            }
            c[i]=z+48;
        }
    }
    if (flag==0) {
        printf("-");
    }
    for (i=k-1; i>=0; i--) {
        if (zero==0 && c[i]=='0') {
            continue;
        }
        if (c[i]!=0) {
            zero=1;
        }
        printf("%c",c[i]);
    }
    if (zero==0) {
        printf("0\n");
    }
    return 0;
}
