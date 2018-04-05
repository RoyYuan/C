//
//  main.cpp
//  NYOJ-20-吝啬的国度
//
//  Created by 袁子涵 on 15/11/24.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  324ms   5164KB

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#define MAXIN 100100

using namespace std;
long long int N,S;
long long int father[MAXIN];
vector<long long int>v[MAXIN];

void dfs(long long int pre)
{
    for (int i=0; i<v[pre].size(); i++) {
        if (father[v[pre][i]]) {
            continue;
        }
        father[v[pre][i]]=pre;
        dfs(v[pre][i]);
    }
}
int main(int argc, const char * argv[]) {
    int M,a,b;
    cin >> M;
    while (M--) {
        cin >> N >> S;
        memset(v, 0, sizeof(v));
        memset(father, 0, sizeof(father));
        father[S]=-1;
        for (long long int i=1; i<N; i++) {
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(S);
        for (long long int i=1; i<=N; i++) {
            printf("%lld ",father[i]);
        }
    }
    return 0;
}
