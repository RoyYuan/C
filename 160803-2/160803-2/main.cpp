//
//  main.cpp
//  160803-2
//
//  Created by 袁子涵 on 16/8/3.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;
const int INF=0x7fffffff;
typedef struct node
{
    long long int sum,mid,left,right;
    int r,l;
}node;
node tree[200005];
int n,m;
long long int ans;
void build(int root,int l,int r)
{
    int sl=root<<1,sr=root<<1|1,mid=(l+r)>>1;
    tree[root].l=l,tree[root].r=r;
    if (l==r) {
        long long int tmp;
        scanf("%lld",&tmp);
        tree[root].sum=tree[root].mid=tree[root].left=tree[root].right=tmp;
        return;
    }
    build(sl, l, mid);
    build(sr, mid+1, r);
    tree[root].sum=tree[sl].sum+tree[sr].sum;
    tree[root].mid=max(tree[sl].mid,tree[sr].mid);
    tree[root].mid=max(tree[root].mid,tree[sl].right+tree[sr].left);
    tree[root].left=max(tree[sl].left,tree[sl].sum+tree[sr].left);
    tree[root].left=max(tree[root].left,tree[sl].sum);
    tree[root].right=max(tree[sr].right,tree[sr].sum+tree[sl].right);
    tree[root].right=max(tree[root].right,tree[sr].sum);
}
long long int getmid(int root,int l,int r,int flag)
{
    long long int lout=0,rout=0,out=0;
    if (l<=tree[root].l && r>=tree[root].r)
    {
        ans=max(ans,tree[root].mid);
        return flag==-1?tree[root].left:tree[root].right;
    }
    int mid=(tree[root].l+tree[root].r)>>1;
    if (r<=mid)
        return getmid(root<<1, l, r, -1);
    else if (l>mid)
        return getmid(root<<1|1, l, r, 1);
    else {
        lout=getmid(root<<1, l, r, 1);
        rout=getmid(root<<1|1, l, r, -1);
        out=lout+rout;
        ans=max(ans,out);
        if (flag==-1)
            return max(tree[root<<1].left,tree[root<<1].sum+rout);
        else
            return max(tree[root<<1|1].right,tree[root<<1|1].sum+lout);
    }
}
int main(int argc, const char * argv[]) {
    int x,y;
    scanf("%d",&n);
    build(1, 1, n);
    scanf("%d",&m);
    for (int i=1; i<=m; i++) {
        scanf("%d%d",&x,&y);
        ans=-INF;
        getmid(1,x,y,-1);
        printf("%lld\n",ans);
    }
    return 0;
}
