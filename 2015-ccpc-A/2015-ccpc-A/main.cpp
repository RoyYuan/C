//
//  main.cpp
//  2015-ccpc-A
//
//  Created by 袁子涵 on 15/11/20.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  124ms 1572kb

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main(int argc, const char * argv[]) {
    int T,now=0;
    cin >> T;
    int a[5],b[5];
//    int a[2][2],b[2][2];
    while (now<T) {
        bool flag=0;
        cin >> a[1] >> a[2] >> a[4] >> a[3];
        cin >> b[1] >> b[2] >> b[4] >> b[3];
        for (int i=1; i<5; i++) {
            if (b[i]==a[1]) {
                for (int j=1; j<=3; j++) {
                    if (i+j>4) {
                        if (b[i+j-4]!=a[1+j]) {
                            break;
                        }
                        if (j==3) {
                            flag=1;
                            break;
                        }
                    }
                    else
                    {
                        if (b[i+j]!=a[1+j]) {
                            break;
                        }
                        if (j==3) {
                            flag=1;
                            break;
                        }
                    }
                }
            }
            if (flag) {
                break;
            }
        }
//        for (int i=0; i<2; i++) {
//            for (int j=0; j<2; j++) {
//                cin >> a[i][j];
//            }
//        }
//        for (int i=0; i<2; i++) {
//            for (int j=0; j<2; j++) {
//                cin >> b[i][j];
//            }
//        }
//        if (a[0][0]==b[0][0] && a[0][1]==b[0][1] && a[1][1]==b[1][1] && a[1][0]==b[1][0])
//            flag=1;
//        else if (a[0][0]==b[0][1] && a[0][1]==b[1][1] && a[1][1]==b[1][0] && a[1][0]==b[0][0])
//            flag=1;
//        else if (a[0][0]==b[1][1] && a[0][1]==b[1][0] && a[1][1]==b[0][0] && a[1][0]==b[0][1])
//            flag=1;
//        else if (a[0][0]==b[1][0] && a[0][1]==b[0][0] && a[1][1]==b[0][1] && a[1][0]==b[1][1])
//            flag=1;
        if (flag) {
            printf("Case #%d: POSSIBLE\n",++now);
        }
        else
            printf("Case #%d: IMPOSSIBLE\n",++now);
        
    }
    return 0;
}
