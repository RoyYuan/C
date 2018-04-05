//
//  main.cpp
//  贪心9
//
//  Created by 袁子涵 on 17/2/24.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <list>
#include <map>
#include <stack>
using namespace::std;
string str1,str2;
int change[150][150],vis[150];
int main(int argc, const char * argv[]) {
    int l,flag=0,out1,out2,total=0;
    cin >> l >> str1 >> str2;
    for (int i=0; i<l; i++) {
        if (str1[i]!=str2[i]) {
            vis[str1[i]]=i+1;
            total++;
            if (change[str1[i]][str2[i]])   continue;
            change[str1[i]][str2[i]]=i+1;
        }
    }
    for (int i='a'; i<='z'; i++) {
        for (int j=i+1; j<='z'; j++) {
            if (change[i][j] && change[j][i]) {
                flag=2;
                out1=change[i][j],out2=change[j][i];
                break;
            }
            if (change[i][j] && vis[j]) {
                flag=1;
                out1=change[i][j];
                out2=vis[j];
            }
            if (change[j][i] && vis[i]) {
                flag=1;
                out1=change[j][i];
                out2=vis[i];
            }
        }
        if (flag==2)    break;
    }
    if (!flag)
        cout << total << endl << "-1 -1" << endl;
    else
    {
        if (flag==2)
            cout << total-2 << endl << out1 << ' ' << out2 << endl;
        else
            cout << total-1 << endl << out1 << ' ' << out2 << endl;
    }
    return 0;
}
