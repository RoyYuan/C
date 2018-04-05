//
//  main.cpp
//  RE6
//
//  Created by 袁子涵 on 17/7/18.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> H;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int n,m,k,a;
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) {
        cin >> a;
        if (a==0)
            continue;
        if (a<=k)
            H.push_back(abs(i-m)*10);
    }
    sort(H.begin(), H.end());
    cout << H[0] << endl;
    return 0;
}
