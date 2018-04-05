//
//  main.cpp
//  160803-3
//
//  Created by 袁子涵 on 16/8/3.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
const int MAXN=100005;
int n,q,times[MAXN],plz[MAXN],now,last,f[MAXN][20],l[MAXN],r[MAXN];
void init()
{
    for (int i=1; i<=now; i++)
        f[i][0]=times[i];
    int k=floor((double)log(now)/log(2.0));
    for (int j=1; j<=k; j++)
        for (int i=1; i+(1<<(j-1))<=now; i++)
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
int getmax(int l,int r)
{
    int k=0,x=2,range=r-l+1;
    while (x<=range) {
        k++;
        x<<=1;
    }
    return max(f[l][k],f[r-(1<<k)+1][k]);
}
int main(int argc, const char * argv[]) {
    int x,y,out,num;
    while (scanf("%d",&n)!=EOF && n!=0) {
        now=0,last=1000005;
        scanf("%d",&q);
        for (int i=1; i<=n; i++) {
            scanf("%d",&num);
            if (num==last)
            {
                times[now]++;
                r[now]=i;
                plz[i]=now;
            }
            else
            {
                times[++now]=1;
                l[now]=r[now]=i;
                plz[i]=now;
                last=num;
            }
        }
        init();
        for (int i=1; i<=q; i++) {
            scanf("%d%d",&x,&y);
            if (plz[x]==plz[y])
                out=y-x+1;
            else if (plz[y]==plz[x]+1)
                out=max(r[plz[x]]-x,y-l[plz[y]])+1;
            else
            {
                out=max(r[plz[x]]-x,y-l[plz[y]])+1;
                out=max(out,getmax(plz[x]+1,plz[y]-1));
            }
            printf("%d\n",out);
        }
    }
    return 0;
}
