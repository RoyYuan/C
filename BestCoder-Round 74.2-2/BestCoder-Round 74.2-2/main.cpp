//
//  main.cpp
//  BestCoder-Round 74.2-2
//
//  Created by 袁子涵 on 16/3/5.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cmath>
#define M 1000000007
using namespace std;
long long int t;
long long int n,m;
long long int a1,a2,a3,b1,b2,b3;
long long int dis,tmp1,tmp2,out;
long long int s,e;
bool vis1[4];

long long int f(long long int x)
{
    return x>0?x:-x;
}

long long int dfs(long long int s,long long int e)
{
    long long int dis=f(s-e);
    if (vis1[1]==0) {
        vis1[1]=1;
        dis=min(dis,f(s-a1)+1+dfs(b1, e));
        dis=min(dis,f(s-b1)+1+dfs(a1, e));
        dis=min(dis,dfs(s, e));
        vis1[1]=0;
    }
    if (vis1[2]==0) {
        vis1[2]=1;
        dis=min(dis,f(s-a2)+1+dfs(b2, e));
        dis=min(dis,f(s-b2)+1+dfs(a2, e));
        dis=min(dis,dfs(s, e));
        vis1[2]=0;
    }
    if (vis1[3]==0) {
        vis1[3]=1;
        dis=min(dis,f(s-a3)+1+dfs(b3, e));
        dis=min(dis,f(s-b3)+1+dfs(a3, e));
        dis=min(dis,dfs(s, e));
        vis1[3]=0;
    }
    return dis;
}

int main(int argc, const char * argv[]) {
    cin >> t;
    while (t--) {
        out=0;
        cin >> n >> m;
        cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
        for (long long int i=1; i<=m; i++) {
            scanf("%lld %lld",&s,&e);
            memset(vis1, 0, sizeof(vis1));
            dis=dfs(s, e);
            out+=i*dis;
            out%=M;
        }
        cout << out << endl;
    }
    return 0;
}
