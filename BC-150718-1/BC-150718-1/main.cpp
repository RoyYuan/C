//
//  main.cpp
//  BC-150718-1
//
//  Created by 袁子涵 on 15/7/18.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define N 3145800

char s[N];
int flag=0;
unsigned long int length;
unsigned long int T;

void isornot()
{
    unsigned long int wp=N,yp=0,hp=0;
    int wflag=0;
    for (unsigned long int i=0; i<length;i++) {
        if(s[i]=='w')
        {
            if(wflag==0)
            {
                wp=i;
                wflag=1;
            }
        }
        if (s[i]=='v') {
            if (s[i+1]=='v') {
                if (wflag==0) {
                    wp=i;
                    wflag=1;
                }
            }
        }
        if (s[i]=='y') {
            if (wp>=yp) {
                yp=i;
            }
        }
        if (s[i]=='h') {
            hp=i;
        }
    }
    if (wp<yp && yp<hp) {
        flag=1;
    }
    return;
}

int main(int argc, const char * argv[]) {
    scanf("%lu",&T);
    while (T--) {
        flag=0;
        scanf("%s",s);
        length=strlen(s);
        isornot();
        if (flag==1) {
            printf("Yes\n");
        }
        else
            printf("No\n");
    }
    return 0;
}
