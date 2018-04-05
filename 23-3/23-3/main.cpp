//
//  main.cpp
//  23-3
//
//  Created by 袁子涵 on 16/4/23.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>

using namespace std;
int t;
int num[6];
int button[6][5];
int pressed[6][2];
void f1()
{
    if (num[1]==1 || num[1]==2) {
        cout << 2 << " " << button[1][2];
        pressed[1][0]=2,pressed[1][1]=button[1][2];
        return;
    }
    if (num[1]==3) {
        cout << 3 << " " << button[1][3];
        pressed[1][0]=3,pressed[1][1]=button[1][3];
        return;
    }
    if (num[1]==4) {
        cout << 4 << " " << button[1][4];
        pressed[1][0]=4,pressed[1][1]=button[1][4];
        return;
    }
}
void f2()
{
    if (num[2]==1) {
        for (int i=1; i<=4; i++) {
            if (button[2][i]==4) {
                cout << i << " " << 4;
                pressed[2][0]=i,pressed[2][1]=4;
                return;
            }
        }
    }
    if (num[2]==2 || num[2]==4) {
        cout << pressed[1][0] << " " << button[2][pressed[1][0]];
        pressed[2][0]=pressed[1][0],pressed[2][1]=button[2][pressed[1][0]];
        return;
    }
    if (num[2]==3) {
        cout << 1 << " " << button[2][1];
        pressed[2][0]=1,pressed[2][1]=button[2][1];
        return;
    }
}
void f3()
{
    if (num[3]==1) {
        for (int i=1; i<=4; i++) {
            if (button[3][i]==pressed[2][1]) {
                cout << i << " " << button[3][i];
                pressed[3][0]=i,pressed[3][1]=button[3][i];
                return;
            }
        }
    }
    if (num[3]==2) {
        for (int i=1; i<=4; i++) {
            if (button[3][i]==pressed[1][1]) {
                cout << i << " " << button[3][i];
                pressed[3][0]=i,pressed[3][1]=button[3][i];
                return;
            }
        }
    }
    if (num[3]==3) {
        cout << 3 << " " << button[3][3];
        pressed[3][0]=3,pressed[3][1]=button[3][3];
        return;
    }
    if (num[3]==4) {
        for (int i=1; i<=4; i++) {
            if (button[3][i]==4) {
                cout << i << " " << 4;
                pressed[3][0]=i,pressed[3][1]=4;
                return;
            }
        }
    }
}
void f4()
{
    if (num[4]==1) {
        cout << pressed[1][0] << " " << button[4][pressed[1][0]];
        pressed[4][0]=pressed[1][0],pressed[4][1]=button[4][pressed[1][0]];
        return;
    }
    if (num[4]==2) {
        cout << 1 << " " << button[4][1];
        pressed[4][0]=1,pressed[4][1]=button[4][1];
        return;
    }
    if (num[4]==3 || num[4]==4) {
        cout << pressed[2][0] << " " << button[4][pressed[2][0]];
        pressed[4][0]=pressed[2][0],pressed[4][1]=button[4][pressed[2][0]];
        return;
    }
}
void f5()
{
    if (num[5]==1 || num[5]==2) {
        for (int i=1; i<=4; i++) {
            if (button[5][i]==pressed[num[5]][1]) {
                cout << i << " " << button[5][i];
                return;
            }
        }
    }
    if (num[5]==3) {
        for (int i=1; i<=4; i++) {
            if (button[5][i]==pressed[4][1]) {
                cout << i << " " << button[5][i];
                return;4
            }
        }
    }
    if (num[5]==4) {
        for (int i=1; i<=4; i++) {
            if (button[5][i]==pressed[3][1]) {
                cout << i << " " << button[5][i];
                return;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> t;
    while (t--) {
        memset(pressed, 0, sizeof(pressed));
        memset(num, 0, sizeof(num));
        memset(button, 0, sizeof(button));
        for (int i=1; i<=5; i++) {
            cin >> num[i];
            for (int j=1; j<=4; j++) {
                cin >> button[i][j];
            }
        }
        f1();
        cout << endl;
        f2();
        cout << endl;
        f3();
        cout << endl;
        f4();
        cout << endl;
        f5();
        if(t) cout << endl;
    }
    return 0;
}
