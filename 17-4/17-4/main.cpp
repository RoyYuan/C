//
//  main.cpp
//  17-4
//
//  Created by 袁子涵 on 16/4/17.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int t;
int a,k;
long long int num,tmp,tl;
vector<long long int>re;
void GetNum(int a,int k)
{
    re.clear();
    tl=0;
    long long int shi=1,jin=0,now=0,last=a;
    while (now!=a || jin!=0) {
        tmp=last*k+jin;
        now=tmp%10;
        jin=tmp/10;
        re.push_back(now);
        shi*=10;
        last=now;
    }
}
int main(int argc, const char * argv[]) {
    cin >> t;
    while (t--) {
        cin >> a >> k;
        if (a==0) {
            cout << 0 << endl;
            continue;
        }
        if (!k) {
            cout << -1 << endl;
            continue;
        }
        if (k>a) {
            cout << -1 << endl;
            continue;
        }
        GetNum(a, k);
        for (long long int i=re.size()-1; i>=0; i--) {
            printf("%lld",re[i]);
        }
        cout << endl;
    }
    return 0;
}
