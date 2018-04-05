//
//  main.cpp
//  RE-3-2
//
//  Created by 袁子涵 on 17/8/2.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <utility>
using namespace std;
long long int num[10],total,k,now,ans;
string str;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> k;
    cin >> str;
    for (int i=0; i<str.size(); i++) {
        num[str[i]-'0']++;
        now+=str[i]-'0';
    }
    if (now>=k) {
        cout << 0 << endl;
        return 0;
    }
    else
    {
        long long int tmp=0,tt;
        while (now<k) {
            tt=num[tmp]*(9-tmp);
            if (tt+now>=k) {
                for (int i=1; i<=num[tmp]; i++) {
                    if (i*(9-tmp)+now>=k) {
                        ans+=i;
                        break;
                    }
                }
                break;
            }
            else
            {
                ans+=num[tmp];
                now+=tt;
                tmp++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
