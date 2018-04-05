//
//  main.cpp
//  160805-1
//
//  Created by 袁子涵 on 16/8/5.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cmath>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=505;
int dis[maxn][maxn],W[maxn],n,m,out,mincut,S,T;
bool A[maxn],combine[maxn];
void GetMinCut()
{
    int maxW,tmp;
    memset(W, 0, sizeof(W));
    memset(A, 0, sizeof(A));
    S=T=-1;
    for (int i=0; i<n; i++) {
        maxW=-INF;
        for (int j=0; j<n; j++) {
            if (!combine[j] && !A[j] && W[j]>maxW) {
                maxW=W[j];
                tmp=j;
            }
        }
        if (tmp==T)
            return;
        S=T;T=tmp;
        mincut=maxW;
        A[T]=1;
        for (int j=0; j<n; j++)
            if (!combine[j] && !A[j])
                W[j]+=dis[T][j];
    }
}
void Stoer_Wagner()
{
    memset(combine, 0, sizeof(combine));
    out=INF;
    for (int i=0; i<n-1; i++) {
        GetMinCut();
        out=min(out,mincut);
        combine[T]=1;
        for (int i=0; i<n; i++) {
            if (!combine[i]) {
                dis[S][i]+=dis[T][i];
                dis[i][S]+=dis[i][T];
            }
        }
    }
}
int main(int argc, const char * argv[])
{
    int u,v,w;
    while (~scanf("%d%d",&n,&m)) {
        memset(dis, 0, sizeof(dis));
        while (m--) {
            scanf("%d%d%d",&u,&v,&w);
            dis[u][v]+=w;
            dis[v][u]+=w;
        }
        Stoer_Wagner();
        printf("%d\n",out);
    }
    return 0;
}
