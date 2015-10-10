//
//  main.cpp
//  150723-6
//
//  Created by 袁子涵 on 15/7/23.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

struct Step
{
    int a;
    int b;
}step[100];

int T;
int n,m,num,sum;
int connect[10][10];
int friends[10];
int off[10];
int on[10];

void dfs(int number)
{
    if (number>m) {
        for (int i=1; i<=n; i++) {
            if (off[i]==(friends[i]/2) && (on[i]==(friends[i]/2))) {
                continue;
            }
            else
            {
                return;
            }
        }
        sum++;
    }
}

int main(int argc, const char * argv[]) {
    int flag;
    cin >> T;
    while (T--) {
        memset(connect, 0, sizeof(connect));
        memset(friends, 0, sizeof(friends));
        sum=0;
        cin >> n >> m;
        for (int i=1; i<=m; i++) {
            cin >> step[i].a >> step[i].b;
            connect[step[i].a][step[i].b]=1;
            connect[step[i].b][step[i].a]=1;
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (connect[i][j]==1) {
                    friends[i]++;
                }
            }
            if (friends[i]%2) {
                cout << "0" <<endl;
                continue;
            }
        }
        dfs(1);
        dfs(1);
    }
    return 0;
}
