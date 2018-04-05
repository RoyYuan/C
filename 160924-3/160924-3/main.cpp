//
//  main.cpp
//  160924-3
//
//  Created by 袁子涵 on 16/9/24.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <utility>
#include <complex>

using namespace std;
set<string>S;
int main(int argc, const char * argv[]) {
    string str,end="0",last[105],now,cur[105];
    int cas=0;
    while (getline(cin,str)) {
        for (int i=0; i<105; i++)
        {
            cur[i].clear();
            last[i].clear();
        }
        cas++;
        S.clear();
        cout << "Case " << cas << ":\n";
        if (str==end)
            continue;
        str+='/';
        S.insert(str);
        while (getline(cin, str)) {
            if (str==end)
                break;
            str+='/';
            S.insert(str);
        }
        set<string>::iterator it=S.begin();
        int step;
        for (; it!=S.end(); it++) {
            for (int i=0; i<105; i++)
                cur[i].clear();
            str=*it;
            step=0;
            now.clear();
            for (int i=0; i<str.size(); i++) {
                if (str[i]!='/')
                    now+=str[i];
                else
                {
                    step++;
                    cur[step]=now;
                    if (now!=last[step]) {
                        for (int i=1; i<=4*(step-1); i++)
                            putchar(' ');
                        cout << now << endl;
                    }
                    now.clear();
                }
            }
            for (int i=0; i<step; i++) {
                last[i]=cur[i];
            }
        }
    }
    return 0;
}
