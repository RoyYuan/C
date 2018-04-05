//
//  main.cpp
//  UOJ-Round 10-2
//
//  Created by 袁子涵 on 15/12/4.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include "worldline.h"
/* This is sample grader for the contestant */
#include <stdio.h>
#include <assert.h>

#define maxN 20010

static int t,flag,tot_query,tot_addedge,father[maxN],height[maxN];
static int A[maxN],ans[12][maxN],turn,step,n,res[12][5],N[12];

void next_step(){
    if (step!=1) flag=0; step++;
}

int findfather(int k){
    if (father[k]==k) return k;
    father[k]=findfather(father[k]);
    return father[k];
}

void link(int u,int v){
    u=findfather(u); v=findfather(v);
    if (u!=v){
        if (height[u]<height[v]){
            int t=u; u=v; v=t;
        }
        father[v]=u; if (height[u]==height[v]) height[u]++;
    }
}

void addedge(int u,int v){
    if (step!=1) flag=0; tot_addedge++;
    if (u<0||u>n||v<0||v>n) return;
    link(u,v);
}

int query(int u,int v){
    if (step!=2) flag=0; tot_query++;
    if (u<0||u>n||v<0||v>n) return 0;
    u+=n; v+=n;
    u=findfather(u); v=findfather(v);
    return u==v;
}

void new_round(){
    if (turn==2||(step!=2&&turn>0)) flag=0;
    turn++; step=1;
    for (int i=1;i<=n+n;i++) father[i]=i,height[i]=1;
    for (int i=1;i<=n;i++) link(i,A[i]+n);
}

int main()
{
    assert(scanf("%d",&t)==1);
    for (int now=1;now<=t;now++){
        assert(scanf("%d",&n)==1); N[now]=n;
        for (int i=1;i<=n;i++) assert(scanf("%d",&A[i])==1);
        flag=1; tot_query=0; tot_addedge=0; turn=0; step=0;
        res[now][1]=query_permutation(n,ans[now]);
        res[now][0]=flag; res[now][2]=tot_query; res[now][3]=tot_addedge;
        if (res[now][1]==0) for (int i=1;i<=n;i++) ans[now][i]=0;
    }
    for (int i=1;i<=t;i++){
        printf("%d %d %d %d\n",res[i][0],res[i][1],res[i][2],res[i][3]);
        for (int j=1;j<=N[i];j++) printf("%d ",ans[i][j]); printf("\n");
    }
    return 0;
}

using namespace std;
int query_permutation(int n, int ans[]);
void new_round();
void next_step();
void addedge(int u, int v);
int query(int u, int v);
int r[2][20005];
bool vis[2][20005];
int query_permutation(int n,int ans[])
{
    new_round();//第一轮
    memset(r, 0, sizeof(r));
    memset(vis, 0, sizeof(vis));
    if (n==2) {
        return 0;
    }
    if (n%2) {//总数为奇数时
        for (int i=1; i<n; i+=2) {
            addedge(i, i+1);
        }//将前面的配对
        next_step();//下一轮
        int tmp=0;//检查连通性
        for(int i=n+1;i<=2*n;i++){
            for (int j=i+1; j<=2*n; j++) {
                if (query(i-n, j-n)) {
                    r[0][i]=j;
                    r[0][j]=i;
                    vis[0][i]=1;
                    vis[0][j]=1;
                    tmp+=2;
                    break;
                }
            }
            if (tmp==n-1) {
                break;
            }
        }
        new_round();//新一轮
        //后面的配对
        for (int i=2; i<n; i+=2) {
            addedge(i, i+1);
        }
        next_step();
        tmp=0;
        for (int i=n+1; i<=2*n; i++) {
            for (int j=i+1; j<=2*n; j++) {
                if (query(i-n, j-n)) {
                    r[1][i]=j;
                    r[1][j]=i;
                    vis[1][i]=1;
                    vis[1][j]=1;
                    tmp+=2;
                    break;
                }
            }
            if (tmp==n-1) {
                break;
            }
        }
        for (int i=n+1; i<=2*n; i++) {
            if (vis[0][i]==0) {
                ans[n]=i-n;
            }
            if (vis[1][i]==0) {
                ans[1]=i-n;
            }
        }
        for (int i=2; i<=n-1; i++) {
            ans[i]=r[i%2][ans[i-1]+n]-n;
        }
        for (int i=1; i<=n; i++) {
            if (ans[i]<1 || ans[i]>n) {
                return 0;
            }
        }
        return 1;
    }
    else
    {
        for (int i=1; i<=n-2; i+=2) {
            addedge(i, i+1);
        }
        next_step();
        int tmp=0;
        for (int i=n+1; i<=2*n; i++) {
            for (int j=i+1; j<=2*n; j++) {
                if (query(i-n, j-n)) {
                    r[0][i]=j;
                    r[0][j]=i;
                    vis[0][i]=1;
                    vis[0][j]=1;
                    tmp+=2;
                    break;
                }
            }
            if (tmp==n-2) {
                break;
            }
        }
        new_round();
        for (int i=2; i<n; i+=2) {
            addedge(i, i+1);
        }
        next_step();
        tmp=0;
        for (int i=n+1; i<=2*n; i++) {
            for (int j=i+1; j<=2*n; j++) {
                if (query(i-n, j-n)) {
                    r[1][i]=j;
                    r[1][j]=i;
                    vis[1][i]=1;
                    vis[1][j]=1;
                    tmp+=2;
                    break;
                }
            }
            if (tmp==n-2) {
                break;
            }
        }
        int num[2][2],gong[4],total=0,t1=0,t2=0;
        for (int i=1+n; i<=2*n; i++) {
            if (vis[0][i]==0) {
                num[0][t1++]=i;
                gong[total++]=i;
            }
            if (vis[1][i]==0) {
                num[1][t2++]=i;
                gong[total++]=i;
            }
        }
        sort(gong+0,gong+4);
        for (int i=0; i<4; i++) {
            if (gong[i]==gong[i+1]) {
                ans[n]=gong[i]-n;
                break;
            }
        }
        for (int i=0; i<2; i++) {
            if (num[0][i]!=ans[n]+n) {
                ans[n-1]=num[0][i]-n;
            }
            if (num[1][i]!=ans[n]+n) {
                ans[1]=num[1][i]-n;
            }
        }
        for (int i=2; i<n-1; i++) {
            ans[i]=r[i%2][ans[i-1]+n]-n;
        }
        for (int i=1; i<=n; i++) {
            if (ans[i]<1 || ans[i]>n) {
                return 0;
            }
        }
        return 1;
    }
}
