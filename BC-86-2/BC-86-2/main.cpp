//
//  main.cpp
//  BC-86-2
//
//  Created by 袁子涵 on 16/8/6.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    int t,n;
    long long int a[100005],out=0,mx1=-1,mx2=-1,mx3,tmp,now1,now2;
    cin >> t;
    while (t--) {
        cin >> n;
        out=0,mx1=-1,mx2=-1,mx3=-1;
        for (int i=0; i<n; i++)
            scanf("%lld",&a[i]);
        for (int i=0; i<n-1; i++) {
            tmp=abs(a[i+1]-a[i]);
            if (tmp>mx1) {
                mx3=mx2;
                mx2=mx1;
                mx1=tmp;
            }
            else if (tmp>mx2)
            {
                mx3=mx2;
                mx2=tmp;
            }
            else if (tmp>mx3)
            {
                mx3=tmp;
            }
        }
        for (int i=1; i<n-1; i++) {
            tmp=abs(a[i+1]-a[i-1]);
            now1=abs(a[i]-a[i-1]),now2=abs(a[i+1]-a[i]);
            if (now1<now2) {
                swap(now1, now2);
            }
            if (tmp>=mx1) {
                out+=tmp;
                continue;
            }
            else if (now1==mx1)
            {
                if (now2==mx2) {
                    out+=max(tmp,mx3);
                }
                else
                {
                    out+=max(tmp,mx2);
                }
                continue;
            }
            else
            {
                out+=max(tmp,mx1);
                continue;
            }
        }
        now1=abs(a[0]-a[1]);
        if (now1==mx1) {
            out+=mx2;
        }
        else
            out+=mx1;
        now1=abs(a[n-1]-a[n-2]);
        if (now1==mx1) {
            out+=mx2;
        }
        else
            out+=mx1;
        printf("%lld\n",out);
    }
    return 0;
}
