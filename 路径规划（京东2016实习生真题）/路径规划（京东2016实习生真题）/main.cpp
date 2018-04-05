//
//  main.cpp
//  路径规划（京东2016实习生真题）
//
//  Created by 袁子涵 on 18/1/24.
//  Copyright © 2018年 袁子涵. All rights reserved.
//

#include <iostream>
using namespace::std;
string s,t;
int dx,dy,ax,ay,out1,out2;
string out[4]={"U","D","L","R"};
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    while (cin >> s) {
        cin >> t;
        dx=t[0]-s[0];   
        dy=t[1]-s[1];
        ax=abs(dx);
        ay=abs(dy);
        cout << max(ax,ay) << endl;
        out1=dx>0?3:2;
        out2=dy>0?0:1;
        while (1) {
            if (ax==0 && ay==0)   break;
            if (ax>0)    cout << out[out1],ax--;
            if (ay>0)    cout << out[out2],ay--;
            cout << endl;
        }
    }
    return 0;
}