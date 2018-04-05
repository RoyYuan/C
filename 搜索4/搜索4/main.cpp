//
//  main.cpp
//  搜索4
//
//  Created by 袁子涵 on 17/2/25.
//  Copyright © 2017年 袁子涵. All rights reserved.
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
const int maxn=2e5+5;
const int mod=1e9+7;
vector<int>To[maxn];
int n,tmp;
int vis[maxn],now,circle;
long long int mi[maxn],ans;
bool flag;
void dfs(int num,int fa,int deep)
{
    if (vis[num]) {
        if (!flag)
            circle=deep-vis[num];
        flag=1;
        return;
    }
    now++;
    vis[num]=deep;
    bool back=0;
    for (int i=0; i<To[num].size(); i++) {
        if (!back && To[num][i]==fa)
        {
            back=1;
            continue;
        }
        dfs(To[num][i], num, deep+1);
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> n;
    mi[0]=ans=1;
    for (int i=1; i<=n; i++)
    {
        cin >> tmp;
        To[tmp].push_back(i);
        To[i].push_back(tmp);
        mi[i]=(mi[i-1]<<1)%mod;
    }
    for (int i=1; i<=n; i++) {
        if (!vis[i]) {
            now=circle=0;
            flag=0;
            dfs(i,0,1);
            ans=ans*mi[now-circle]%mod*(mi[circle]-2+mod)%mod;
        }
    }
    cout << ans << endl;
    return 0;
}
