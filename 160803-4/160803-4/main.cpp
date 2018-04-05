//
//  main.cpp
//  160803-4
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
#include <string>

using namespace std;
const int maxn=100005;
int M,N,str[maxn],now,l[maxn],r[maxn],top[maxn];
int line[maxn][100];
bool vis[maxn];
int a[maxn];
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
    while(num<=N)
    {
        a[num]+=x;
        num+=LowBit(num);
    }
}
void dfs(int num)
{
    vis[num]=1;
    str[++now]=num;
    l[num]=r[num]=now;
    for (int i=0; i<top[num]; i++)
        if (vis[line[num][i]]==0)
            dfs(line[num][i]);
    r[num]=now;
}
int main(int argc, const char * argv[]) {
    int u,v;
    scanf("%d",&N);
    for (int i=1; i<N; i++) {
        Add(i, 1);
        scanf("%d%d",&u,&v);
        line[u][top[u]++]=v;
        line[v][top[v]++]=u;
    }
    Add(N, 1);
    dfs(1);
    scanf("%d",&M);
    char op,ch;
    int tmp;
    for (int i=1; i<=M; i++) {
        while((ch=getchar())!='\n');
        scanf("%c%d",&op,&tmp);
        switch (op) {
            case 'Q':
                printf("%d\n",GetSum(r[tmp])-GetSum(l[tmp]-1));
                break;
            case 'C':
                int tt=GetSum(l[tmp])-GetSum(l[tmp]-1);
                if (tt>0)
                    Add(l[tmp], -1);
                else
                    Add(l[tmp], 1);
        }
    }
    return 0;
}
