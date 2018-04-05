//
//  main.cpp
//  RE-4-1
//
//  Created by 袁子涵 on 17/8/5.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const long long int INF=0x7fffffffffffffff;
const int maxn=1e3+5;
const int maxnn=1e5+5;
typedef struct skill
{
    long long int k,p;
    bool operator <(const skill &r)const
    {
        return p>r.p;
    }
}Sk;
Sk S[maxn];
long long int n,m,a[maxnn],b[maxnn],maxp,maxa,maxb;
long long int ans,tmp,tt;
long long int DP[11][2*maxn];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    while (cin >> n >> m) {
        maxa=maxb=maxp=0;
        ans=0;
        memset(DP, -1, sizeof(DP));
        for (int i=0; i<n; i++) {
            cin >> a[i] >> b[i];
            maxa=max(maxa,a[i]);
            maxb=max(maxb,b[i]);
        }
        for (int i=0; i<m; i++) {
            cin >> S[i].k >> S[i].p;
            maxp=max(maxp,S[i].p);
        }
        sort(S+0,S+m);
        for (long long int i=0; i<=maxb; i++) {
            DP[i][0]=0;
            tmp=INF;
            for (int j=0; j<maxa; j++) {
                if (DP[i][j]==-1)
                    continue;
                for (int x=0; x<m; x++) {
                    if (S[x].p<=i)
                        break;
                    tt=j+S[x].p-i;
                    if (DP[i][tt]==-1)
                        DP[i][tt]=DP[i][j]+S[x].k;
                    else
                        DP[i][tt]=min(DP[i][tt],DP[i][j]+S[x].k);
                }
            }
            for (long long int j=maxa+maxp; j>=0; j--) {
                if (tmp==INF && DP[i][j]==-1)
                    continue;
                if (DP[i][j]!=-1)
                    tmp=min(tmp,DP[i][j]);
                DP[i][j]=tmp;
            }
        }
        bool flag=0;
        for (long long int i=0; i<n; i++)
        {
            if (DP[b[i]][a[i]]==-1) {
                cout << -1 << endl;
                flag=1;
                break;
            }
            ans+=DP[b[i]][a[i]];
        }
        if (flag)
            continue;
        cout << ans << endl;
    }
    return 0;
}
