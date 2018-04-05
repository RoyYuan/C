//
//  main.cpp
//  XUPT19-4
//
//  Created by 袁子涵 on 16/11/24.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;
const int maxn=2e5+5;
int a[maxn];
int ans[maxn];
vector<pair<int, int>>down[maxn];
int n;
vector<pair<int,int>>edge[maxn];
void dfs(int num,int U)
{
    for (int i=0; i<edge[num].size(); i++) {
        dfs(edge[num][i].first,edge[num][i].second);
        for (int j=0; j<down[edge[num][i].first].size(); j++)
            if (down[edge[num][i].first][j].second+edge[num][i].second<=a[down[edge[num][i].first][j].first])
                down[num].push_back(make_pair(down[edge[num][i].first][j].first, down[edge[num][i].first][j].second+edge[num][i].second));
        down[edge[num][i].first].clear();
        if (a[edge[num][i].first]>=edge[num][i].second)
            down[num].push_back(make_pair(edge[num][i].first, edge[num][i].second));
    }
    ans[num]=down[num].size();
    return;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int p,d;
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=2; i<=n; i++) {
        cin >> p >> d;
        edge[p].push_back(make_pair(i, d));
    }
    dfs(1,0);
    for (int i=1; i<=n; i++)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}
//int father[maxn],dis[maxn];
////int ans[maxn];
//int main(int argc, const char * argv[]) {
//    ios::sync_with_stdio(false);
//    cin >> n;
//    for (int i=1; i<=n; i++) {
//        cin >> a[i];
//    }
//    for (int i=2; i<=n; i++) {
//        cin >> father[i] >> dis[i];
//    }
//    father[1]=-1,dis[1]=0;
//    for (int i=2; i<=n; i++) {
//        int now=dis[i],num=father[i];
//        while (num>0 && now<=a[i]) {
//            now+=dis[num];
//            ans[num]++;
//            num=father[num];
//        }
//    }
//    for (int i=1; i<=n; i++) {
//        cout << ans[i] << ' ';
//    }
//    cout << endl;
//    return 0;
//}