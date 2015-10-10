//
//  main.cpp
//  0728-1011
//
//  Created by 袁子涵 on 15/7/28.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

int n,k;

typedef struct guanxi
{
    int a;
    int b;
}Guanxi;

Guanxi g[110];
int connect[110][110];
int sum;
int s[110];

int f(int a)
{
    if (s[a]!=0) {
        return s[a];
    }
    for (int i=1; i<=n; i++) {
        if (connect[a][i]==1) {
            s[a]+=f(i)+1;
        }
    }
    return s[a];
}

int main(int argc, const char * argv[]) {
    while (scanf("%d %d",&n,&k)!=EOF) {
        memset(connect, 0, sizeof(connect));
        memset(s, 0, sizeof(s));
        sum=0;
        for (int i=1; i<n; i++) {
            cin >> g[i].a >> g[i].b;
            connect[g[i].a][g[i].b]=1;
            connect[g[i].b][g[i].a]=-1;
        }
        for (int i=1; i<=n; i++) {
            f(i);
            if (s[i]==k) {
                sum++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
