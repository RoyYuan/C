//
//  main.cpp
//  150920-3
//
//  Created by 袁子涵 on 15/9/20.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;
int T;
long long int n,m;
long long int score[50005][5];
long long int q,p;
long long int set[50005][5];
long long int sum;


int main(int argc, const char * argv[]) {
    scanf("%d",&T);
    bool f=0;
    while (T--) {
        scanf("%lld%lld",&n,&m);
        memset(score, 0, sizeof(score));
        memset(set, 0, sizeof(set));
        for ( long long int i=0; i<n; i++) {
            for (int j=0; j<5; j++) {
                scanf("%lld",&score[i][j]);
            }
        }
        scanf("%lld",&q);
        for (long long int i=0; i<q; i++) {
            for (int j=0; j<5; j++) {
                scanf("%lld",&set[i][j]);
            }
        }
        sum=0;
        for (long long int i=0; i<n; i++) {
            f=1;
            for (long long int j=0; j<5; j++) {
                if (score[i][j]>set[0][j]) {
                    f=0;
                    break;
                }
            }
            if (f) {
                sum++;
            }
        }
        printf("%lld\n",sum);
        p=q-1;
        while (p--) {
            if (sum!=0) {
                for (int j=0; j<5; j++) {
                    set[q-p-1][j]^=sum;
                }
            }
            sum=0;
            for (long long int i=0; i<n; i++) {
                f=1;
                for (long long int j=0; j<5; j++) {
                    if (score[i][j]>set[q-p-1][j]) {
                        f=0;
                        break;
                    }
                }
                if (f) {
                    sum++;
                }
            }
            printf("%lld\n",sum);
        }
    }
    return 0;
}
