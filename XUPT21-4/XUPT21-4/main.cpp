//
//  main.cpp
//  XUPT21-4
//
//  Created by 袁子涵 on 16/12/1.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;
const int maxn=1e5+5;
int t;
typedef struct seg
{
    int l,r;
    bool operator <(const seg &x)const
    {
        return l<x.l;
    }
}seg;
seg S[maxn];
bool vis[maxn];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        memset(vis, 0, sizeof(vis));
        int l,r,total=0;
        while (cin >> l >> r) {
            if (l==0 && r==0) {
                break;
            }
            if (r<=0) {
                continue;
            }
            S[++total].l=l;
            S[total].r=r;
        }
        sort(S+1,S+total+1);
        int R=-0x3f3f3f3f,now=0,nowR=-1,ans=0;
        bool flag=0;
        for (int i=1; i<=total; i++) {
            if (S[i].l<=0) {
                flag=1;
                while (S[i].l<=0 && i<=total) {
                    if (S[i].r>=R) {
                        now=i;
                        R=S[i].r;
                    }
                    i++;
                }
                vis[now]=1;
                nowR=R;
                ans=1;
                i--;
            }
            else
            {
                if (flag==0) {
                    break;
                }
                while (S[i].l<=nowR && i<=total) {
                    if (S[i].r>=R) {
                        now=i;
                        R=S[i].r;
                        if (R>=m)
                            break;
                    }
                    i++;
                }
                vis[now]=1;
                nowR=R;
                ans++;
                if (nowR>=m) {
                    break;
                }
                i--;
            }
        }
        if (flag==0 || nowR<m) {
            cout << 0 << endl;
        }
        else
        {
            cout << ans << endl;
            for (int i=1; i<=total; i++) {
                if (vis[i]) {
                    cout << S[i].l << ' ' << S[i].r << endl;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
