//
//  main.cpp
//  XUPT08-3
//
//  Created by 袁子涵 on 16/9/22.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>
#include <map>

using namespace std;
const int maxn=2105;
string str1,str2,str3;
bool have[30];
int ans=0;
vector<pair<int,int>>out;
int main(int argc, const char * argv[]) {
    cin >> str1 >> str2;
    str3=str1;
    int l=min(str1.size(),str2.size());
    int ll=str1.size();
    reverse(str3.begin(), str3.end());
    for (int i=0; i<str1.size(); i++)
        have[str1[i]-'a']=1;
    for (int i=0; i<str2.size(); i++) {
        if (have[str2[i]-'a'])
            continue;
        cout << "-1" << endl;
        return 0;
    }
    int now=0;
    string tmp;
    std::size_t it1,it2;
    while (now<str2.size()) {
        ans++;
        int l1,l2,r1,r2;
        tmp.clear();
        for (int i=1; i<=l; i++) {
            tmp+=str2[now+i-1];
            it1=str1.find(tmp);
            it2=str3.find(tmp);
            if (it1!=std::string::npos) {
                l1=it1+1;
                r1=l1+i-1;
            }
            if (it2!=std::string::npos) {
                l2=ll-it2;
                r2=l2-i+1;
            }
            else if (it1==std::string::npos && it2==std::string::npos)
                break;
        }
        if (r1-l1>=l2-r2) {
            out.push_back(make_pair(l1, r1));
            now+=r1-l1+1;
        }
        else
        {
            out.push_back(make_pair(l2, r2));
            now+=l2-r2+1;
        }
    }
    cout << ans << endl;
    for (int i=0; i<out.size(); i++)
        cout << out[i].first << " " << out[i].second << endl;
    return 0;
}
