//
//  main.cpp
//  基础DP1-C-Monkeys and Banana
//
//  Created by 袁子涵 on 15/10/23.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  0ms 1540KB

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>

using namespace::std;

typedef struct blocks
{
    int x,y,z;
}Blocks;

Blocks s[120];
int n,h[120];
bool visit[120];

int dp(int num)
{
    if (visit[num]) {
        return h[num];
    }
    int x=s[num].x,y=s[num].y,z=s[num].z;
    h[num]=z;
    for (int i=1; i<=3*n; i++) {
        if ((x<s[i].x && y<s[i].y) || (x<s[i].y && y<s[i].x)) {
            h[num]=max(h[num],dp(i)+z);
        }
    }
    visit[num]=1;
    return h[num];
}

int main(int argc, const char * argv[]) {
    int x,y,z,out,t=0;
    while (scanf("%d",&n)!=EOF && n!=0) {
        t++;
        out=0;
        for (int i=1; i<=3*n; i+=3) {
            scanf("%d%d%d",&x,&y,&z);
            s[i].x=x;s[i].y=y;s[i].z=z;
            s[i+1].x=x;s[i+1].y=z;s[i+1].z=y;
            s[i+2].x=y;s[i+2].y=z;s[i+2].z=x;
        }
        memset(h, 0, sizeof(h));
        memset(visit, 0, sizeof(visit));
        for (int i=1; i<=3*n; i++) {
            out=max(out,dp(i));
        }
        printf("Case %d: maximum height = %d\n",t,out);
    }
    return 0;
}
