//
//  main.cpp
//  Codeforces-Round 328-div.2-1
//
//  Created by 袁子涵 on 15/11/1.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#define INF 0x7fffffff
using namespace std;

char plat[10][10];

int main(int argc, const char * argv[]) {
    memset(plat, 0, sizeof(plat));
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            cin >> plat[i][j];
        }
    }
    int wina=INF,winb=INF,tempa,tempb;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (plat[i][j]=='W') {
                tempa=0;
                for (int k=i; k>=0; k--) {
                    if (plat[k][j]=='.') {
                        tempa++;
                    }
                }
                if (tempa==i) {
                    wina=min(tempa,wina);
                }
            }
            if (plat[i][j]=='B') {
                tempb=0;
                for (int k=i; k<8; k++) {
                    if (plat[k][j]=='.') {
                        tempb++;
                    }
                }
                if (tempb==7-i) {
                    winb=min(tempb,winb);
                }
            }
        }
    }
    if (wina>winb) {
        printf("B\n");
    }
    else
        printf("A\n");
    return 0;
}
