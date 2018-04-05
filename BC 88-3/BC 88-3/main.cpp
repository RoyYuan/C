//
//  main.cpp
//  BC 88-3
//
//  Created by 袁子涵 on 16/10/1.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
const int maxn=100005;
char a[maxn];
long long int num[maxn];
using namespace std;
int main(int argc, const char * argv[]) {
    for (int i=1; i<maxn; ++i) {
        num[i]=num[i-1]+i;
    }
    int t;
    cin >> t;
    while (t--) {
        long long int ans=0;
        cin >> a;
        int len=strlen(a);
        for (int i=0; i<len; i++) {
            if ('q'==a[i]) {
                int j;
                for (int j=i+1; j<len; j++) {
                    if (a[j]!='q') {
                        break;
                    }
                }
                ans+=num[j-i];
            }
        }
    }
    return 0;
}
