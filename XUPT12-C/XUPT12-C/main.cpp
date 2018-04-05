//
//  main.cpp
//  XUPT12-C
//
//  Created by 袁子涵 on 16/10/19.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;
const int maxn=200005;
int n,m,k,c[maxn];
int fa[maxn],times[maxn];
vector<int>l[maxn];
inline int find(int num)
{
    int root,now=num;
    while(fa[now]!=now)
        now=fa[now];
    root=now;
    fa[num]=root;
    return root;
}
inline void join(int a,int b)
{
    int ffa=find(a),ffb=find(b);
    if (ffa!=ffb) {
        fa[ffa]=ffb;
    }
}
int main(int argc, const char * argv[]) {
    long long int ans=0;
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++)
    {
        scanf("%d",&c[i]);
        fa[i]=i;
    }
    int a,b;
    for (int i=1; i<=m; i++) {
        scanf("%d%d",&a,&b);
        join(a, b);
    }
    for (int i=1; i<=n; i++)
        l[find(i)].push_back(c[i]);
    for (int i=1; i<=n; i++) {
        if (find(i)==i) {
            int tmp=0,total=l[i].size();
            map<int,int>book;
            for (int j=0; j<total; j++) {
                book[l[i][j]]++;
                tmp=max(book[l[i][j]],tmp);
            }
            ans+=total-tmp;
        }
    }
    printf("%lld\n",ans);
    return 0;
}