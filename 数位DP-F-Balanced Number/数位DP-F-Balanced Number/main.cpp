//
//  main.cpp
//  数位DP-F-Balanced Number
//
//  Created by 袁子涵 on 15/11/7.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  31ms    20756KB


#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;
long long int dp[35][35][2000],x,y;
int num[35];

long long int dfs(int size,int pos,int moment,bool flag)
{
    if (size<0) {
        return moment==0;
    }
    if (moment<0) {
        return 0;
    }
    if (!flag && dp[size][pos][moment]!=-1) {
        return dp[size][pos][moment];
    }
    long long int ans=0;
    int maxs=flag?num[size]:9;
    for (int i=0; i<=maxs; i++) {
        ans+=dfs(size-1, pos, moment+i*(size-pos), flag && i==maxs);
    }
    if (!flag) {
        dp[size][pos][moment]=ans;
    }
    return ans;
}

long long int handle(long long int t)
{
    memset(num, 0, sizeof(num));
    int size=0;
    long long int ans=0;
    while (t) {
        num[size++]=t%10;
        t/=10;
    }
    for (int i=0; i<size; i++) {
        ans+=dfs(size,i,0,1);
    }
    ans-=(size-1);
    return ans;
}


int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    memset(dp, -1, sizeof(dp));
    while (T--) {
        cin >> x >> y;
        long long int out;
        out=handle(y)-handle(x-1);
        cout <<  out << endl;
    }
    return 0;
}
