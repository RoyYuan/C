//
//  main.cpp
//  XUPT22-5
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
map<string,int>Book;
int num[10],now;
string str,stop="-1",nxt;
void tonext(int num,int times)
{
    int st[100],top=0;
    while (times) {
        st[++top]=times%10;
        times/=10;
    }
    while (top) {
        nxt+=(char)(st[top--]+'0');
    }
    nxt+=(char)(num+'0');
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    while (cin >> str) {
        Book.clear();
        if (str==stop) {
            break;
        }
        nxt.clear();
        memset(num, 0, sizeof(num));
        for (int i=0; i<str.size(); i++) {
            num[str[i]-'0']++;
        }
        now=0;
        for (int i=0; i<=9; i++) {
            if (num[i]) {
                tonext(i,num[i]);
            }
        }
        if (nxt==str) {
            cout << str << " is self-inventorying" << endl;
            continue;
        }
        Book[str]=1;
        string str1=str;
        str=nxt;
        bool flag=0;
        for (int i=1; i<=15; i++) {
            nxt.clear();
            memset(num, 0, sizeof(num));
            for (int i=0; i<str.size(); i++) {
                num[str[i]-'0']++;
            }
            for (int i=0; i<=9; i++) {
                if (num[i]) {
                    tonext(i,num[i]);
                }
            }
            if (str==nxt) {
                cout << str1 << " is self-inventorying after " << i << " steps" << endl;
                flag=1;
                break;
            }
            if (Book[str]!=0) {
                cout << str1 << " enters an inventory loop of length " << i+2-Book[nxt] << endl;
                flag=1;
                break;
            }
            Book[str]=i+1;
            str=nxt;
        }
        if (flag) {
            continue;
        }
        cout << str1 << " can not be classified after 15 iterations" << endl;
    }
    return 0;
}
