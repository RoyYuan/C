//
//  main.cpp
//  RE2
//
//  Created by 袁子涵 on 17/7/18.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
using namespace std;
int n;
const int maxn=1e5+5;
bool vis[maxn];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> n;
    if (n==1)
        cout << 1 << endl << 1 << endl;
    else if (n==2)
        cout << 1 << endl << "1 1" << endl;
    else
    {
        cout << 2 << endl;
        for (int i=2; i<=n+1; i++) {
            if (!vis[i]) {
                cout << "1 ";
                for (int j=i*2; j<=n+1; j+=i)
                    vis[j]=1;
            }
            else
                cout << "2 ";
        }
        cout << endl;
    }
    return 0;
}
