//
//  main.cpp
//  HDU-5723-Abandoned country
//
//  Created by 袁子涵 on 16/7/20.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
#include <stack>

using namespace std;
const int MAXN=100005;
const int MAXM=1000005;
int t;
long long int n,m,father[MAXN],a,b,fa,fb,root,mst;
double result;
bool vis[MAXN];
typedef struct edge1
{
    long long int to,w;
    edge1(long long int _to,long long int _w):to(_to),w(_w){}
}edge1;
typedef struct edge
{
    long long int u,v,w;
    bool operator <(const edge &r)const
    {
        return w<r.w;
    }
}edge;
long long int find(long long int num)
{
    long long int now=num,root;
    while (father[now]!=now)
        now=father[now];
    root=now;
    now=num;
    while (father[now]!=now) {
        now=father[now];
        father[now]=root;
    }
    return root;
}
vector<edge1>Node[MAXN];
edge Edge[MAXM];
long long int dfs(long long int num,long long int wt)
{
    long long int son=0;
    vis[num]=1;
    for (long long int i=0; i<Node[num].size(); i++)
        if (vis[Node[num][i].to]==0)
            son+=dfs(Node[num][i].to, Node[num][i].w);
    son++;
    result+=(n-son)*son*wt;
    return son;
}
int main(int argc, const char * argv[]) {
    scanf("%d",&t);
    while (t--) {
        mst=result=0;
        scanf("%lld%lld",&n,&m);
        for (long long int i=1; i<=n; i++)
        {
            vis[i]=0;
            Node[i].clear();
            father[i]=i;
        }
        for (long long int i=0; i<m; i++)
            scanf("%lld%lld%lld",&Edge[i].u,&Edge[i].v,&Edge[i].w);
        sort(Edge+0,Edge+m);
        for (long long int i=0; i<m; i++) {
            a=Edge[i].u,b=Edge[i].v;
            fa=find(a),fb=find(b);
            if(fa!=fb)
            {
                Node[a].push_back(edge1(b,Edge[i].w));
                Node[b].push_back(edge1(a,Edge[i].w));
                mst+=Edge[i].w;
                father[fa]=fb;
            }
        }
        for (long long int i=1; i<=n; i++) {
            if (father[i]==i) {
                root=i;
                break;
            }
        }
        dfs(root,0);
        result/=(double)(n*n-n);
        result*=2;
        printf("%lld %.2lf\n",mst,result);
    }
    return 0;
}
