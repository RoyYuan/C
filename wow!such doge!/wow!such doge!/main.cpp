//
//  main.cpp
//  wow!such doge!
//
//  Created by 袁子涵 on 15/6/2.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxstr 10086

char str[maxstr];
long int sum=0;

int main(int argc, const char * argv[]) {
    int i;
    while (gets(str)!=NULL) {
        i=0;
        while (str[i+3]!=0) {
            if (str[i]=='d'||str[i]=='D') {
                if (str[i+1]=='o'||str[i+1]=='O') {
                    if (str[i+2]=='g'||str[i+2]=='G') {
                        if (str[i+3]=='e'||str[i+3]=='E') {
                            sum++;
                        }
                    }
                }
            }
            i++;
        }
    }
    printf("%ld\n",sum);
    return 0;
}
