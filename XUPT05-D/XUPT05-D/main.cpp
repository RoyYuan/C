//
//  main.cpp
//  XUPT05-D
//
//  Created by 袁子涵 on 16/9/9.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <queue>
#include <set>

using namespace std;
multiset<int>S;
map<int,int>vis;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int q,num;
    char op;
    cin >> q;
    S.insert(0);
    for (int i=1; i<=q; i++) {
        cin >> op >> num;
        if (op=='+') {
            if (!vis[num])
                S.insert(num);
            vis[num]++;
        }
        else if (op=='-')
        {
            vis[num]--;
            if (!vis[num])
                S.erase(num);
        }
        else
        {
            int now=0;
            for (int i=30; i>=0; i--) {
                int tmp=(1<<i);
                if (!(num&tmp))
                    now|=tmp;
                multiset<int>::iterator it=S.lower_bound(now);
                if (it!=S.end() && *it<now+tmp)
                    continue;
                now^=tmp;
            }
            cout << (now^num) << endl;
        }
    }
    return 0;
}
