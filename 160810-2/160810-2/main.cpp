//
//  main.cpp
//  160810-2
//
//  Created by 袁子涵 on 16/8/10.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <stack>
using namespace std;
const int MAXN = 1e5+10;
const int INF = 0x7fffffff;
struct Point
{
    long long int x,y,num;
};
long long int out,ans;
long long int a,b,outa,outb;
long long int dist(Point a,Point b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
Point p[MAXN],pp[MAXN];
Point tmpt[MAXN];
bool cmpxy(Point a,Point b) {
    if(a.x != b.x)
        return a.x < b.x;
    else
        return a.y < b.y;
}
bool cmpy(Point a,Point b) {
    return a.y < b.y;
}
long long int Closest_Pair(long long int left,long long int right) {
    long long int d= INF;
    if(left == right)
        return d;
    if(left + 1 == right)
    {
        d=dist(p[left],p[right]);
        if (d<out) {
            out=d;
            a=p[left].num,b=p[right].num;
        }
        return d;
    }
    long long int mid = (left+right)>>1;
    long long int d1 = Closest_Pair(left,mid);
    long long int d2 = Closest_Pair(mid+1,right);
    d=min(d1,d2);
    long long int k = 0;
    for(long long int i = left;i <= right;i++) {
        if(abs(p[mid].x - p[i].x) <= d)
            tmpt[k++] = p[i];
    }
    sort(tmpt,tmpt+k,cmpy);
    for(long long int i = 0;i <k;i++) {
        for(long long int j = i+1;j < k && tmpt[j].y - tmpt[i].y < d;j++) {
            if (d>dist(tmpt[i],tmpt[j])) {
                d=dist(tmpt[i],tmpt[j]);
                if (d<out) {
                    a=tmpt[i].num,b=tmpt[j].num;
                    out=d;
                }
            }
        }
    }
    return d;
}
int main(int argc, const char * argv[]) {
    long long int t,n,now;
    long long int out1;
    scanf("%lld",&t);
    while (t--) {
        out=INF;
        scanf("%lld",&n);
        for (long long int i=0; i<n; i++)
        {
            scanf("%lld%lld",&pp[i].x,&pp[i].y);
            pp[i].num=i;
        }
        sort(pp, pp+n, cmpxy);
        for (long long int i=0; i<n; i++)
            p[i]=pp[i];
        out1=Closest_Pair(0, n-1);
        outa=a,outb=b;
        ans=out1*(n-2);
        now=0;
        for (long long int i=0; i<n; i++) {
            if (pp[i].num==outa)
                continue;
            p[now++]=pp[i];
        }
        ans+=Closest_Pair(0, now-1);
        now=0;
        for (long long int i=0; i<n; i++) {
            if (pp[i].num==outb)
                continue;
            p[now++]=pp[i];
        }
        ans+=Closest_Pair(0, now-1);
        printf("%lld\n",ans);
    }
    return 0;
}
