//
//  main.cpp
//  160805-3
//
//  Created by 袁子涵 on 16/8/5.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define lnode(a) (a<<1)
#define rnode(a) (a<<1|1)
const int MAXN = 20010;
const int MAXM = 100010;
struct Edge {
        int to,next;
}edge[MAXM];
int head[MAXN],tot,num[MAXN];
void init() {
    tot = 0;
    memset(head,-1,sizeof(head));
}
inline void addedge(int u,int v) {
    edge[tot].to = v;edge[tot].next = head[u];head[u] = tot++;
}
bool vis[MAXN];
int S[MAXN],top;
bool dfs(int u) {
    if(vis[u^1])return false;
    if(vis[u])return true;
    vis[u] = true;
    S[top++] = u;
    for(int i = head[u];i != -1;i = edge[i].next)
        if(!dfs(edge[i].to))
            return false;
    return true;
}
bool Twosat(int n) {
    memset(vis,false,sizeof(vis));
    for(int i = 0;i < n;i += 2){
        if(vis[i] || vis[i^1])continue;
        top = 0;
        if(!dfs(i))
        {
            while(top)
                vis[S[--top]] = false;
            if(!dfs(i^1))
                return false;
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    int t,cas=0,n,m,tmp,a,b,k;
    bool flag;
    scanf("%d",&t);
    while (t--) {
        init();
        flag=1;
        scanf("%d%d",&n,&m);
        for (int i=0; i<n; i++) {
            scanf("%d",&tmp);
            switch (tmp) {
                case 1:
                    num[lnode(i)]=1,num[rnode(i)]=2;
                    break;
                case 2:
                    num[lnode(i)]=2,num[rnode(i)]=3;
                    break;
                case 3:
                    num[lnode(i)]=1,num[rnode(i)]=3;
                default:
                    break;
            }
        }
        for (int i=0; i<m; i++) {
            scanf("%d%d%d",&a,&b,&k);
            a--,b--;
            if (a==b) {
                if (k==1)
                    flag=0;
                continue;
            }
            if (k==0) {
                if (num[lnode(a)]!=num[lnode(b)])
                    addedge(lnode(a), rnode(b)),addedge(lnode(b), rnode(a));
                if (num[lnode(a)]!=num[rnode(b)])
                    addedge(lnode(a), lnode(b)),addedge(rnode(b), rnode(a));
                if (num[rnode(a)]!=num[rnode(b)])
                    addedge(rnode(a), lnode(b)),addedge(rnode(b), lnode(a));
                if (num[rnode(a)]!=num[lnode(b)])
                    addedge(rnode(a), rnode(b)),addedge(lnode(b), lnode(a));
            }
            else
            {
                if (num[lnode(a)]==num[lnode(b)])
                    addedge(lnode(a), rnode(b)),addedge(lnode(b), rnode(a));
                if (num[lnode(a)]==num[rnode(b)])
                    addedge(lnode(a), lnode(b)),addedge(rnode(b), rnode(a));
                if (num[rnode(a)]==num[lnode(b)])
                    addedge(rnode(a), rnode(b)),addedge(lnode(b), lnode(a));
                if (num[rnode(a)]==num[rnode(b)])
                    addedge(rnode(a), lnode(b)),addedge(rnode(b), lnode(a));
            }
        }
        printf("Case #%d: ",++cas);
        if (!flag)
        {
            printf("no\n");
            continue;
        }
        flag=Twosat(2*n);
        if (flag)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
