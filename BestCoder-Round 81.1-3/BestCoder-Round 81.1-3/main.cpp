//
//  main.cpp
//  BestCoder-Round 81.1-3
//
//  Created by 袁子涵 on 16/4/22.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#define MAXN 1000005
using namespace std;
string s;
int k,t,tmp;
vector<long long int>plz[27];
long long int out,now,tail;
bool vis[27];
int main(int argc, const char * argv[]) {
    cin >> t;
    while (t--) {
        cin >> s >> k;
        long long int length=s.size();
        for (int i=0; i<26; i++)
            plz[i].clear();
        memset(vis, 0, sizeof(vis));
        for (long long int i=0; i<length; i++)
            plz[s[i]-'a'].push_back(i);
        for (long long int i=0; i<length; i++)
            sort(plz[i].begin(), plz[i].end());
        now=out=0;
        for (long long int i=0; i<length; i++) {
            if (!vis[s[i]-'a']) {
                now++;
                vis[s[i]-'a']=1;
                if (now==k) {
                    tail=i;
                    break;
                }
            }
        }
        if (now<k) {
            cout << 0 << endl;
            continue;
        }
        out+=length-tail;
        for (long long int i=1; i<=length-k; i++) {
            vis[s[i-1]-'a']=0;
            bool flag=0,fflag=0;
            for (long long int j=i; j<=tail; j++) {
                if (s[j]==s[i-1]) {
                    flag=1;
                    vis[s[i-1]-'a']=1;
                    break;
                }
            }
            if (flag) {
                out+=length-tail;
            }
            else
            {
                long long int l=0,r=plz[s[i-1]-'a'].size()-1;
                if (plz[s[i-1]-'a'][r]<=tail) {
                    fflag=1;
                }
                else
                {
                    while (l<=r) {
                        long long int tmp=(l+r)/2;
                        if (plz[s[i-1]-'a'][tmp]<tail) {
                            l=tmp+1;
                        }
                        else
                            r=tmp-1;
                    }
                    tail=plz[s[i-1]-'a'][l];
                    out+=length-tail;
                }
            }
            if (fflag) {
                for (long long int j=tail+1; j<length; j++) {
                    if (!vis[s[j]-'a']) {
                        tail=j;
                        out+=length-tail;
                        vis[s[j]-'a']=1;
                        break;
                    }
                }
            }
        }
        cout << out << endl;
    }
    return 0;
}
