//
//  main.cpp
//  RE-2-3
//
//  Created by 袁子涵 on 17/7/28.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <string>
using namespace std;
const int maxn=55;
int n,k,num[maxn],tmp;
string str;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    int now=1;
    for (int i=0; i<=n-k; i++) {
        cin >> str;
        if (str=="NO")
        {
            tmp=max(num[i],num[i+k-1]);
            num[i]=num[i+k-1]=tmp==0?now++:tmp;
        }
    }
    for (int i=0; i<n; i++)
        if (!num[i])
            num[i]=now++;
    for (int i=0; i<n; i++) {
        int t=num[i]/10;
        cout << (char)('A'+t);
        for (int j=1; j<=num[i]%10; j++)
            cout << (char)('a'+t);
        if (i<n-1)
            cout << ' ';
    }
    cout << endl;
    return 0;
}
