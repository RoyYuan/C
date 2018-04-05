//
//  main.cpp
//  XUPT21-3
//
//  Created by 袁子涵 on 16/12/1.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;
map<string,bool>Book;
const int maxn=120005;
string str[maxn];
bool ans[maxn];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int total=0;
    while (cin >> str[++total])
    {
        Book[str[total]]=1;
    }
    for (int i=1; i<=total; i++) {
        int l=str[i].size();
        for (int j=i+1; j<=total; j++) {
            if (str[j].size()<l) {
                break;
            }
            if (str[j].substr(0,l)!=str[i]) {
                break;
            }
            if(Book[str[j].substr(l,str[j].size()-l)])
                ans[j]=1;
                    
        }
    }
    for (int i=1; i<=total; i++) {
        if (ans[i]) {
            cout << str[i] << endl;
        }
    }
    return 0;
}
