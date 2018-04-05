//
//  main.cpp
//  XUPT14-3
//
//  Created by 袁子涵 on 16/11/3.
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
map<string,int>book;
void add(long long int num)
{
    string now;
    now.clear();
    while (num) {
        if (num%10&1) {
            now+="1";
        }
        else
            now+='0';
        num/=10;
    }
    reverse(now.begin(), now.end());
    book[now]++;
}
void del(long long int num)
{
    string now;
    now.clear();
    while (num) {
        if (num%10&1) {
            now+="1";
        }
        else
            now+="0";
        num/=10;
    }
    reverse(now.begin(), now.end());
    book[now]--;
}
void check(string str)
{
    int now=0;
    string pa;
    while (str[now]=='0') {
        now++;
    }
    while (now<str.size()) {
        pa+=str[now];
        now++;
    }
    long long int out=0;
    while (pa.size()<20) {
        out+=book[pa];
        pa="0"+pa;
    }
    printf("%lld\n",out);
}
int main(int argc, const char * argv[]) {
    int t;
    long long int tmp;
    char c;
    string str;
    scanf("%d",&t);
    while (t--) {
        cin >> c;
        switch (c) {
            case '+':
                scanf("%lld",&tmp);
                add(tmp);
                break;
            case '-':
                scanf("%lld",&tmp);
                del(tmp);
                break;
            case '?':
                cin >> str;
                check(str);
            default:
                break;
        }
    }
    return 0;
}
