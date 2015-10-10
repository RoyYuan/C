//
//  main.cpp
//  150813-1005
//
//  Created by 袁子涵 on 15/8/13.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int T;
char a[100000][10000];
char b[100000][10000];
unsigned long long int sum[100000];
long long int n,m;

void times(long long int num)
{
    char t[10000],k[10000];
    bool flag=1;
    unsigned long int l1,l2;
    memcpy(t, a[num], sizeof(t));
    l1=strlen(t);
    for (long long int i=0; i<m; i++) {
        memcpy(k, b[i], sizeof(k));
        l2=strlen(k);
        if (l1<l2) {
            continue;
        }
        for (long long int j=0; j<l1-l2+1; j++) {
            if (t[j]==k[0]) {
                flag=1;
                for (long long int q=0; q<l2; q++) {
                    if (t[j+q]!=k[q]) {
                        flag=0;
                        break;
                    }
                }
                if (flag) {
                    sum[num]++;
                }
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    cin >> T;
    while (T--) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(sum, 0, sizeof(sum));
        scanf("%lld%lld",&n,&m);
        for (long long int i=0; i<n; i++) {
            scanf("%s",a[i]);
        }
        for (long long int i=0; i<m; i++) {
            scanf("%s",b[i]);
        }
        for (long long int i=0; i<n; i++) {
            times(i);
            printf("%llu\n",sum[i]);
        }
    }
    return 0;
}
