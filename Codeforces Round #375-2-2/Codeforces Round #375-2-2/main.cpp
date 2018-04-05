//
//  main.cpp
//  Codeforces Round #375-2-2
//
//  Created by 袁子涵 on 16/10/3.
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
#include <utility>
#include <queue>
#include <vector>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    int n,now,out1,out2;
    bool flag=0,flag1=0;
    char c;
    now=out1=out2=0;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> c;
        if (c==')') {
            flag=0;
            if (flag1)
                out2++;
            flag1=0;
            now=0;
        }
        else if (c=='(')
        {
            flag=1;
            out1=max(out1,now);
            now=0;
        }
        else if (c=='_')
        {
            if (!flag) {
                out1=max(out1,now);
                now=0;
            }
            else
            {
                if (flag1) {
                    out2++;
                }
                flag1=0;
                now=0;
            }
        }
        else
        {
            if (flag) {
                flag1=1;
            }
            now++;
        }
    }
    if (!flag) {
        out1=max(out1,now);
    }
    cout << out1 << " " << out2 << endl;
    return 0;
}
