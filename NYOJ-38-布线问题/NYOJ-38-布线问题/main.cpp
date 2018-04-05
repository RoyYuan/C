//
//  main.cpp
//  NYOJ-38-布线问题
//
//  Created by 袁子涵 on 15/11/25.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  52ms    1252KB

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <stdlib.h>

#define MAXS 0x7fffffff
using namespace std;

const int MAXN=510;
bool vis[MAXN];
long long int lowc[MAXN];
int cost[MAXN][MAXN];
long long int Prim(long long int n)
{
    long long int ans=0;
    memset(vis, 0, sizeof(vis));
    vis[0]=1;
    for (int i=1; i<n; i++)
        lowc[i]=cost[0][i];
    for (int i=1; i<n; i++) {
        long long int minc=MAXS;
        int p=-1;
        for (int j=0; j<n; j++)
            if (!vis[j] && minc>lowc[j]) {
                minc=lowc[j];
                p=j;
            }
        if (minc == MAXS)
            return -1;
        ans+=minc;
        vis[p]=1;
        for (int j=0; j<n; j++) {
            if (!vis[j] && lowc[j]>cost[p][j])
                lowc[j]=cost[p][j];
        }
    }
    return ans;
}



int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    while (n--) {
        int v,e,a,b,c;
        cin >> v >> e;
        for (int i=0; i<v; i++) {
            for (int j=0; j<v; j++) {
                if (i==j) {
                    cost[i][j]=0;
                }
                else
                    cost[i][j]=MAXS;
            }
        }
        for (int i=1; i<=e; i++) {
            scanf("%d %d %d",&a,&b,&c);
            cost[a-1][b-1]=min(cost[a-1][b-1],c);
            cost[b-1][a-1]=min(cost[b-1][a-1],c);
        }
        long long int sum=Prim(v);
        int temp=MAXS;
        for (int i=1; i<=v; i++) {
            scanf("%d",&a);
            temp=min(temp,a);
        }
        sum+=temp;
        cout << sum << endl;
    }
    return 0;
}
