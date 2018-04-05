//
//  main.cpp
//  XUPT22-3
//
//  Created by 袁子涵 on 16/12/2.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;
int tosixt(int num)
{
    int ans=0;
    while (num) {
        ans+=num%16;
        num/=16;
    }
    return ans;
}
int totwl(int num)
{
    int ans=0;
    while (num) {
        ans+=num%12;
        num/=12;
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    for (int i=1000; i<10000; i++) {
        int tmp=0,tmp1=tosixt(i),tmp2=totwl(i);
        int tt=i;
        while (tt) {
            tmp+=tt%10;
            tt/=10;
        }
        if (tmp==tmp1 && tmp1==tmp2) {
            cout << i << endl;
        }
    }
    return 0;
}
