//
//  main.cpp
//  160811-2
//
//  Created by ??? on 16/8/11.
//  Copyright © 2016? ???. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#define lson(x) (x<<1)
#define rson(x) (x<<1|1)
using namespace std;
const long long int maxn=400005;
typedef struct node
{
    long long int num,l,r,lazy;
}node;
node tree[maxn];
long long int build(long long int l,long long int r,long long int root)
{
    tree[root].l=l,tree[root].r=r,tree[root].lazy=0;
    if (l==r) {
        scanf("%lld",&tree[root].num);
        return tree[root].num;
    }
    long long int mid=(l+r)>>1;
    tree[root].num=build(l, mid, lson(root));
    tree[root].num+=build(mid+1, r, rson(root));
    return tree[root].num;
}
inline void push_up(long long int root)
{
    tree[root].num=tree[lson(root)].num+tree[rson(root)].num;
}
inline void push_down(long long int root)
{
    if (!tree[root].lazy)
        return;
    tree[lson(root)].lazy+=tree[root].lazy;
    tree[rson(root)].lazy+=tree[root].lazy;
    tree[lson(root)].num+=tree[root].lazy*(tree[lson(root)].r-tree[lson(root)].l+1);
    tree[rson(root)].num+=tree[root].lazy*(tree[rson(root)].r-tree[rson(root)].l+1);
    tree[root].lazy=0;
}
void add(long long int l,long long int r,long long int root,long long int num)
{
    if (tree[root].l>=l && tree[root].r<=r) {
        tree[root].lazy+=num;
        tree[root].num+=num*(tree[root].r-tree[root].l+1);
        return;
    }
    push_down(root);
    long long int mid=(tree[root].l+tree[root].r)>>1;
    if (l<=mid)
        add(l, r, lson(root), num);
    if (r>mid)
        add(l, r, rson(root), num);
    push_up(root);
}
long long int get_sum(long long int l,long long int r,long long int root)
{
    long long int out=0;
    if (tree[root].l>=l && tree[root].r<=r) {
        return tree[root].num;
    }
    push_down(root);
    long long int mid=(tree[root].l+tree[root].r)>>1;
    if (l<=mid)
        out+=get_sum(l, r, lson(root));
    if (r>mid)
        out+=get_sum(l, r, rson(root));
    return out;
}
int main(int argc, const char * argv[]) {
    long long int n,q,l,r,num;
    char op;
    scanf("%lld%lld",&n,&q);
    build(1, n, 1);
    for (long long int i=1; i<=q; i++) {
        while ((op=getchar())!='\n');
        scanf("%c",&op);
        if (op=='Q') {
            scanf("%lld%lld",&l,&r);
            printf("%lld\n",get_sum(l,r,1));
        }
        else
        {
            scanf("%lld%lld%lld",&l,&r,&num);
            add(l, r, 1, num);
        }
    }
    return 0;
}