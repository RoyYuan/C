//
//  main.cpp
//  基础DP1-G-免费馅饼
//
//  Created by 袁子涵 on 15/10/23.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

#define INF 0x7fffffff
#define MAX 110000

long long int n,dp[2][15],T,out;

typedef struct
{
    int x;
    long long int t;
}Pies;

Pies P[MAX];

bool comp1(Pies a,Pies b)
{
    if (a.t<b.t) {
        return 1;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    while (scanf("%lld",&n)!=EOF && n!=0) {
        T=0;
        for (long long int i=1; i<=n; i++) {
            scanf("%d%lld",&P[i].x,&P[i].t);
        }
        memset(dp, 0, sizeof(dp));
        sort(P+1, P+n+1, comp1);
        T=P[n].t;
        int q=1;
        bool flag=0;
        for (long long int i=0; i<=T; i++) {
            dp[flag][0]=max(dp[!flag][0],dp[!flag][1]);
            for (long long int j=((5-i)>=1?(5-i):1); j<=(5+i>=10?10:5+i); j++) {
                dp[flag][j]=max(dp[!flag][j-1],max(dp[!flag][j],dp[!flag][j+1]));
            }
            while (i==P[q].t && q<=n) {
                if (abs(5-P[q].x)<=i) {
                    dp[flag][P[q].x]++;
                }
                q++;
            }
            flag=!flag;
        }
        flag=!flag;
        out=0;
        for (int i=0; i<=10; i++) {
            out=max(out,dp[flag][i]);
        }
        cout << out << endl;
    }
    return 0;
}
