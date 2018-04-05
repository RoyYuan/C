//
//  main.cpp
//  XUPT22-2
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
string str;
char to[26]={'V','W','X','Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U'};
int main(int argc, const char * argv[]) {
    string stop="ENDOFINPUT";
    while (getline(cin,str)) {
        if (str==stop) {
            break;
        }
        getline(cin,str);
        for (int i=0; i<str.size(); i++) {
            if (str[i]>='A' && str[i]<='Z') {
                str[i]=to[str[i]-'A'];
            }
        }
        cout << str << endl;
        getline(cin, str);
    }
    return 0;
}
