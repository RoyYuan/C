//
//  main.cpp
//  sta15-test
//
//  Created by 袁子涵 on 15/11/28.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
#include <stdio.h>

float f(float x)
{
    if (x<1)    return x;
    else if (x<10)  return 2*x-1;
    else    return 3*x-11;
}

int main(int argc, const char * argv[]) {
    float x;
    scanf("%f",&x);
    printf("%f\n",f(x));
    return 0;
}