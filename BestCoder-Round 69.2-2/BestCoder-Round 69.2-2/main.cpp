//
//  main.cpp
//  BestCoder-Round 69.2-2
//
//  Created by 袁子涵 on 16/1/23.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <stdlib.h>

using namespace std;

int t;
long long int total,n,a,b,tmp;
char str[12],same;
bool flag=0;
int year,mon,day;
int s[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};

int main(int argc, const char * argv[]) {
    scanf("%d",&t);
    while (t--) {
        total=0;
        scanf("%lld",&n);
        scanf("%lld %lld",&a,&b);
        while (n--) {
            flag=1;
            scanf("%s",str);
            same=str[6];
            for (int i=7; i<11; i++) {
                if (str[i]!=same) {
                    flag=0;
                    break;
                }
            }
            if (flag) {
                total+=a;
                continue;
            }
            flag=1;
            for (int i=8; i<11; i++) {
                if (str[i]-str[i-1]!=str[i-1]-str[i-2]) {
                    flag=0;
                    break;
                }
            }
            if (flag) {
                total+=a;
                continue;
            }
            flag=1;
            year=mon=day=0;
            tmp=1000;
            for (int i=3; i<7; i++) {
                year+=(str[i]-'0')*tmp;
                tmp/=10;
            }
            if (year<1980 || year>2016) {
                total+=b;
                continue;
            }
            tmp=10;
            for (int i=7; i<9; i++) {
                mon+=(str[i]-'0')*tmp;
                tmp/=10;
            }
            if (mon<1 || mon>12) {
                total+=b;
                continue;
            }
            tmp=10;
            for (int i=9; i<11; i++) {
                day+=(str[i]-'0')*tmp;
                tmp/=10;
            }
            if (day<1 || day>31) {
                total+=b;
                continue;
            }
            if (mon!=2) {
                if (day<=s[mon]) {
                    total+=a;
                    continue;
                }
                else
                {
                    total+=b;
                    continue;
                }
            }
            else
            {
                if (year%400==0 || (year%4==0 && year%100!=0)) {
                    if (day<=29) {
                        total+=a;
                        continue;
                    }
                    else
                    {
                        total+=b;
                        continue;
                    }
                }
                else
                {
                    if (day<29) {
                        total+=a;
                        continue;
                    }
                    else
                    {
                        total+=b;
                        continue;
                    }
                }
            }
        }
        printf("%lld\n",total);
    }
    return 0;
}
