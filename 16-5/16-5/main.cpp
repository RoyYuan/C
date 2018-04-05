//
//  main.cpp
//  16-5
//
//  Created by 袁子涵 on 16/4/16.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int t,casenum;
long long int n,tmp1,tmp2;
vector<long long int>to[50005];
long long int du[50005];
typedef struct node
{
    long long int num;
    bool operator <(const node &r) const
    {
        if(du[num]<du[r.num])
            return 0;
        if(du[num]==du[r.num])
            return r.num<num;
        return 1;
    }
}node;

node Node[50005];
bool vis[50005];
void init()
{
    for (long long int i=0; i<=n; i++) {
        Node[i].num=i;
        to[i].clear();
    }
    memset(du, 0, sizeof(du));
    memset(vis, 0, sizeof(vis));
}
int main(int argc, const char * argv[]) {
    cin >> t;
    casenum=0;
    node tmp;
    while (t--) {
        casenum++;
        cin >> n;
        init();
        for (long long int i=1; i<n; i++) {
            scanf("%lld %lld",&tmp1,&tmp2);
            du[tmp1]++,du[tmp2]++;
            to[tmp1].push_back(tmp2);
            to[tmp2].push_back(tmp1);
        }
        priority_queue<node>q;
        for (long long int i=1; i<=n; i++) {
            q.push(Node[i]);
        }
        cout << "Case #" << casenum << ": ";
        while (q.size()!=2) {
            tmp=q.top();
            q.pop();
            vis[tmp.num]=1;
            long long int temp=to[tmp.num][0];
            cout << temp;
            du[temp]--;
            du[tmp.num]--;
            for (int i=0; i<to[temp].size(); i++) {
                if (to[temp][i]==tmp.num) {
                    vector<long long int>::iterator it=to[temp].begin()+i;
                    to[temp].erase(it);
                    break;
                }
            }
            while (!q.empty()) {
                q.pop();
            }
            for (int i=1; i<=n; i++) {
                if (vis[i]==0) {
                    q.push(Node[i]);
                }
            }
        }
        cout << endl;
    }
    return 0;
}
