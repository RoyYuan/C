//
//  main.cpp
//  搜索6
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
const int maxn=100010;
bool vis[maxn*2];
queue<pair<int,int> >Q;
int main(int argc, const char * argv[]) {
    int s,t,now,step,ans;
    cin >> s >> t;
    if (s>t) {
        cout << s-t << endl;
        return 0;
    }
    Q.push(make_pair(s, 0));
    vis[s]=1;
    while (!Q.empty()) {
        now=Q.front().first;
        step=Q.front().second;
        Q.pop();
        if (now==t) {
            ans=step;
            break;
        }
        if (!vis[now+1]) {
            vis[now+1]=1;
            Q.push(make_pair(now+1, step+1));
        }
        if (now>0 && !vis[now-1]) {
            vis[now-1]=1;
            Q.push(make_pair(now-1, step+1));
        }
        if (now<maxn && !vis[now*2]) {
            vis[now*2]=1;
            Q.push(make_pair(now*2, step+1));
        }
    }
    cout << ans << endl;
    return 0;
}
