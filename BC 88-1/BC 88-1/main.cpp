//
//  main.cpp
//  BC 88-1
//
//  Created by 袁子涵 on 16/10/1.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <set>

using namespace std;
string str;
int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        long long int out=0,last=0;
        cin >> str;
        for (int i=0; i<str.size(); i++) {
            if (str[i]=='q') {
                last++;
            }
            else
            {
                if (last) {
                    out+=(1+last)*last/2;
                    last=0;
                }
            }
        }
        if (last) {
            out+=(1+last)*last/2;
            last=0;
        }
        cout << out << endl;
    }
    return 0;
}
