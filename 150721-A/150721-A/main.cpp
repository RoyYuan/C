//
//  main.cpp
//  150721-A
//
//  Created by 袁子涵 on 15/7/21.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

long int L[100000],R[100000];
long int n;
long int a[100000];
unsigned long long int sum;

int main()
{
    int flag;
    while (scanf("%ld",&n)!=EOF) {
        memset(a, 0, sizeof(a));
        for (long int i=0; i<n; i++) {
            //cin >> a[i];
            a[i]=i+1;
        }
        sum=0;
        memset(L, 0, sizeof(L));
        memset(R, 0, sizeof(R));
        for (long int i=0; i<n; i++) {
            flag=0;
            for (long int j=i-1; j>=0; j--) {
                if (a[i]%a[j]==0) {
                    flag=1;
                    L[i]=j;
                    break;
                }
            }
            if (flag==0) {
                L[i]=-1;
            }
            flag=0;
            for (long int j=i+1; j<n; j++) {
                if (a[i]%a[j]==0) {
                    flag=1;
                    R[i]=j;
                    break;
                }
            }
            if (flag==0) {
                R[i]=n;
            }
            sum+=((i-L[i])*(R[i]-i));
            sum=sum%1000000007;
        }
        cout << sum <<endl;
    }
}