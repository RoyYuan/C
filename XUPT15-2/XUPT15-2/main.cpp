//
//  main.cpp
//  XUPT15-2
//
//  Created by 袁子涵 on 16/11/4.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <utility>

using namespace std;
int vis[200];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    string str;
    cin >> str;
    if (str.size()<26) {
        cout << -1 << endl;
        return 0;
    }
    int now=0,wen=0,plz=26;
    for (int i=0; i<26; i++) {
        if (vis[str[i]]>0) {
            vis[str[i]]++;
            continue;
        }
        else if (str[i]=='?')
            wen++;
        else if(vis[str[i]]==0)
        {
            vis[str[i]]=1;
            now++;
        }
    }
    while (wen+now<26 && plz<str.size()) {
        if (str[plz-26]=='?') {
            wen--;
        }
        else
        {
            vis[str[plz-26]]--;
            if (vis[str[plz-26]]==0) {
                now--;
            }
        }
        if (str[plz]=='?') {
            wen++;
        }
        else
        {
            if (vis[str[plz]]==0) {
                now++;
            }
            vis[str[plz]]++;
        }
        plz++;
    }
    if (wen+now==26) {
        plz--;
        for (int i=plz-25; i<=plz; i++) {
            if (str[i]!='?') {
                continue;
            }
            for (int j='A'; j<='Z'; j++) {
                if (vis[j]==0) {
                    str[i]=j;
                    vis[j]++;
                    break;
                }
            }
        }
        for (int i=0; i<=plz-26; i++) {
            if (str[i]=='?') {
                str[i]='A';
            }
        }
        for (int i=plz+1; i<str.size(); i++) {
            if (str[i]=='?') {
                str[i]='A';
            }
        }
        cout << str << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}
