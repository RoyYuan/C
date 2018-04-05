//
//  main.cpp
//  160811-3
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
const long long int maxn=4000005;
typedef long long int  LL;
typedef struct node
{
    LL l,r,sum,num,num1,total;
}node;
node tree[maxn];
inline void fresh(LL num,LL root)
{
    if (num>=tree[root].num)
        return;
    tree[root].sum-=(tree[root].num-num)*tree[root].total;
    tree[root].num=num;
}
inline void push_up(LL root)
{
    tree[root].num=max(tree[lson(root)].num,tree[rson(root)].num);
    tree[root].num1=max(tree[lson(root)].num1,tree[rson(root)].num1);
    tree[root].sum=tree[lson(root)].sum+tree[rson(root)].sum;
    tree[root].total=0;
    if (tree[lson(root)].num==tree[root].num)
        tree[root].total+=tree[lson(root)].total;
    else
        tree[root].num1=max(tree[root].num1,tree[lson(root)].num);
    if (tree[rson(root)].num==tree[root].num)
        tree[root].total+=tree[rson(root)].total;
    else
        tree[root].num1=max(tree[root].num1,tree[rson(root)].num);
}
inline void push_down(LL root)
{
    fresh(tree[root].num,lson(root));
    fresh(tree[root].num,rson(root));
}
void build(LL l,LL r,LL root)
{
    tree[root].l=l,tree[root].r=r;
    if (l==r) {
        scanf("%lld",&tree[root].num);
        tree[root].sum=tree[root].num;
        tree[root].total=1;
        tree[root].num1=-1;
        return;
    }
    LL mid=(l+r)>>1;
    build(l, mid, lson(root));
    build(mid+1, r, rson(root));
    push_up(root);
}
void f1(LL root,LL l,LL r,LL t)
{
    if (tree[root].num<=t)
        return;
    if (tree[root].l==l && tree[root].r==r && tree[root].num1<t) {
        fresh(t, root);
        return;
    }
    push_down(root);
    LL mid=(tree[root].l+tree[root].r)>>1;
    if (l<=mid)
        f1(lson(root), l, min(r,mid), t);
    if (r>mid)
        f1(rson(root), max(l,mid+1), r, t);
    push_up(root);
}
LL f2(LL root,LL l,LL r)
{
    LL out=0;
    if (tree[root].l>=l && tree[root].r<=r)
        return tree[root].num;
    push_down(root);
    LL mid=(tree[root].l+tree[root].r)>>1;
    if (l<=mid)
        out=max(out,f2(lson(root), l, r));
    if (r>mid)
        out=max(out,f2(rson(root), l, r));
    return out;
}
LL f3(LL root,LL l,LL r)
{
    LL out=0;
    if (tree[root].l>=l && tree[root].r<=r)
        return tree[root].sum;
    push_down(root);
    LL mid=(tree[root].l+tree[root].r)>>1;
    if (l<=mid)
        out+=f3(lson(root), l, r);
    if (r>mid)
        out+=f3(rson(root), l, r);
    return out;
}
int main(int argc, const char * argv[]) {
    int t,op;
    long long int n,m,l,r,num;
    scanf("%d",&t);
    while (t--) {
        scanf("%lld%lld",&n,&m);
        build(1, n, 1);
        for (LL i=1; i<=m; i++) {
            scanf("%d",&op);
            scanf("%lld%lld",&l,&r);
            switch (op) {
                case 0:
                    scanf("%lld",&num);
                    f1(1, l, r, num);
                    break;
                case 1:
                    printf("%lld\n",f2(1, l, r));
                    break;
                case 2:
                    printf("%lld\n",f3(1, l, r));
                    break;
            }
        }
    }
    return 0;
}