//
//  main.cpp
//  XUPT22-4
//
//  Created by 袁子涵 on 16/12/2.
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
map<int,int>Book;
int n;
string str;
int to[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
void output(int num)
{
    int now=1000000;
    for (int i=1; i<=3; i++) {
        cout << (num/now)%10;
        now/=10;
    }
    cout << '-';
    for (int i=4; i<=7; i++) {
        cout << (num/now)%10;
        now/=10;
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> str;
        int now=1000000,tmp=0;
        for (int j=0; j<str.size(); j++) {
            if (str[j]>='0' && str[j]<='9') {
                tmp+=now*(str[j]-'0');
                now/=10;
                continue;
            }
            if (str[j]>='A' && str[j]<='Z') {
                tmp+=now*(to[str[j]-'A']);
                now/=10;
                continue;
            }
        }
        Book[tmp]++;
    }
    bool flag=0;
    map<int,int>::iterator it=Book.begin();
    for (; it!=Book.end(); it++) {
        if (it->second<=1) {
            continue;
        }
        flag=1;
        output(it->first);
        cout << " " << it->second << endl;
    }
    if (flag==0) {
        cout << "No duplicates." << endl;
    }
    return 0;
}
