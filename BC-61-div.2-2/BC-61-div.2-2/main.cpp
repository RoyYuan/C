//
//  main.cpp
//  BC-61-div.2-2
//
//  Created by 袁子涵 on 15/10/31.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int N,S,T;

int main(int argc, const char * argv[]) {
    while (scanf("%d%d%d",&N,&S,&T)!=EOF) {
        if (S==T) {
            if (N==1) {
                printf("0\n");
                continue;
            }
            else
            {
                printf("-1\n");
                continue;
            }
        }
        else if (S<T)
        {
            if (T-S>1) {
                if (S==1) {
                    if (T==N) {
                        printf("0\n");
                        continue;
                    }
                    if (T<N) {
                        printf("1\n");
                        continue;
                    }
                }
                if (S>1) {
                    if (T==N) {
                        printf("2\n");
                        continue;
                    }
                    if (T<N) {
                        printf("2\n");
                        continue;
                    }
                }
            }
            else
            {
                if (S==1) {
                    if (N==2) {
                        printf("0\n");
                        continue;
                    }
                    else
                    {
                        printf("1\n");
                        continue;
                    }
                }
                if (S>1) {
                    printf("1\n");
                    continue;
                }
            }
        }
        else if (S>T)
        {
            if (S-T>1) {
                if (S==N) {
                    if (T==1) {
                        printf("0\n");
                        continue;
                    }
                    if (T>1) {
                        printf("1\n");
                        continue;
                    }
                }
                if (S<N) {
                    if (T==1) {
                        printf("2\n");
                        continue;
                    }
                    if (T>1) {
                        printf("2\n");
                        continue;
                    }
                }
            }
            else
            {
                if (T==1) {
                    if (N==2) {
                        printf("0\n");
                        continue;
                    }
                    else
                    {
                        printf("1\n");
                        continue;
                    }
                }
                if (T>1) {
                    printf("1\n");
                    continue;
                }
            }
            
        }
        else
        {
            printf("-1\n");
            continue;
        }
    }
    return 0;
}
