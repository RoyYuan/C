//
//  main.cpp
//  3117 高精度练习之乘法
//
//  Created by 袁子涵 on 15/6/8.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxof(a,b)  ((a)>(b)?(a):(b))

char a[500];
char b[500];
int c[1000];
int sum[600];
char d[1000];

void swap(char*a,char*b)
{
    *a+=*b;
    *b=*a-*b;
    *a-=*b;
}

int main(void)
{
    int i,j;
    int m,n;
    int x,y,z,t=0;
    int flag=0;
    int num=0;
    scanf("%s %s",a,b);
    m=(int)strlen(a);
    n=(int)strlen(b);
    memset(d, 0, sizeof(d));
    for (i=0; i<m/2; i++) {
        swap(&a[i], &a[m-1-i]);
    }
    for (i=0; i<n/2; i++) {
        swap(&b[i], &b[n-1-i]);
    }
    for (i=0; i<n; i++) {
        x=b[i]-48;
        t=0;
        memset(sum, 0, sizeof(sum));
        for (j=0; j<m; j++) {
            y=a[j]-48;
            z=x*y+t;
            t=z/10;
            z=z%10;
            sum[j]=z;
        }
        sum[m]=t;
        for (j=0; j<=m; j++) {
            c[i+j]+=sum[j];
        }
    }
    for (i=0; i<1000; i++) {
        if (c[i]>9) {
            z=c[i]/10;
            c[i+1]+=z;
            c[i]=c[i]%10;
        }
    }
    for (i=999; i>=0; i--) {
        if (c[i]!=0) {
            flag=1;
        }
        if (flag==0) {
            continue;
        }
        d[num++]=c[i]+48;
    }
    puts(d);
    return 0;
}