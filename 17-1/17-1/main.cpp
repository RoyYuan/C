//
//  main.cpp
//  17-1
//
//  Created by 袁子涵 on 16/4/17.
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
int t;
string str1,str2;
char final1[1005],final2[1005];
int now1,now2,l1,l2;
char last;
string out1,out2;
int main(int argc, const char * argv[]) {
    cin >> t;
    while (t--) {
        cin >> str1 >> str2;
        memset(final1, 0, sizeof(final1));
        memset(final2, 0, sizeof(final2));
        l1=str1.size();
        l2=str2.size();
        now1=now2=0;
        last=0;
        for (int i=0; i<l1; i++) {
            if (str1[i]!=last) {
                last=str1[i];
                final1[now1++]=last;
            }
        }
        final1[now1]='\0';
        last=0;
        for (int i=0; i<l2; i++) {
            if (str2[i]!=last) {
                last=str2[i];
                final2[now2++]=last;
            }
        }
        final2[now2]='\0';
        out1=final1;
        out2=final2;
        if (out1==out2) {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
    return 0;
}
