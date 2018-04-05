//
//  main.cpp
//  XUPT18-2
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
string str,now;
int in,fl;
void add()
{
    int l=now.size(),tt=0;
    if (l>3 && now[l-3]=='.') {
        tt=(now[l-2]-'0')*10+now[l-1]-'0';
        fl+=tt;
        tt=1;
        for (int i=l-4; i>=0; i--) {
            if (now[i]=='.') {
                continue;
            }
            in+=(now[i]-'0')*tt;
            tt*=10;
        }
    }
    else
    {
        tt=1;
        for (int i=l-1; i>=0; i--) {
            if (now[i]=='.') {
                continue;
            }
            in+=(now[i]-'0')*tt;
            tt*=10;
        }
    }
    
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    in=fl=0;
    cin >> str;
    for (int i=0; i<str.size(); i++) {
        while (str[i]!='.' && (str[i]>'9' || str[i]<'0') && i<str.size()) {
            i++;
        }
        now.clear();
        while ((str[i]=='.' || (str[i]<='9' && str[i]>='0'))&& i<str.size()) {
            now+=str[i];
            i++;
        }
        add();
    }
    in+=(fl/100);
    fl%=100;
    string out;
    int now=0;
    out.clear();
    if (in==0) {
        out="0";
    }
    while (in) {
        if (now!=0 && now%3==0) {
            out+=(char)'.';
        }
        out+=(char)(in%10+'0');
        now++;
        in/=10;
    }
    for (int i=out.size()-1; i>=0; i--) {
        cout << out[i];
    }
    if (fl!=0) {
        cout << '.' << fl/10 << fl%10 << endl;
    }
    return 0;
}
