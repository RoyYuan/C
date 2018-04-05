//
//  main.cpp
//  24-6
//
//  Created by 袁子涵 on 16/4/24.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
int n,m;
string attemp[100];
int num[100];
bool vis[100];
int ri[100];
bool vis1[100][100];
typedef struct node
{
    int a,b;
}node;
int main(int argc, const char * argv[]) {
    while (cin >> n >> m) {
        memset(vis, 0, sizeof(vis));
        memset(vis1, 0, sizeof(vis1));
        memset(ri, 0, sizeof(ri));
        memset(attemp, 0, sizeof(attemp));
        memset(num, 0, sizeof(num));
        long long int left=1<<n;
        for (int i=0; i<m; i++)
            cin >> attemp[i] >> num[i];
        queue<node>q;
        while (!q.empty()) {
            q.pop();
        }
        for (int i=0; i<m; i++) {
            for (int j=i+1; j<m; j++) {
                int diff=0;
                for (int k=0; k<n; k++) {
                    if (attemp[i][k]!=attemp[j][k]) {
                        diff++;
                    }
                }
                if (diff==abs(num[i]-num[j])) {
                    q.push(node{i,j});
                }
            }
        }
        node tmp;
        while (!q.empty()) {
            tmp=q.front();
            vis1[tmp.a][tmp.b]=1;
            q.pop();
            for (int i=0; i<n; i++) {
                if (vis[i]) {
                    continue;
                }
                else
                {
                    if (attemp[tmp.a][i]!=attemp[tmp.b][i]) {
                        if (num[tmp.a]>num[tmp.b]) {
                            vis[i]=1;
                            ri[i]=attemp[tmp.a][i];
                        }
                        else
                        {
                            vis[i]=1;
                            ri[i]=attemp[tmp.b][i];
                        }
                    }
                }
            }
//            for (int i=0; i<m; i++) {
//                for (int j=0; j<n; j++) {
//                    if (vis[j] && attemp[i][j]==ri[j]) {
//                        num[i]--;
//                    }
//                }
//            }
            for (int i=0; i<m; i++) {
                int rit=0,wr=0;
                for (int j=0; j<n; j++) {
                    if (vis[j]) {
                        if (attemp[i][j]==ri[j]) {
                            rit++;
                        }
                        else
                            wr++;
                    }
                }
                if (rit==num[i]) {
                    for (int j=0; j<n; j++) {
                        if (!vis[j]) {
                            vis[j]=1;
                            ri[j]=(attemp[i][j]==1?0:1);
                        }
                    }
                }
                else if (wr==n-num[i])
                {
                    for (int j=0; j<n; j++) {
                        if (!vis[j]) {
                            vis[j]=1;
                            ri[j]=attemp[i][j];
                        }
                    }
                }
            }
            for (int i=0; i<m; i++) {
                for (int j=0; j<m; j++) {
                    int diff=0;
                    for (int k=0; k<n; k++) {
                        if (!vis[k] && attemp[i][k]!=attemp[j][k]) {
                            diff++;
                        }
                    }
                    if (diff==abs(num[i]-num[j]) && vis1[i][j]==0) {
                        q.push(node{i,j});
                    }
                }
            }
        }
        bool flag=0;
        for (int i=0; i<m; i++) {
            int tt=0;
            for (int j=0; j<n; j++) {
                if (vis[j] && attemp[i][j]==ri[j]) {
                    tt++;
                }
            }
            if (tt>num[i]) {
                flag=1;
                break;
            }
        }
        if (flag) {
            cout << 0 << endl;
            continue;
        }
        int now=n-1;
        for (int i=0; i<n; i++) {
            if (vis[i]) {
                left-=(1<<now);
                now--;
            }
        }
        cout << left << endl;
    }
    return 0;
}
