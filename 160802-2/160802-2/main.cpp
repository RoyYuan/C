//
//  main.cpp
//  160802-2
//
//  Created by 袁子涵 on 16/8/2.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <set>
#include <map>

using namespace std;
typedef struct line
{
    double y1,y2,x;
    int flag;
    bool operator <(const line &r)const
    {
        return x<r.x;
    }
}line;
typedef struct node
{
    bool flag;
    double down,up,left;
    int cover;
    
}node;
int n;
double y[205];
line li[205];
node tree[1005];
void build(int num,int l,int r)
{
    tree[num].left=-1;
    tree[num].cover=0;
    tree[num].down=y[l];
    tree[num].up=y[r];
    tree[num].flag=0;
    if (l+1==r) {
        tree[num].flag=1;
        return;
    }
    build(num<<1, l, (l+r)>>1);
    build((num<<1)+1, ((l+r)>>1), r);
}
double fresh(int root,double x,double d,double u,int flag)
{
    double ans=0;
    if (u<=tree[root].down || d>=tree[root].up) {
        return 0;
    }
    if (tree[root].flag) {
        if (tree[root].cover>0) {
            ans=(x-tree[root].left)*(tree[root].up-tree[root].down);
            tree[root].left=x;
            tree[root].cover+=flag;
            return ans;
        }
        else
        {
            tree[root].left=x;
            tree[root].cover+=flag;
            return 0;
        }
    }
    ans=fresh(root<<1, x, d, u, flag);
    ans+=fresh((root<<1)+1, x, d, u, flag);
    return ans;
}
int main(int argc, const char * argv[]) {
    double x1,x2,y1,y2;
    int cas=0;
    while (scanf("%d",&n)!=EOF && n!=0) {
        for (int i=1; i<=n; i++)
        {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            y[2*i-1]=y1,y[2*i]=y2;
            li[2*i-1].y1=y1,li[2*i-1].y2=y2,li[2*i-1].x=x1,li[2*i-1].flag=1;
            li[2*i].y1=y1,li[2*i].y2=y2,li[2*i].x=x2,li[2*i].flag=-1;
        }
        sort(y+1,y+2*n+1);
        sort(li+1,li+2*n+1);
        build(1,1,2*n);
        double ans=0;
        for (int i=1; i<=2*n; i++)
            ans+=fresh(1, li[i].x, li[i].y1, li[i].y2, li[i].flag);
        printf("Test case #%d\nTotal explored area: %.2f\n\n",++cas,ans);
    }
    return 0;
}
