//
//  main.cpp
//  XUPT18-1
//
//  Created by 袁子涵 on 16/11/18.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;
map<long long int,long long int>from;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    long long int a,b;
    cin >> a >> b;
    if (a>b) {
        cout << "NO" << endl;
        return 0;
    }
    queue<long long int>q;
    while (!q.empty()) {
        q.pop();
    }
    q.push(a);
    from[a]=-1;
    while (!q.empty()) {
        long long int tmp=q.front();
        q.pop();
        if (tmp*2<=b) {
            q.push(tmp*2);
            from[tmp*2]=tmp;
        }
        if (tmp*10+1<=b) {
            q.push(tmp*10+1);
            from[tmp*10+1]=tmp;
        }
    }
    if (from[b]!=0) {
        cout << "YES" << endl;
        long long int st[10000],now=b,total=0;
        st[1]=b;
        while (from[now]!=-1) {
            st[++total]=now;
            now=from[now];
        }
        st[++total]=a;
        cout << total << endl;
        for (long long int i=total; i>=1; i--) {
            cout << st[i] << " ";
        }
        cout << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
