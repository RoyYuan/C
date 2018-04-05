//
//  main.cpp
//  17-5
//
//  Created by 袁子涵 on 16/4/17.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
int t,n;
long long int num1[1005],num2[1005];
long long int plz[2010];
long long int plz1[2][1005],plz2[2][1005];
int main(int argc, const char * argv[]) {
    cin >> t;
    while (t--) {
        long long int tmp1,tmp2;
        cin >> n;
        long long int no=n*2-1,out=n;
        memset(num1, 0, sizeof(num1));
        memset(num2, 0, sizeof(num2));
        memset(plz1, -1, sizeof(plz1));
        memset(plz2, -1, sizeof(plz2));
        memset(plz, -1, sizeof(plz));
        for (int i=1; i<=n; i++) {
            scanf("%lld %lld",&tmp1,&tmp2);
            num1[i]=tmp1;
            num2[i]=tmp2;
        }
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                if (plz1[0][i]==-1 && num1[i]+num1[j]==no) {
                    plz1[0][i]=j-1;
                }
                if (plz1[1][i]==-1 && num1[i]+num2[j]==no) {
                    plz1[1][i]=j-1;
                }
                if (plz2[0][i]==-1 && num2[i]+num1[j]==no) {
                    plz1[0][i]=j-1;
                }
                if (plz2[1][i]==-1 && num2[i]+num2[j]==no) {
                    plz2[1][i]=j-1;
                }
            }
        }
        for (int i=1; i<=n; i++) {
            if (plz1[0][i]==-1) {
                plz1[0][i]=n;
            }
            if (plz1[1][i]==-1) {
                plz1[1][i]=n;
            }
            if (plz2[0][i]==-1) {
                plz2[0][i]=n;
            }
            if (plz2[1][i]==-1) {
                plz2[1][i]=n;
            }
        }
        for (int i=1; i<=n; i++) {
            plz1[0][i]=max(plz1[0][i],plz1[1][i]);
            plz2[0][i]=max(plz2[0][i],plz2[1][i]);
            plz1[0][i]=max(plz1[0][i],plz2[0][i]);
            out=min(plz1[0][i],out);
            if (out<=i) {
                break;
            }
        }
        cout << out << endl;
    }
    return 0;
}
