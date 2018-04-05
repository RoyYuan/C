//
//  main.cpp
//  160924-1
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

using namespace std;
map<string,int>M;
int main(int argc, const char * argv[]) {
    string tmp,end="####";
    while (getline(cin,tmp)) {
        M.clear();
        if (tmp==end)
            continue;
        tmp+=".";
        int l=tmp.length();
        string now,last,last1;
        last.clear();
        now.clear();
        for (int i=0; i<l; i++) {
            if (tmp[i]<='z' && tmp[i]>='a') {
                now+=tmp[i];
            }
            else if (tmp[i]==' ')
            {
                while (tmp[i]==' ') {
                    i++;
                }
                i--;
                if (last.size() && now.size()) {
                    last+=" ";
                    last+=now;
                    M[last]++;
                }
                last=now;
                now.clear();
            }
            else if (tmp[i]==',' || tmp[i]=='.')
            {
                if (last.size() && now.size()) {
                    last+=" ";
                    last+=now;
                    M[last]++;
                }
                last.clear();
                now.clear();
            }
            else
            {
                if (last.size() && now.size()) {
                    last+=" ";
                    last+=now;
                    M[last]++;
                }
                last.clear();
                now.clear();
            }
        }
        while (getline(cin,tmp)) {
            if (tmp==end)
                break;
            tmp+=".";
            int l=tmp.length();
            string now,last,last1;
            last.clear();
            now.clear();
            for (int i=0; i<l; i++) {
                if (tmp[i]<='z' && tmp[i]>='a') {
                    now+=tmp[i];
                }
                else if (tmp[i]==' ')
                {
                    while (tmp[i]==' ') {
                        i++;
                    }
                    i--;
                    if (last.size() && now.size()) {
                        last+=" ";
                        last+=now;
                        M[last]++;
                    }
                    last=now;
                    now.clear();
                }
                else if (tmp[i]==',' || tmp[i]=='.')
                {
                    if (last.size() && now.size()) {
                        last+=" ";
                        last+=now;
                        M[last]++;
                    }
                    last.clear();
                    now.clear();
                }
                else
                {
                    if (last.size() && now.size()) {
                        last+=" ";
                        last+=now;
                        M[last]++;
                    }
                    last.clear();
                    now.clear();
                }
            }
        }
        map<string,int>::iterator it=M.begin();
        string out;
        int ans=0;
        for (; it!=M.end(); it++) {
            if (it->second>ans) {
                ans=it->second;
                out=it->first;
            }
            else if (it->second==ans) {
                if (out>it->first) {
                    out=it->first;
                }
            }
        }
        cout << out << ":" << ans << endl;
    }
    return 0;
}
