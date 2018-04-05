//
//  main.cpp
//  160910-3
//
//  Created by 袁子涵 on 16/9/10.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <utility>

using namespace std;
const int maxn=100005;
long long int a[maxn*2];
long long int num[maxn];
long long int plznum[maxn];
long long int plzk[maxn];
long long int n,k,root,out;
bool vis[maxn],roota[maxn];
typedef struct node
{
    bool flag;
    long long int num;
    double value;
    bool operator <(const node &r)const
    {
        return value<r.value;
    }
}node;
node Node[2*maxn];
vector<long long int>edge[maxn];
inline long long int LowBit(long long int x)    {return (x&(-x));}
inline long long int GetSum(long long int num)
{
    long long int sum=0;
    while(num>0)
    {
        sum+=a[num];
        num-=LowBit(num);
    }
    return sum;
}
inline void Add(long long int num,long long int x)
{
    while(num<=2*n)
    {
        a[num]+=x;
        num+=LowBit(num);
    }
}
void dfs(long long int now)
{
    if (vis[now])
        return;
    vis[now]=1;
    if (!edge[now].empty()) {
        Add(plznum[now], 1);
        for (long long int i=0; i<edge[now].size(); i++)
            dfs(edge[now][i]);
        Add(plznum[now], -1);
    }
    out+=GetSum(plzk[now]);
    return;
}
int main(void)
{
    int t;
    scanf("%d",&t);
    while (t--) {
        out=0;
        memset(vis, 0, sizeof(vis));
        memset(roota, 0, sizeof(roota));
        memset(a, 0, sizeof(a));
        scanf("%lld%lld",&n,&k);
        for (long long int i=1; i<=n; i++) {
            scanf("%lld",&num[i]);
            edge[i].clear();
            Node[2*i-1].num=i,Node[2*i-1].value=num[i],Node[2*i-1].flag=1;
            Node[2*i].num=i,Node[2*i].value=(double)k/num[i],Node[2*i].flag=0;
        }
        sort(Node+1,Node+2*n+1);
        for (long long int i=1; i<=2*n; i++) {
            if (Node[i].flag)
                plznum[Node[i].num]=i;
            else
                plzk[Node[i].num]=i;
        }
        long long int u,v;
        for (long long int i=1; i<n; i++) {
            scanf("%lld%lld",&u,&v);
            edge[u].push_back(v);
            roota[v]=1;
        }
        for (long long int i=1; i<=n; i++) {
            if (roota[i])
                continue;
            root=i;
            break;
        }
        dfs(root);
        printf("%lld\n",out);
    }
    return 0;
}
