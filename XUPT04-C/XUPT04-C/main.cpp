//
//  main.cpp
//  XUPT04-C
//
//  Created by 袁子涵 on 16/9/8.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>

using namespace std;
string str;
int main(int argc, const char * argv[]) {
    bool flag=0;
    cin >> str;
    long long int l=str.length();
    for (long long int i=0; i<l; i++) {
        if (str[i]!='a') {
            str[i]--;
            flag=1;
        }
        else if (flag)
            break;
    }
    if (flag==0)
        str[l-1]='z';
    cout << str << endl;
    return 0;
}
