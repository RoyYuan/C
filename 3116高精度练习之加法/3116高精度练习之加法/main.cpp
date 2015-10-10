//
//  main.cpp
//  3116高精度练习之加法
//
//  Created by 袁子涵 on 15/6/4.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxof(a,b) ((a)>(b)?(a):(b))

char a[501];
char b[501];
char sum[502];

void swap(char *a,char *b)
{
    char c;
    c=*a;
    *a=*b;
    *b=c;
}



int main(int argc, const char * argv[]) {
    int i;
    int x,y,z,t;
    unsigned long int k,m,n;
    scanf("%s %s",a,b);
    m=strlen(a);
    n=strlen(b);
    for (i=0; i<m/2; i++) {
        swap(&a[i],&a[m-i-1]);
    }
    for (i=0; i<n/2; i++) {
        swap(&b[i],&b[n-1-i]);
    }
    k=maxof(m, n);
    t=0;
    for (i=0; i<k; i++) {
        x=0;
        y=0;
        if (a[i]) {
            x=a[i]-'0';
        }
        if (b[i]) {
            y=b[i]-'0';
        }
        z=x+y+t;
        t=(z>=10?1:0);
        z=z%10;
        sum[i]=z+'0';
    }
    if (t) {
        sum[i]='1';
    }
    k=strlen(sum);
    for (i=(int)k-1; i>=0; i--) {
        printf("%c",sum[i]);
    }
    return 0;
}
