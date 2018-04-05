//
//  main.cpp
//  160807-6
//
//  Created by 袁子涵 on 16/8/7.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>
using namespace std;
int map1[105][105],n,tmp;
string str;
map<int,pair<int,int>>MAP;
int main(int argc, const char * argv[]) {
    while (cin >> str) {
        if (str=="SHOW") {
            for (int i=1; i<=n; i++) {
                for (int j=1; j<n; j++) {
                    printf("%d ",map1[i][j]);
                }
                printf("%d\n",map1[i][n]);
            }
            puts("");
        }
        else if (str=="NEIGHBORS")
        {
            cin >> tmp;
            int x=MAP[tmp].first,y=MAP[tmp].second;
            vector<int>out;
            out.clear();
            if (x>1)
                out.push_back(map1[x-1][y]);
            if (y>1)
                out.push_back(map1[x][y-1]);
            if (y<n)
                out.push_back(map1[x][y+1]);
            if (x<n)
                out.push_back(map1[x+1][y]);
            for (int i=0; i<out.size()-1; i++)
                printf("%d ",out[i]);
            printf("%d\n",out[out.size()-1]);
        }
        else
        {
            n=0;
            memset(map1, 0, sizeof(map1));
            MAP.clear();
            tmp=1;
            for (int i=str.length()-1; i>=0; i--) {
                n+=tmp*(str[i]-'0');
                tmp*=10;
            }
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=n; j++) {
                    cin >> map1[i][j];
                    MAP[map1[i][j]]=make_pair(i, j);
                }
            }
        }
        
        
    }
    return 0;
}
