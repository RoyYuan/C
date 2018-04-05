//
//  main.cpp
//  XUPT04-D
//
//  Created by 袁子涵 on 16/9/8.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>

using namespace std;
const int maxn=10;
const int inf=0x7fffffff;
typedef struct snode
{
    int node,sum;
    bool operator <(const snode &r)const
    {
        return sum<r.sum;
    }
}snode;
typedef struct Node
{
    pair<int,int> maxsub=make_pair(0, 0);
    set<snode>subnode;
}Node;
int sum[maxn];
int fa[maxn];
bool vis[maxn];
Node node[maxn];
int n;
vector<int>edge[maxn];
pair<int,set<snode>> dfs1(int now,int last)
{
    int total=0;
    pair<int,set<snode>>tmp;
    set<snode>::iterator it;
    if (vis[now])
        return tmp;
    vis[now]=1;
    for (int i=0; i<edge[now].size(); i++) {
        if (edge[now][i]==last)
            continue;
        tmp=dfs1(edge[now][i], now);
        total+=tmp.first;
        if (node[now].maxsub.second<tmp.first)
            node[now].maxsub=make_pair(edge[now][i], tmp.first);
        it=tmp.second.begin();
        for (; it!=tmp.second.end(); it++)
        {
            node[now].subnode.insert(*it);
            node[now].subnode.insert(snode{now, it->sum+1});
        }
    }
    total++;
    sum[now]=total;
    fa[now]=last;
    return make_pair(total, node[now].subnode);
}
int main(int argc, const char * argv[]) {
    int a,b;
    scanf("%d",&n);
    for (int i=1; i<n; i++) {
        scanf("%d%d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    if (n==3) {
        cout << "1 1 1" << endl;
        return 0;
    }
    dfs1(1, 0);
    memset(vis, 0, sizeof(vis));
    for (int i=2; i<=n; i++) {
        int tt=n-sum[i];
        if (tt>node[i].maxsub.second)
            node[i].maxsub=make_pair(fa[i], tt);
    }
    for (int i=1; i<=n; i++) {
        if (node[i].maxsub.second<n/2)
            printf("1 ");
        else
        {
            snode tmp;
            tmp.sum=node[i].maxsub.second-n/2;
            set<snode>::iterator it;
            it=node[node[i].maxsub.first].subnode.upper_bound(tmp);
            if (it!=node[node[i].maxsub.first].subnode.begin()) {
                it--;
                if (it->sum>=tmp.sum && it->sum<=n/2) {
                    if (it->node!=i) {
                        printf("1 ");
                        continue;
                    }
                }
                it++;
            }
            if (it->node!=i && it->sum<=n/2)
                printf("1 ");
            else
                printf("0 ");
        }
    }
    return 0;
}
