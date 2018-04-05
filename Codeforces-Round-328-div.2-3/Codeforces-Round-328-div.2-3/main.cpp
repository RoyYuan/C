//
//  main.cpp
//  Codeforces-Round-328-div.2-3
//
//  Created by 袁子涵 on 15/11/1.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

long long int t,w,b,up,down;
void swap(long long int *a,long long int *b)
{
    *a+=*b;
    *b=*a-*b;
    *a-=*b;
}

long long int gcd(long long int a,long long int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main(int argc, const char * argv[]) {
    cin >> t >> w >> b;
    up=0;
    if (w==b) {
        cout << "1/1" << endl;
        return 0;
    }
    if (w>b) {
        swap(&w, &b);
    }
    if (t<w) {
        cout << "1/1" << endl;
        return 0;
    }
    if (t>b) {
        if () {
            long long int temp=(long long int )(t/(b*w));
            up+=w*temp;
            up+=(t-temp)>=w?w-1:t-temp;
        }
        else
        {
            up+=
        }
    }
    return 0;
}
