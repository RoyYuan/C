//
//  main.cpp
//  DP2
//
//  Created by 袁子涵 on 17/3/6.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <list>
#include <map>
#include <stack>
using namespace::std;
int T,num[20];
long long int dp[20][3],N;
void handle()
{
    dp[0][0]=1;
    for (int i=1; i<=18; i++) {
        dp[i][0]=dp[i-1][0]*10-dp[i-1][1];
        dp[i][1]=dp[i-1][0];
        dp[i][2]=dp[i-1][2]*10+dp[i-1][1];
    }
}
long long int DP()
{
    int size=0;
    long long int temp=N;
    memset(num, 0, sizeof(num));
    while (temp) {
        num[++size]=temp%10;
        temp/=10;
    }
    bool flag=0;
    for (int i=size; i>0; i--) {
        temp+=dp[i-1][2]*num[i];
        if (flag)
            temp+=dp[i-1][0]*num[i];
        else if (num[i]>4)
            temp+=dp[i-1][1];
        if (num[i+1]==4 && num[i]==9)
            flag=1;
    }
    if (flag)
        temp++;
    return temp;
}

int main(int argc, const char * argv[]) {
    cin >> T;
    handle();
    while (T--) {
        cin >> N;
        long long int out=0;
        out=DP();
        cout << out << endl;
    }
    return 0;
}
