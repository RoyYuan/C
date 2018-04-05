//
//  main.cpp
//  160803-1
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

typedef struct node
{
    long long int l,r,data,lazy1,lazy2;
}node;
node tree[500000];
int op;
long long int n,m,p,num[100005],ll,rr,up;
long long int build(long long int root,long long int l,long long int r)
{
    tree[root].l=l,tree[root].r=r,tree[root].lazy1=1,tree[root].lazy2=0;
    if (l==r) {
        tree[root].data=num[l];
        return num[l];
    }
    long long int mid=(l+r)>>1;
    tree[root].data=build(root<<1, l, mid);
    tree[root].data=(tree[root].data+build(root<<1|1, mid+1, r))%p;
    return tree[root].data;
}
inline void pushup(long long int root)
{
    tree[root].data=(tree[root<<1].data+tree[root<<1|1].data)%p;
}
inline void pushdown(long long int root)
{
    long long int sl=root<<1,sr=root<<1|1;
    tree[sl].lazy1=(tree[sl].lazy1*tree[root].lazy1)%p;
    tree[sl].lazy2=(tree[sl].lazy2*tree[root].lazy1+tree[root].lazy2)%p;
    tree[sl].data=(tree[sl].data*tree[root].lazy1+(tree[sl].r-tree[sl].l+1)*tree[root].lazy2)%p;
    tree[sr].lazy1=(tree[sr].lazy1*tree[root].lazy1)%p;
    tree[sr].lazy2=(tree[sr].lazy2*tree[root].lazy1+tree[root].lazy2)%p;
    tree[sr].data=(tree[sr].data*tree[root].lazy1+(tree[sr].r-tree[sr].l+1)*tree[root].lazy2)%p;
    tree[root].lazy1=1,tree[root].lazy2=0;
}
void f1(long long int root,long long int l,long long int r,long long int now)
{
    if (l<=tree[root].l && r>=tree[root].r) {
        tree[root].lazy1=(tree[root].lazy1*now)%p;
        tree[root].lazy2=(tree[root].lazy2*now)%p;
        tree[root].data=(tree[root].data*now)%p;
        return;
    }
    pushdown(root);
    long long int mid=(tree[root].l+tree[root].r)>>1;
    if (l<=mid)
        f1(root<<1, l, r, now);
    if (r>mid)
        f1(root<<1|1, l, r, now);
    pushup(root);
}
void f2(long long int root,long long int l,long long int r,long long int now)
{
    if (l<=tree[root].l && r>=tree[root].r) {
        tree[root].lazy2=(tree[root].lazy2+now)%p;
        tree[root].data=(tree[root].data+now*(tree[root].r-tree[root].l+1))%p;
        return;
    }
    pushdown(root);
    long long int mid=(tree[root].l+tree[root].r)>>1;
    if (l<=mid)
        f2(root<<1, l, r, now);
    if (r>mid)
        f2(root<<1|1, l, r, now);
    pushup(root);
}
long long int f3(long long int root,long long int l,long long int r)
{
    long long int out=0;
    if (l<=tree[root].l && r>=tree[root].r) {
        return tree[root].data;
    }
    pushdown(root);
    long long int mid=(tree[root].l+tree[root].r)>>1;
    if (l<=mid)
        out+=f3(root<<1, l, r)%p;
    if (r>mid)
        out+=f3(root<<1|1, l, r)%p;
    return out%p;
}
int main(int argc, const char * argv[]) {
    scanf("%lld%lld",&n,&p);
    for (long long int i=1; i<=n; i++)
        scanf("%lld",&num[i]);
    scanf("%lld",&m);
    build(1, 1, n);
    for (long long int i=1; i<=m; i++) {
        scanf("%d",&op);
        switch (op) {
            case 1:
                scanf("%lld%lld%lld",&ll,&rr,&up);
                f1(1,ll,rr,up);
                break;
            case 2:
                scanf("%lld%lld%lld",&ll,&rr,&up);
                f2(1,ll,rr,up);
                break;
            case 3:
                scanf("%lld%lld",&ll,&rr);
                printf("%lld\n",f3(1,ll,rr));
        }
    }
    return 0;
}