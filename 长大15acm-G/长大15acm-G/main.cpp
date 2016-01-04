//
//  main.cpp
//  长大15acm-G
//
//  Created by 袁子涵 on 15/12/7.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;
long long int n,m,c[20005],mins,maxs;
int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    while (T--) {
        mins=0;
        cin >> n >> m;
        long long int sum=0,re,total=0;
        for (long long int i=1; i<=m; i++)
        {
            scanf("%lld",&c[i]);
            sum+=c[i];
        }
        re=sum/n;
        if (re==0) {
            cout << 0 << endl;
            continue;
        }
        maxs=re;
        for (long long int i=1; i<=m; i++)
            total+=c[i]/re;
        while (1) {
            total=0;
            if (mins==maxs-1) {
                for (long long int i=1; i<=m; i++) {
                    total+=c[i]/maxs;
                }
                if (total>=n) {
                    re=maxs;
                    break;
                }
                else
                {
                    re=mins;
                    break;
                }
            }
            re=(maxs+mins)/2;
            for (long long int i=1; i<=m; i++)
                total+=c[i]/re;
            if (total>=n) {
                mins=re;
            }
            else
                maxs=re;
        }
        cout << re << endl;
    }
    return 0;
}
