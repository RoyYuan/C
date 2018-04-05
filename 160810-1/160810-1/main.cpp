//
//  main.cpp
//  160810-1
//
//  Created by 袁子涵 on 16/8/10.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <utility>
#include <set>

using namespace std;
const int maxm=1e4+5;
typedef struct Node
{
    int x,y;
    bool operator <(const Node &r)const
    {
        if (x<r.x)
            return 1;
        else if (x==r.x)
            return y<r.y;
        return 0;
    }
}Node;
Node node[maxm];
set<Node>out;
set<Node>::iterator it;
void dfs(int left,int right)
{
    if (left>=right)
        return;
    int mid=(left+right)>>1;
    for (int i=left; i<=right; i++)
        out.insert(Node{node[mid].x,node[i].y});
    dfs(left, mid-1);
    dfs(mid+1, right);
}
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d%d",&node[i].x,&node[i].y);
        out.insert(Node{node[i].x,node[i].y});
    }
    sort(node+1,node+n+1);
    dfs(1,n);
    n=out.size();
    printf("%d\n",n);
    it=out.begin();
    for (int i=1; i<=n; it++,i++)
        printf("%d %d\n",it->x,it->y);
    return 0;
}
