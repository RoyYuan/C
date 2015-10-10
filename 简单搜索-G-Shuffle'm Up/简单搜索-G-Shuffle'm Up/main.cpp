//
//  main.cpp
//  简单搜索-G-Shuffle'm Up
//
//  Created by 袁子涵 on 15/8/2.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int N;
int C;
char s1[101],s2[101],s12[202];
char ss[202],final[202];

bool check()
{
    for (int i=1; i<=2*C; i++) {
        if (s12[i]!=final[i]) {
            return 0;
        }
    }
    return 1;
}

bool re()
{
    for (int i=1; i<=2*C; i++) {
        if (s12[i]!=ss[i]) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    cin >> N;
    int t=N;
    int sum=0;
    while (t--) {
        cin >> C;
        sum=0;
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
        memset(s12, 0, sizeof(s12));
        for (int i=1;i<=C ; i++) {
            cin >> s1[i];
        }
        for (int i=1; i<=C; i++) {
            cin >> s2[i];
        }
        for (int i=1; i<=2*C; i++) {
            cin >> final[i];
        }
        for (int i=1; i<=2*C; i+=2) {
            s12[i]=s2[i/2+1];
            s12[i+1]=s1[i/2+1];
        }
        sum++;
        if (check()) {
            cout << N-t << " " << "1" <<endl;
            continue;
        }
        memcpy(ss, s12, sizeof(ss));
        while (1) {
            sum++;
            for (int i=1; i<=C; i++) {
                s1[i]=s12[i];
            }
            for (int i=C+1; i<=2*C; i++) {
                s2[i-C]=s12[i];
            }
            for (int i=1; i<=2*C; i+=2) {
                s12[i]=s2[i/2+1];
                s12[i+1]=s1[i/2+1];
            }
            if (re()) {
                cout << N-t << " " << "-1" << endl;
                break;
            }
            if (check()) {
                cout << N-t << " " << sum << endl;
                break;
            }
        }
    }
    return 0;
}
