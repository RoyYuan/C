//
//  main.cpp
//  RE4
//
//  Created by 袁子涵 on 17/7/18.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int a,b,c,n,x,ans=0;
    cin >> a >> b >> c;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x;
        if (x<c && x>b) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
