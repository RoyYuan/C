//
//  main.cpp
//  160910-1
//
//  Created by 袁子涵 on 16/9/10.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <utility>

using namespace std;
const int maxn=200005;
vector<int>edge[maxn];
set<int>S;
int out[maxn],n,m,s;
typedef struct Node
{
    int num,step;
}Node;
int main(int argc, const char * argv[]) {
    int t,u,v;
    scanf("%d",&t);
    set<int>::iterator it,last;
    while (t--) {
        S.clear();
        scanf("%d%d",&n,&m);
        for (int i=1; i<=n; i++)
        {
            S.insert(i);
            edge[i].clear();
        }
        for (int i=1; i<=m; i++) {
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        for (int i=1; i<=n; i++)
            sort(edge[i].begin(),edge[i].end());
        scanf("%d",&s);
        queue<Node>Q;
        Node now,tt;
        now.num=s,now.step=0;
        S.erase(s);
        while (!Q.empty())
            Q.pop();
        Q.push(now);
        while (!Q.empty()) {
            now=Q.front();
            Q.pop();
            out[now.num]=now.step;
            if (edge[now.num].size()) {
                int tmp;
                it=S.begin();
                for (int i=0; i<edge[now.num].size(); i++) {
                    tmp=edge[now.num][i];
                    for (; it!=S.end() && *it<tmp;) {
                        tt.num=*it;
                        tt.step=now.step+1;
                        Q.push(tt);
                        last=it;
                        it++;
                        S.erase(last);
                    }
                    if (it!=S.end() && *it==tmp)
                        it++;
                }
                for (; it!=S.end();) {
                    tt.num=*it;
                    tt.step=now.step+1;
                    Q.push(tt);
                    last=it;
                    it++;
                    S.erase(last);
                }
            }
            else
            {
                for (it=S.begin(); it!=S.end();) {
                    tt.num=*it;
                    tt.step=now.step+1;
                    last=it;
                    it++;
                    S.erase(last);
                    Q.push(tt);
                }
            }
        }
        int total=0;
        for (int i=1; i<=n; i++) {
            if (i!=s) {
                if (out[i])
                    printf("%d",out[i]);
                else
                    printf("-1");
                total++;
                
                if (total!=n-1) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
