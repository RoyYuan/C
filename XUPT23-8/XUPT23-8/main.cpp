//
//  main.cpp
//  XUPT23-8
//
//  Created by 袁子涵 on 17/2/13.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int sum,limit;
vector<int>out;
typedef struct num
{
    int num,bit;
    bool operator <(const struct num &r)const
    {
        return bit<r.bit;
    }
}num;
num node[100005];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> sum >> limit;
    for (int i=1; i<=limit; i++) {
        node[i].num=i;
        node[i].bit=(i&(-i));
    }
    sort(node+1, node+limit+1);
    int now=0;
    for (int i=limit; i>0; i--) {
        if (now+node[i].bit<=sum) {
            now+=node[i].bit;
            out.push_back(node[i].num);
        }
    }
    if (now!=sum) {
        cout << -1 << endl;
    }
    else
    {
        cout << out.size() << endl;
        for (int i=0; i<out.size(); i++) {
            cout << out[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
