//
//  main.cpp
//  160802-1
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
#include <vector>
#include <utility>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef struct point
{
    int x,y;
    bool operator <(const point &r)const
    {
        if (x==r.x)
            return y<r.y;
        return x<r.x;
    }
}point;
typedef struct stk
{
    int top;
    point data[105];
}stk;
typedef struct vt
{
    int x,y;
}vt;
int n,now;
stk s;
point node[105];
double out;
inline void stk_push(point now)
{
    s.data[s.top++]=now;
}
inline double point_dis(point a,point b,point c)
{
    vt tmp1,tmp2;
    tmp1.x=a.x-b.x;
    tmp1.y=a.y-b.y;
    tmp2.x=c.x-b.x;
    tmp2.y=c.y-b.y;
    double cc,ss;
    cc=(double)(tmp1.x*tmp2.x+tmp1.y*tmp2.y)/(sqrt((double)(tmp1.x*tmp1.x+tmp1.y*tmp1.y))*sqrt((double)(tmp2.x*tmp2.x+tmp2.y*tmp2.y)));
    ss=sqrt(1-cc*cc);
    return sqrt((double)(tmp1.x*tmp1.x+tmp1.y*tmp1.y))*ss;
}
inline int cross(point a,point b,point c)
{
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
int main(int argc, const char * argv[]) {
    int cas=0;
    while (scanf("%d",&n)!=EOF && n!=0) {
        cas++;
        s.top=0;
        for (int i=1; i<=n; i++)
            scanf("%d%d",&node[i].x,&node[i].y);
        sort(node+1,node+n+1);
        now=2;
        for (int i=1; i<=n; i++) {
            while (s.top>=now && cross(s.data[s.top-2], s.data[s.top-1], node[i])<0)
                s.top--;
            stk_push(node[i]);
        }
        now=s.top+1;
        for (int i=n-1; i>=1; i--) {
            while (s.top>=now && cross(s.data[s.top-2], s.data[s.top-1], node[i])<0)
                s.top--;
            stk_push(node[i]);
        }
        out=100005;
        double tmp=0;
        for (int i=0; i<s.top-1; i++) {
            tmp=0;
            for (int j=0; j<s.top-1; j++) {
                if (j==i || j==i+1 || (j==0 && i==s.top-2))
                    continue;
                tmp=max(tmp,point_dis(s.data[j], s.data[i], s.data[i+1]));
            }
            out=min(tmp,out);
        }
        printf("Case %d: %.2f\n",cas,out+0.005);
    }
    return 0;
}
