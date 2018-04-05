//
//  main.cpp
//  XUPT03-B
//
//  Created by 袁子涵 on 16/6/2.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N = 1000;
const int inf = 0x3f3f3f3f;
int n,m,k;
struct Node
{
    int from,to,cap,flow;
};
vector<int> v[N];
vector<Node> e;
int vis[N];
int cur[N];
void add_Node(int from,int to,int cap)
{
    e.push_back((Node){from,to,cap,0});
    e.push_back((Node){to,from,0,0});
    int tmp=e.size();
    v[from].push_back(tmp-2);
    v[to].push_back(tmp-1);
}
bool bfs(int s,int t)
{
    memset(vis, -1, sizeof(vis));
    queue<int> q;
    q.push(s);
    vis[s] = 0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0; i<v[x].size(); i++)
        {
            Node tmp = e[v[x][i]];
            if(vis[tmp.to]<0 && tmp.cap>tmp.flow)
            {
                vis[tmp.to]=vis[x]+1;
                q.push(tmp.to);
            }
        }
    }
    if(vis[t]>0)
        return true;
    return false;
}
int dfs(int o,int f,int t)
{
    if(o==t || f==0)
        return f;
    int a = 0,ans=0;
    for(int &i=cur[o]; i<v[o].size(); i++)
    {
        Node &tmp = e[v[o][i]];
        if(vis[tmp.to]==(vis[o]+1) && (a = dfs(tmp.to,min(f,tmp.cap-tmp.flow),t))>0)
        {
            tmp.flow+=a;
            e[v[o][i]^1].flow-=a;
            ans+=a;
            f-=a;
            if(f==0)
                break;
        }
    }
    return ans;
}

int dinci(int s,int t)
{
    int ans=0;
    while(bfs(s,t))
    {
        memset(cur, 0, sizeof(cur));
        int tm=dfs(s,inf,t);
        ans+=tm;
    }
    return ans;
}
int mp[450][450];
int dou[450][450];
bool solve()
{
    for(int i=1;i<=n;i++)
    {
        int tmp=0;
        for(int j=0;j<v[i].size();j++)
            if(e[v[i][j]].to>n)
                mp[i][++tmp]=e[v[i][j]].flow;
    }
    memset(dou, 0, sizeof(dou));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            for(int z = j+1; z <= m; z++)
            {
                bool v1=0,v2=0;
                if(mp[i][j]!=k&&mp[i][z]!=0)
                {
                    if(dou[z][j])
                        return 0;
                    v1=1;
                }
                if(mp[i][j]!=0&&mp[i][z]!=k)
                {
                    if(dou[j][z])return 0;
                    v2=1;
                }
                if(v1)dou[j][z]=1;
                if(v2)dou[z][j]=1;
            }
    }
    return 1;
}
int main()
{
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        int x;
        int s=0,t=m+n+1,sum_a=0,sum_b=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            sum_a += x;
            add_Node(s,i,x);
            for(int j=1;j<=m;j++)
                add_Node(i,n+j,k);
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&x);
            sum_b+=x;
            add_Node(i+n,t,x);
        }
        int ans=dinci(s,t);
        if(ans!=min(sum_a,sum_b))
            printf("Impossible\n");
        else
        {
            memset(mp,0,sizeof(mp));
            if(solve()==0)
                printf("Not Unique\n");
            else
            {
                printf("Unique\n");
                for(int i=1;i<=n;i++)
                    for(int j=1;j<=m;j++)
                        printf("%d%c",mp[i][j],j==m?'\n':' ');
            }
        }
        for(int i=0; i<=t; i++)
            v[i].clear();
        e.clear();
    }
    return 0;
}

