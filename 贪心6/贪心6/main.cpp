//
//  main.cpp
//  贪心6
//
//  Created by 袁子涵 on 17/2/21.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <list>
#include <map>
#include <stack>
using namespace::std;
const int maxn=2e5+5;
int n;
queue<int>ans;
stack<int>st[maxn];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> n;
    int tmp;
    for (int i=1; i<=n; i++) {
        cin >> tmp;
        st[tmp].push(i);
    }
    int now=0;
    while (1) {
        if (st[now].empty()) {
            if (now<3) {
                break;
            }
            else
            {
                for (int i=1; i<4; i++) st[now-i].pop();
                now-=3;
            }
        }
        else
        {
            ans.push(st[now].top());
            now++;
        }
    }
    if (ans.size()==n) {
        cout << "Possible" << endl;
        for (int i=0; i<n; i++) {
            cout << ans.front() << " ";
            ans.pop();
        }
    }
    else
        cout << "Impossible" << endl;
    return 0;
}
