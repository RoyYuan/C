//
//  main.cpp
//  长大15acm-I
//
//  Created by 袁子涵 on 15/12/7.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;
struct cor
{
    int degree,min,sec;
};
int n;
struct cor c[20];
double edge[20];
bool flag=0,vis[20];
struct cor total,f,tmp;
struct edge
{
    int u,v;
    double w;
};
struct edge E[20];
void update(struct cor *x)
{
    if (x->sec>=60) {
        x->min+=x->sec/60;
        x->sec%=60;
    }
    if (x->min>=60) {
        x->degree+=x->min/60;
        x->min%=60;
    }
}
bool cmp(struct cor a,struct cor b)
{
    if (a.degree>b.degree)
        return 1;
    if (a.min>b.min)
        return 1;
    if (a.sec>b.sec)
        return 1;
    return 0;
}
bool limit()
{
    tmp.degree=tmp.min=tmp.sec=0;
    if (total.degree<(n-2)*180) {
        tmp.degree=(n-2)*180-total.degree-1;
        tmp.min=60-total.min-1;
        tmp.sec=60-total.sec;
        flag=1;
    }
    else
    {
        tmp.degree=total.degree-(n-2)*180;
        tmp.min=total.min;
        tmp.sec=total.sec;
        flag=0;
    }
    update(&tmp);
    if (cmp(f, tmp))
        return 0;
    return 1;
}
void getback(struct cor *a)
{
    a->sec+=a->degree*3600+a->min*60;
    a->degree=a->min=0;
}
bool comp(struct edge a,struct edge b)
{
    return a.w<b.w;
}
int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        total.sec=total.min=total.degree=0;
        memset(vis, 0, sizeof(vis));
        f.sec=f.min=f.degree=0;
        for (int i=1; i<=n; i++)
        {
            scanf("%d%d%d",&c[i].degree,&c[i].min,&c[i].sec);
            total.sec+=c[i].sec;
            total.min+=c[i].min;
            total.degree+=c[i].degree;
        }
        update(&total);
        for (int i=1; i<=n; i++)
        {
            scanf("%lf",&edge[i]);
            if (i==n) {
                E[i].u=n;
                E[i].v=1;
                E[i].w=edge[i];
            }
            else
            {
                E[i].u=i;
                E[i].v=i+1;
                E[i].w=edge[i];
            }
        }
        f.sec=40*sqrt((double)n);
        update(&f);
        if(limit())
        {
            cout << "Poor Prince Cao Tan" << endl;
            continue;
        }
        getback(&tmp);
        long long int fix=tmp.sec/n;
        tmp.sec%=n;
        for (int i=1; i<=n; i++) {
            if (flag)
                c[i].sec+=fix;
            else
                c[i].sec-=fix;
            update(&c[i]);
        }
        if (tmp.sec) {
            sort(E+1, E+n+1, comp);
            for (int i=1; i<=tmp.sec; i++) {
                struct edge tt=E[i];
                int pp,pt;
                if ((edge[tt.u-1]<edge[tt.v] && vis[tt.u]==0) || vis[tt.v]) {
                    pp=tt.u;
                    pt=tt.v;
                }
                else
                {
                    pp=tt.v;
                    pt=tt.u;
                }
                if (flag)
                    c[pp].sec+=1;
                else
                    c[pp].sec-=1;
                vis[pp]=1;
                update(&c[pp]);
                if(tmp.sec-1 && vis[pt]==0)
                {
                    if (flag)
                        c[pt].sec+=1;
                    else
                        c[pt].sec-=1;
                    tmp.sec--;
                }
            }
        }
        for (int i=1; i<=n; i++)
            printf("%d %d %d\n",c[i].degree,c[i].min,c[i].sec);
    }
    return 0;
}
