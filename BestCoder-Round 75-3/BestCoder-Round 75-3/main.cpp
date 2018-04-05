//
//  main.cpp
//  BestCoder-Round 75-3
//
//  Created by 袁子涵 on 16/3/12.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
long long int t;
int k,s[10];
bool vis[10],vis1[10];
int m[10][10]={{0,0,0,0,0,0,0,0,0,0},{0,0,0,2,0,0,0,4,0,5},{0,0,0,0,0,0,0,0,5,0},{0,2,0,0,0,0,0,5,0,6},{0,0,0,0,0,0,5,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,5,0,0,0,0,0},{0,4,0,5,0,0,0,0,0,8},{0,0,5,0,0,0,0,0,0,0},{0,5,0,6,0,0,0,8,0,0}};
int main(int argc, const char * argv[]) {
    cin >> t;
    while (t--) {
        bool flag=1;
        scanf("%d",&k);
        if (k<4)
            flag=0;
        memset(vis, 0, sizeof(vis));
        memset(vis1, 0, sizeof(vis1));
        for (int i=0; i<k; i++) {
            scanf("%d",&s[i]);
            if (vis[s[i]] || s[i]<1 || s[i]>9)
                flag=0;
            vis[s[i]]=1;
        }
        if (flag==0) {
            printf("invalid\n");
            continue;
        }
        for (int i=0; i<k-1; i++) {
            int now=s[i],next=s[i+1],node;
            node=m[now][next];
            if (node==0) {
                vis1[now]=1;
                continue;
            }
            else if (vis1[node]==0)
            {
                flag=0;
                break;
            }
        }
        if (flag) {
            printf("valid\n");
        }
        else
        {
            printf("invalid\n");
        }
    }
    return 0;
}
