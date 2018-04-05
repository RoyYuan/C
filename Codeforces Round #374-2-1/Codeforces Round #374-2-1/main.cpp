//
//  main.cpp
//  Codeforces Round #374-2-1
//
//  Created by 袁子涵 on 16/9/30.
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
vector<int>out;
int main(int argc, const char * argv[]) {
    int n,last=0;
    char tmp;
    cin >> n;
    while (n--) {
        cin >> tmp;
        if (tmp=='B') {
            last++;
        }
        else
        {
            if (last==0) {
                continue;
            }
            else
            {
                out.push_back(last);
                last=0;
            }
        }
    }
    if (last)
        out.push_back(last);
    else if (out.size()==0)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << out.size() << endl;
    for (int i=0; i<out.size(); i++) {
        if (i!=out.size()-1) {
            cout << out[i] << " ";
        }
        else
        {
            cout << out[i] << endl;
        }
    }
    return 0;
}
