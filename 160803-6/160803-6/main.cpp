//
//  main.cpp
//  160803-6
//
//  Created by 袁子涵 on 16/8/3.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;
const int maxn=1000005;
int dp[maxn],max1[maxn],max2[maxn],fa[maxn],n,now;
int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    n++;
    for (int i=2; i<=n; i++) {
        scanf("%d",&fa[i]);
        dp[i]=1;
        now=i;
        while (now!=0) {
            if (dp[now]>max1[fa[now]]) {
                max2[fa[now]]=max1[fa[now]];
                max1[fa[now]]=dp[now];
            }
            else
                max2[fa[now]]=max(max2[fa[now]],dp[now]);
            now=fa[now];
            int tmp=max(max1[now],max2[now]+1);
            if (tmp==dp[now])
                break;
            dp[now]=tmp;
        }
        printf("%d ",max1[1]);
    }
    return 0;
}
