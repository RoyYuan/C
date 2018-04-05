//
//  main.cpp
//  160807-5
//
//  Created by 袁子涵 on 16/8/7.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int tmp,n,t,out;
bool flag;
int main(int argc, const char * argv[]) {
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        out=0;
        flag=0;
        for (int i=1; i<=n; i++) {
            scanf("%d",&tmp);
            if (tmp!=1)
                flag=1;
            out^=tmp;
        }
        if ((out==0 && !flag) || (out>0 && flag))
            puts("John");
        else
            puts("Brother");
    }
    return 0;
}
