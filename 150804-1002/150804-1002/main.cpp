//
//  main.cpp
//  150804-1002
//
//  Created by 袁子涵 on 15/8/4.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int T;
long long int n,m,z,l,key;
long long int num[500010];
long long int b[500010];

int main(int argc, const char * argv[]) {
    cin >> T;
    while (T--) {
        cin >> n >> m >> z >> l;
        num[0]=0;
        for (long long int i=1; i<n; i++) {
            num[i]=(num[i-1]*m+z)%l;
        }
        for(int i = 1; i <= n; i ++){
            b[i] = 2 * num[i];
            if(i == 1)
                key = b[1];
            else if(i >= 2){
                key = key ^ b[i];
            }
        }
        key ^= 0;
        cout << key << endl;
    }
    return 0;
}
