//
//  main.cpp
//  基础DP1-O-Treats for the Cows
//
//  Created by 袁子涵 on 15/10/28.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  188ms   18600KB

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

#define MAX 2005

using namespace std;
int v[MAX],N,dp[MAX][MAX],out=0;
bool visit[MAX][MAX];
int DP(int head,int tail)
{
    if (head<0 || tail >N) {
        return 0;
    }
    if (visit[head][tail]) {
        return dp[head][tail];
    }
    dp[head][tail]=max(DP(head-1,tail)+v[head]*(N-(tail-head)),DP(head,tail+1)+v[tail+1]*(N-(tail-head)));
    visit[head][tail]=1;
    return dp[head][tail];
}

int main(int argc, const char * argv[]) {
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> v[i];
    }
    memset(visit, 0, sizeof(visit));
    for (int i=1; i<=N; i++) {
        out=max(out,DP(i, i));
    }
    cout << out << endl;
    return 0;
}
