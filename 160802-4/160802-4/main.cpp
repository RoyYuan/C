//
//  main.cpp
//  160802-4
//
//  Created by 袁子涵 on 16/8/2.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace::std;
const double eps = 1e-17;
typedef struct man
{
    int a,b,c;
}man;
man Man[105];
struct node
{
    double x;
    double y;
};

node p[105];
int n,m;
double a,b,c;
int sgn(double x)
{
    if(fabs(x) < eps)return 0;
    if(x < 0)return -1;
    else return 1;
}
node Intersection(node p1,node p2,double a,double b,double c)
{
    double u = fabs(a*p1.x + b*p1.y + c);
    double v = fabs(a*p2.x + b*p2.y + c);
    node t;
    t.x = (p1.x*v + p2.x*u)/(u+v);
    t.y = (p1.y*v + p2.y*u)/(u+v);
    return t;
}
node tp[110];
void Cut(double a,double b,double c,node p[],int &cnt)
{
    int tmp = 0;
    for(int i = 1;i <= cnt;i++)
    {
        if(a*p[i].x + b*p[i].y + c < eps)tp[++tmp] = p[i];
        else
        {
            if(a*p[i-1].x + b*p[i-1].y + c < -eps)
                tp[++tmp] = Intersection(p[i-1],p[i],a,b,c);
            if(a*p[i+1].x + b*p[i+1].y + c < -eps)
                tp[++tmp] = Intersection(p[i],p[i+1],a,b,c);
        }
    }
    for(int i = 1;i <= tmp;i++)
        p[i] = tp[i];
    p[0] = p[tmp];
    p[tmp+1] = p[1];
    cnt = tmp;
}
double CalcArea(node p[],int n)
{
    double res = 0;
    for(int i = 0;i < n;i++)
        res += (p[i].x*p[(i+1)%n].y-p[i].y*p[(i+1)%n].x);
    return fabs(res/2);
}
bool solve(int num)
{
    double da,db,dc;
    p[1]=(node) {0,0};
    p[2]=(node) {100005,0};
    p[3]=(node) {100005,100005};
    p[4]=(node) {0,100005};
    p[0]=p[4];
    p[5]=p[1];
    m=4;
    for(int i=1;i<=n;i++)
    {
        if (i==num)
            continue;
        da=(double)(-Man[num].a+Man[i].a)/(Man[num].a*Man[i].a);
        db=(double)(-Man[num].b+Man[i].b)/(Man[num].b*Man[i].b);
        dc=(double)(-Man[num].c+Man[i].c)/(Man[num].c*Man[i].c);
        if (sgn(da)==0 && sgn(db)==0 && sgn(dc)>=0)
            return 0;
        Cut(da, db, dc, p, m);
    }
    if (sgn(CalcArea(p, m))==0)
        return 0;
    return 1;
}

int main(int argc, const char * argv[])
{
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
        scanf("%d%d%d",&Man[i].a,&Man[i].b,&Man[i].c);
    for (int i=1; i<=n; i++) {
        if (solve(i))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}