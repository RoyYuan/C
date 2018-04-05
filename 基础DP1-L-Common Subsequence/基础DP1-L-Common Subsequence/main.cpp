//
//  main.cpp
//  基础DP1-L-Common Subsequence
//
//  Created by 袁子涵 on 15/10/24.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  0ms 924KB

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

char str1[201],str2[201];
int dp[201][201],out;
bool visit[201][201];

int DP(int a,int b)
{
    if (visit[a][b] || a==0 || b==0) {
        return dp[a][b];
    }
    if (str1[a-1]==str2[b-1]) {
        dp[a][b]=DP(a-1,b-1)+1;
    }
    else
        dp[a][b]=max(DP(a-1,b),DP(a,b-1));
    visit[a][b]=1;
    return dp[a][b];
}

int main(int argc, const char * argv[]) {
    while (scanf("%s%s",str1,str2)!=EOF) {
        dp[0][0]=0;
        memset(visit, 0, sizeof(visit));
        out=DP((int)strlen(str1),(int)strlen(str2));
        cout << out << endl;
    }
    return 0;
}
