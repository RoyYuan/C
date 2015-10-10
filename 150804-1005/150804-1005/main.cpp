//
//  main.cpp
//  150804-1005
//
//  Created by 袁子涵 on 15/8/4.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int a,b;

int s[25]={0,1312,2372,520,899,800,1086,1402,1313,1681,2080,495,737,577,786,1011,999,1251,1520,1140,1351,1008,1170,890,1037};

int main(int argc, const char * argv[]) {
    while (scanf("%d %d",&a,&b)!=EOF) {
        if (s[a]>s[b]) {
            printf("FIRST BIGGER\n");
        }
        else
        {
            printf("SECOND BIGGER\n");
        }
    }
    return 0;
}
