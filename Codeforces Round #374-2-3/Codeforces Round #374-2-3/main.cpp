//
//  main.cpp
//  Codeforces Round #374-2-3
//
//  Created by 袁子涵 on 16/9/30.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;
const int maxn=5005;
const int inf=0x3f3f3f3f;
//int n,m,T;
//int dp[maxn];
//int tt[maxn];
//typedef struct qnode
//{
//    int node,time,sum;
//    vector<int>out;
//}qnode;
//vector<int>ans;
//vector<pair<int,int> >edge[maxn];
int n,m,l;
int ans,eg[maxn],kl[maxn],fp[maxn],di[maxn];
int dp[maxn][maxn],p[maxn][maxn],q[maxn],t;
inline void add(int u,int v,int c)
{
    ans++,eg[ans]=v,kl[ans]=fp[u],di[ans]=c,fp[u]=ans;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> n >> m >> l;
    int u,v,c;
    for (int i=1; i<=m; i++) {
        cin >> u >> v >> c;
        add(u,v,c);
    }
    memset(dp, 60, sizeof(dp));
    dp[1][1]=0;
    for (int i=1; i<n; i++) {
        for (int j=1; j<=n; j++) {
            for (int k=fp[j]; k!=0; k=kl[k]) {
                if ((dp[j][i]<=l) && (dp[j][i]+di[k]<dp[eg[k]][i+1])) {
                    dp[eg[k]][i+1]=dp[j][i]+di[k],p[eg[k]][i+1]=j;
                }
            }
        }
        if (dp[n][i]<=l) {
            t=i;
        }
    }
    if (dp[n][n]<=l) {
        t=n;
    }
    int o=0;
    for (int i=n,j=t; j!=0; i=p[i][j],j--) {
        o++,q[o]=i;
    }
    cout << o << endl;
    for (int i=o; i>0; i--) {
        cout << q[i] << " ";
    }
//    cin >> n >> m >> T;
//    int u,v,c;
//    for (int i=1; i<=m; i++) {
//        cin >> u >> v >> c;
//        edge[u].push_back(make_pair(v, c));
//    }
//    for (int i=2; i<=n; i++) {
//        tt[i]=inf;
//    }
//    queue<qnode>Q;
//    while (!Q.empty())
//        Q.pop();
//    qnode now;
//    now.node=now.sum=1;
//    now.time=0;
//    dp[1]=1;
//    now.out.clear();
//    now.out.push_back(1);
//    Q.push(now);
//    while (!Q.empty()) {
//        now=Q.front();
//        Q.pop();
//        if (now.node==n) {
//            if (now.sum>=dp[n]) {
//                ans=now.out;
//            }
//            continue;
//        }
//        for (int i=0; i<edge[now.node].size(); i++) {
//            int next=edge[now.node][i].first,cost=edge[now.node][i].second;
//            if (cost+now.time<=T) {
//                if (dp[next]<now.sum+1 || (dp[next]==now.sum+1 && cost+now.time<tt[next])) {
//                    dp[next]=now.sum+1;
//                    tt[next]=cost+now.time;
//                    qnode tmp;
//                    tmp.node=next,tmp.time=tt[next],tmp.sum=dp[next],tmp.out=now.out;
//                    tmp.out.push_back(next);
//                    Q.push(tmp);
//                }
//            }
//        }
//    }
//    cout << ans.size() << endl;
//    for (int i=0; i<ans.size(); i++) {
//        cout << ans[i];
//        if (i!=ans.size()-1) {
//            cout << " ";
//        }
//        else
//            cout << endl;
//    }
    return 0;
}
