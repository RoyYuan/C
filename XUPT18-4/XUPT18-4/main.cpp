//
//  main.cpp
//  XUPT18-4
//
//  Created by 袁子涵 on 16/11/18.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;
#define S 1
#define M 2
#define L 3
#define XL 4
#define XXL 5
#define XXXL 6
string str;
int n;
int num[7];
string out[7]={"","S","M","L","XL","XXL","XXXL"};
vector<int>man[6];
int choose[100005],ans[100005],total[10],single[10];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    for (int i=1; i<7; i++) {
        cin >> num[i];
    }
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> str;
        string tmp;
        bool flag=0;
        tmp.clear();
        for (int j=0; j<str.size(); j++) {
            if (str[j]!=',') {
                tmp+=str[j];
            }
            else
            {
                flag=1;
                if (tmp=="S")
                {
                    choose[i]=1;
                    man[1].push_back(i);
                    total[1]++;
                }
                else if (tmp=="M")
                {
                    choose[i]=2;
                    man[2].push_back(i);
                    total[2]++;
                }
                else if (tmp=="L")
                {
                    choose[i]=3;
                    man[3].push_back(i);
                    total[3]++;
                }
                else if (tmp=="XL")
                {
                    choose[i]=4;
                    man[4].push_back(i);
                    total[4]++;
                }
                else if (tmp=="XXL")
                {
                    choose[i]=5;
                    man[5].push_back(i);
                    total[5]++;
                }
                break;
            }
        }
        if (flag)
            continue;
        if (tmp=="S")
            ans[i]=1,single[1]++;
        else if (tmp=="M")
            ans[i]=2,single[2]++;
        else if (tmp=="L")
            ans[i]=3,single[3]++;
        else if (tmp=="XL")
            ans[i]=4,single[4]++;
        else if (tmp=="XXL")
            ans[i]=5,single[5]++;
        else if (tmp=="XXXL")
            ans[i]=6,single[6]++;
    }
    bool F=1;
    for (int i=1; i<=6; i++) {
        num[i]-=single[i];
    }
    for (int i=1; i<6; i++) {
        if (total[i]<=num[i]) {
            for (int j=0; j<man[j].size(); j++) {
                ans[man[i][j]]=i;
            }
        }
        else
        {
            for (int j=0; j<num[i]; j++) {
                ans[man[i][j]]=i;
            }
            if (total[i]-num[i]<=num[i+1]) {
                for (int j=num[i]; j<man[i].size(); i++) {
                    ans[man[i][j]]=i;
                }
                num[i+1]-=total[i]-num[i];
            }
        }
    }
    if (F) {
        cout << "YES" << endl;
        for (int i=1; i<=n; i++) {
            cout << out[ans[i]] << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
