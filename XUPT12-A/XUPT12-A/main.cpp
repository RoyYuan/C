//
//  main.cpp
//  XUPT12-A
//
//  Created by 袁子涵 on 16/10/19.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
string str;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> str;
    int out=0;
    char now='a';
    int l=str.size();
    for (int i=0; i<l; i++) {
        int tmp=0x3f3f3f3f;
        if (str[i]>=now) {
            tmp=min(tmp,str[i]-now);
            tmp=min(tmp,'z'-str[i]+now-'a'+1);
        }
        else
        {
            tmp=min(tmp,now-str[i]);
            tmp=min(tmp,'z'-now+str[i]-'a'+1);
        }
        now=str[i];
        out+=tmp;
    }
    cout << out << endl;
    return 0;
}
