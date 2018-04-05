//
//  main.cpp
//  BestCoder-Round 69.2-3
//
//  Created by 袁子涵 on 16/1/23.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

typedef struct
{
    int x,y;
    long long int num;
    int next[5];
    char op[5];
}node;

char map[30][30];
int n,m,t,now,l,nowx,nowy,num;
long long int sum;
bool flag=0;
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
node Node[16];
bool vis[16];

int plaz(int x,int y)
{
    int num=0;
    num+=(x/2)*l;
    num+=y/2;
    return num;
}

bool check(int x,int y)
{
    if (x<0 || x>=n || y<0 || y>=m) {
        return 0;
    }
    return 1;
}

bool dfs(int x,double tmp)
{
    double temp=tmp;
    if (fabs(tmp-(double)sum)<=tmp*0.01) {
        flag=1;
        return 1;
    }
    for (int i=0; i<4; i++) {
        if (Node[x].next[i]!=-1 && vis[Node[x].next[i]]!=1) {
            temp=tmp;
            switch (Node[x].op[i]) {
                case '+':
                    temp+=Node[Node[x].next[i]].num;
                    break;
                case '-':
                    temp-=Node[Node[x].next[i]].num;
                    break;
                case '*':
                    temp*=Node[Node[x].next[i]].num;
                    break;
                case '/':
                    temp/=Node[Node[x].next[i]].num;
                    break;
                default:
                    break;
            }
            if (Node[x].op[i]=='/' && Node[Node[x].next[i]].num==0) {
                continue;
            }
            vis[Node[x].next[i]]=1;
            if(dfs(Node[x].next[i],temp))
                return 1;
            vis[Node[x].next[i]]=0;
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    scanf("%d",&t);
    while (t--) {
        now=0;
        flag=0;
        memset(map, 0, sizeof(map));
        memset(Node, 0, sizeof(Node));
        memset(vis, 0, sizeof(vis));
        scanf("%d%d%lld",&n,&m,&sum);
        l=(m+1)/2;
        num=l*((n+1)/2);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> map[i][j];
            }
        }
        for (int i=0; i<n; i+=2) {
            for (int j=0; j<m; j+=2) {
                Node[now].num=map[i][j]-'0';
                Node[now].x=i;
                Node[now].y=j;
                for (int k=0; k<4; k++) {
                    Node[now].next[k]=-1;
                }
                now++;
            }
        }
        for (int i=0; i<num; i++) {
            for (int k=0; k<4; k++) {
                nowx=Node[i].x+dir[k][0]*2;
                nowy=Node[i].y+dir[k][1]*2;
                if (check(nowx, nowy)) {
                    Node[i].next[k]=plaz(nowx, nowy);
                    nowx-=dir[k][0];
                    nowy-=dir[k][1];
                    Node[i].op[k]=map[nowx][nowy];
                }
            }
        }
        for (int i=0; i<num; i++) {
            vis[i]=1;
            if (dfs(i,Node[i].num)) {
                break;
            }
            vis[i]=0;
        }
        if (flag) {
            printf("Possible\n");
        }
        else
        {
            printf("Impossible\n");
        }
    }
    return 0;
}
