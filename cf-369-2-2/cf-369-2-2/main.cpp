//
//  main.cpp
//  cf-369-2-2
//
//  Created by 袁子涵 on 16/8/29.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <map>

using namespace std;
const int maxn=505;
long long int n,num[maxn][maxn],x,y,nowx,total,tmp,tmp1,tmp2;
int main(int argc, const char * argv[]) {
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> num[i][j];
            if (num[i][j]==0) {
                x=i,y=j;
            }
        }
    }
    if (n==1) {
        cout << 1 << endl;
        return 0;
    }
    if (x==1) {
        nowx=n;
    }
    else
    {
        nowx=1;
    }
    total=0;
    for (int i=1; i<=n; i++) {
        total+=num[nowx][i];
    }
    tmp=0;
    for (int i=1; i<=n; i++) {
        if (i==y) {
            continue;
        }
        else
        {
            tmp+=num[x][i];
        }
    }
    if (total-tmp<=0) {
        cout << -1 << endl;
        return 0;
    }
    num[x][y]=total-tmp;
    tmp=0;
    bool flag=1;
    for (int i=1; i<=n; i++) {
        tmp+=num[i][y];
    }
    if (tmp!=total) {
        flag=0;
    }
    tmp=0;
    for (int i=1; i<=n; i++) {
        tmp+=num[i][i];
    }
    if (tmp!=total) {
        flag=0;
    }
    tmp=0;
    for (int i=1; i<=n; i++) {
        tmp+=num[i][n-i+1];
    }
    if (tmp!=total) {
        flag=0;
    }
    for (int i=1; i<=n; i++) {
        tmp1=tmp2=0;
        for (int j=1; j<=n; j++) {
            tmp1+=num[i][j];
            tmp2+=num[j][i];
        }
        if (tmp1!=tmp2 || tmp1!=total || tmp2!=total) {
            flag=0;
            break;
        }
    }
    if (flag) {
        cout << num[x][y] << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}
