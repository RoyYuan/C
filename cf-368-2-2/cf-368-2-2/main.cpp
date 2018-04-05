//
//  main.cpp
//  cf-368-2-2
//
//  Created by 袁子涵 on 16/8/20.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <utility>
#include <map>

using namespace std;
long long int n,m,k,city[100005];
long long int out=0x7fffffff;
bool vis[100005];
vector<pair<long long int,long long int>>edge[100005];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    bool flag=0;
    long long int u,v,c;
    for (int i=0; i<m; i++) {
        cin >> u >> v >> c;
        edge[u].push_back(make_pair(v,c));
        edge[v].push_back(make_pair(u, c));
    }
    for (int i=0; i<k; i++) {
        cin >> city[i];
        vis[city[i]]=1;
    }
    for (int i=0; i<k; i++) {
        for (int j=0; j<edge[city[i]].size(); j++) {
            if (vis[edge[city[i]][j].first]) {
                continue;
            }
            flag=1;
            out=min(out,edge[city[i]][j].second);
        }
    }
    if (flag) {
        cout << out << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}
