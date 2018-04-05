//
//  main.cpp
//  160807-3
//
//  Created by 袁子涵 on 16/8/7.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
using namespace std;
const int maxn=1e6+1e4;
int lose[maxn],plz[maxn],n,m;
bool vis[maxn*2];
map<pair<int,int>,bool>Vis;
int main(int argc, const char * argv[]) {
    int last=0,total=0;
    bool flag=0;
    for (int i=1; i<=maxn; i++) {
        flag=0;
        for (int j=last+1; j<=maxn; j++) {
            if (vis[j])
                continue;
            last=j;
            flag=1;
            break;
        }
        if (!flag) {
            total=i-1;
            break;
        }
        plz[i]=last;
        lose[last]=last+i;
        vis[last]=vis[last+i]=1;
    }
    while (scanf("%d%d",&n,&m)!=EOF && (n!=0 || m!=0)) {
        Vis.clear();
        if (n>m)
            swap(n, m);
        if (m==lose[n]) {
            puts("0");
            continue;
        }
        else
        {
            puts("1");
            if (n==m)
            {
                puts("0 0");
                Vis[make_pair(0, 0)]=1;
            }
            else if (m>=plz[m-n]+m-n && n>=plz[m-n] && Vis[make_pair(plz[m-n], plz[m-n]+m-n)]==0)
            {
                printf("%d %d\n",plz[m-n],plz[m-n]+m-n);
                Vis[make_pair(plz[m-n], plz[m-n]+m-n)]=1;
            }
            for (int i=1; i<=total; i++) {
                if (n==plz[i] && Vis[make_pair(plz[i], plz[i]+i)]==0 && m>plz[i]+i) {
                    Vis[make_pair(plz[i], plz[i]+i)]=1;
                    printf("%d %d\n",plz[i],plz[i]+i);
                }
                if (n==plz[i]+i && Vis[make_pair(plz[i], plz[i]+i)]==0)
                {
                    printf("%d %d\n",plz[i],plz[i]+i);
                    break;
                }
            }
        }
    }
    return 0;
}
