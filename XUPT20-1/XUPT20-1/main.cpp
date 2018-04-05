//
//  main.cpp
//  XUPT20-1
//
//  Created by 袁子涵 on 16/11/25.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <stack>
#include <utility>

using namespace std;
const int fix='a';
string str;
set<char>nxt[27];
bool vis[27];
bool fe[27];
bool dfs(char now)
{
    set<char>::iterator it=nxt[now-'a'].begin();
    vis[now-'a']=1;
    if (now=='m') {
        return 1;
    }
    for (; it!=nxt[now-'a'].end(); it++) {
        if (vis[*it-'a']) {
            if (fe[*it-'a']) {
                return 1;
            }
        }
        else
        {
            if(dfs(*it))
                return 1;
        }
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    string stop="0";
    while (cin >> str) {
        memset(vis, 0, sizeof(vis));
        memset(fe, 0, sizeof(fe));
        for (int i=0; i<27; i++) {
            nxt[i].clear();
        }
        if (str==stop) {
            cout << "No." << endl;
            continue;
        }
        char f,e;
        f=str[0];
        e=str[str.size()-1];
        nxt[f-fix].insert(e);
        while (cin >> str) {
            if (str==stop) {
                break;
            }
            char f,e;
            f=str[0];
            e=str[str.size()-1];
            nxt[f-fix].insert(e);
        }
        if (dfs('b')) {
            cout << "Yes." << endl;
        }
        else
            cout << "No." << endl;
    }
    return 0;
}
