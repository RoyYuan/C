//
//  main.cpp
//  CodeForces-Round-330.2-2
//
//  Created by 袁子涵 on 15/11/9.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#define MAX 200000
#define MOOD 1000000007

using namespace std;

long long int n,k,a[MAX],b[MAX],sum[MAX],out=1;
int sizeb[MAX];

long long int pow(long long int times)
{
    long long int x=1;
    while (times) {
        x*=10;
        times--;
    }
    return x;
}

int getsize(long long int num)
{
    int x=0;
    while (num) {
        x++;
        num/=10;
    }
    return x;
}

int main(int argc, const char * argv[]) {
    cin >> n >> k;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(sum, 0, sizeof(sum));
    for (long long int i=0; i<n/k; i++) {
        scanf("%lld",&a[i]);
    }
    for (long long int i=0; i<n/k; i++) {
        scanf("%lld",&b[i]);
        sizeb[i]=getsize(b[i]);
    }
    long long int INF=pow(k);
    for (long long int i=0; i<n/k; i++) {
        long long int temp=0,temp1;
        if (b[i]!=0) {
            sum[i]++;
            sum[i]%=MOOD;
        }
        temp=a[i];
        while (temp<INF) {
            if (b[i]==0) {
                if (INF/temp<=10) {
                    sum[i]++;
                    sum[i]%=MOOD;
                }
            }
            else
            {
                temp1=temp;
                while (temp1>b[i]) {
                    temp1/=10;
                }
                if (temp1!=b[i]) {
                    sum[i]++;
                    sum[i]%=MOOD;
                }
            }
            temp+=a[i];
        }
    }
    for (long long int i=0; i<n/k; i++) {
        out*=sum[i];
    }
    cout << out << endl;
    return 0;
}
