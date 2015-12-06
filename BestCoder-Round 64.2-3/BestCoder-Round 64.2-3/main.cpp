//
//  main.cpp
//  BestCoder-Round 64.2-3
//
//  Created by 袁子涵 on 15/11/28.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;
long long int T,m;
long long int bit[65],bit2[65];
long long int mi(int x)
{
    long long int out=1;
    while (x--) {
        out*=2;
    }
    return out;
}
int main(int argc, const char * argv[]) {
    bit[0]=1;
    bit[1]=2;
    for (int i=0; i<=64; i++)
        bit2[i]=mi(i);
    for (int i=2; i<=64; i++)
        bit[i]=2*bit[i-1]+bit2[i-1]-1;
    cin >> T;
    while (T--) {
        cin >> m;
        long long int sum=0,out=0;
        while (m) {
            int num=0;
            while (m>=bit2[num]) {
                num++;
            }
            num--;
            m-=bit2[num];
            sum+=bit[num]+out*bit2[num];
            out++;
        }
        cout << sum << endl;
    }
    return 0;
}
