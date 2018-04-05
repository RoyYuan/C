//
//  main.cpp
//  16-1
//
//  Created by 袁子涵 on 16/4/16.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
string num;
long long int l;
bool flag=0;
int main(int argc, const char * argv[]) {
    while (cin >> num) {
        flag=1;
        l=num.size();
        for(int i=0;i<l/2;i++)
        {
            if(num[i]==num[l-i-1])
                continue;
            flag=0;
            break;
        }
        if (flag) {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
    return 0;
}
