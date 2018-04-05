//
//  main.cpp
//  160803-5
//
//  Created by 袁子涵 on 16/8/3.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn=100005;
int n,p,now,l[maxn],r[maxn],str[maxn];
int a[maxn];
vector<int>line[maxn];
inline int LowBit(int x)    {return (x&(-x));}
inline int GetSum(int num)
{
    int sum=0;
    while(num>0)
    {
        sum+=a[num];
        num-=LowBit(num);
    }
    return sum;
}
inline void Add(int num,int x)
{
    while(num<=n)
    {
        a[num]+=x;
        num+=LowBit(num);
    }
}
void dfs(int num,int fa)
{
    str[++now]=num;
    l[num]=r[num]=now;
    for (int i=0; i<line[num].size(); i++)
        if (line[num][i]!=fa)
            dfs(line[num][i],num);
    r[num]=now;
}
int main(int argc, const char * argv[]) {
    int u,v;
    while (scanf("%d%d",&n,&p)!=EOF && n*p!=0) {
        memset(a, 0, sizeof(a));
        now=0;
        for (int i=1; i<=n; i++)
            line[i].clear();
        for (int i=1; i<n; i++) {
            scanf("%d%d",&u,&v);
            line[u].push_back(v);
            line[v].push_back(u);
        }
        dfs(p,-1);
        for (int i=1; i<n; i++) {
            Add(l[i], 1);
            printf("%d ",GetSum(r[i])-GetSum(l[i]));
        }
        printf("%d\n",GetSum(r[n])-GetSum(l[n]));
    }
    return 0;
}
