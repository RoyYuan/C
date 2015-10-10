//
//  main.cpp
//  150804-1009
//
//  Created by 袁子涵 on 15/8/4.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>

using namespace std;

long long int fib[1010];
long long int s[1010];
int T;

long long int cal(int num)
{
    if (s[num]!=0) {
        return s[num];
    }
    return fib[num-2]+cal(num-3);
}
int main(void){
    cin >> T;
    int n, m;
    memset(fib, 0, sizeof(fib));
    memset(s, 0, sizeof(s));
    fib[1]=1;
    fib[2]=1;
    for (int i=3; i<=1000; i++) {
        fib[i]=(fib[i-1]+fib[i-2])%258280327;
    }
    while(T --){
        cin >> n >> m;
        
        cout << fib[5] << endl;
    }
}