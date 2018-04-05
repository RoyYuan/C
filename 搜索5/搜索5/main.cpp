//
//  main.cpp
//  搜索5
//
//  Created by 袁子涵 on 17/3/6.
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
string str[25];
int same[25][25],times[25],length[25];
int n,ans;
int dfs(int num,int now)
{
    int out=now;
    times[num]++;
    for (int i=0; i<n; i++) {
        if (same[num][i]>0 && times[i]<2)
            out=max(out,dfs(i, now+length[i]-same[num][i]));
    }
    times[num]--;
    return out;
}
int main(int argc, const char * argv[]) {
    cin >> n;
    memset(same, -1, sizeof(same));
    for (int i=0; i<n; i++)
    {
        cin >> str[i];
        length[i]=str[i].size();
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int l=min(length[i],length[j]);
            for (int k=1; k<=l; k++) {
                if (str[i].substr(length[i]-k,length[i]-1)==str[j].substr(0,k)) {
                    same[i][j]=k;
                    break;
                }
            }
            if (same[i][j]==l)
                same[i][j]=-1;
        }
    }
    string c;
    cin >> c;
    for (int i=0; i<n; i++)
        if (str[i].substr(0,1)==c)
            ans=max(ans,dfs(i,length[i]));
    cout << ans << endl;
    return 0;
}