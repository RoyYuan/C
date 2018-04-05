//
//  main.cpp
//  Codeforces Round #374-2-2
//
//  Created by 袁子涵 on 16/9/30.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;
int total[105],n,k,out;
string str;
int main(int argc, const char * argv[]) {
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> str;
        total[str.size()]++;
    }
    cin >> str;
    for (int i=1; i<str.size(); i++)
        out+=total[i];
    cout << out+(out/k)*5+1<< ' ' << ((out+total[str.size()]-1)/k)*5+out+total[str.size()] << endl;
    return 0;
}
