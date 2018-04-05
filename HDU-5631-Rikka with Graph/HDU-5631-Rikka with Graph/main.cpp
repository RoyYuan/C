//
//  main.cpp
//  HDU-5631-Rikka with Graph
//
//  Created by 袁子涵 on 16/2/24.
//  Copyright © 2016年 袁子涵. All rights reserved.
//
//  343ms   1616KB

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;
long long int t,n,u,v,out;
bool vis[105];
long long int father[105];
typedef struct edge
{
    long long int u,v;
}Edge;
Edge E[105];

void init()
{
    for (long long int i=0; i<=n; i++)
        father[i]=i;
}

long long int find(long long int num)
{
    long long int root,now=num,tmp;
    while (father[now]!=now)
        now=father[now];
    root=now;
    now=num;
    while (father[now]!=now) {
        tmp=father[now];
        father[now]=root;
        now=tmp;
    }
    return root;
}

bool check(long long int num1,long long int num2)
{
    init();
    long long int fx,fy,result=0;
    for (long long int i=1; i<=n+1; i++) {
        if (i==num1 || i==num2)
            continue;
        fx=find(E[i].u);
        fy=find(E[i].v);
        if (fx!=fy)
            father[fx]=father[fy];
    }
    for (long long int i=1; i<=n; i++)
        if (father[i]==i)
            result++;
    if (result==1)
        return 1;
    return 0;
}

int main(int argc, const char * argv[]) {
    cin >> t;
    while (t--) {
        cin >> n;
        out=0;
        memset(vis, 0, sizeof(vis));
        memset(E, 0, sizeof(E));
        for (long long int i=1; i<=n+1; i++)
            scanf("%lld %lld",&E[i].u,&E[i].v);
        for (long long int i=1; i<=n; i++) {
            for (long long int j=i+1; j<=n+1; j++) {
                if (check(i, j)) {
                    if (vis[i]==0) {
                        vis[i]=1;
                        out++;
                    }
                    if (vis[j]==0) {
                        vis[j]=1;
                        out++;
                    }
                    out++;
                }
            }
        }
        cout << out << endl;
    }
    return 0;
}
