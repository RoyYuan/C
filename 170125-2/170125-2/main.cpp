//
//  main.cpp
//  170125-2
//
//  Created by 袁子涵 on 17/1/25.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
const int maxn=6e5+5;
long long int total[maxn];
int main(int argc, const char * argv[]) {
    int t,a,b,now;
    ios::sync_with_stdio(false);
//    int t,a,b,sum;
    cin >> t;
    for (int i=2; i<=6e5/2; i++) {
        now=2*i;
        while (now<=6e5) {
            total[now]+=i;
            now+=i;
        }
    }
    while (t--) {
        cin >> a >> b;
//        sum=0;
//        for (int i=2; i<=a/2; i++) {
//            if (a%i);
//            else
//                sum+=i;
//        }
//        if (sum==b-1) {
//            sum=0;
//            for (int i=2; i<=b/2; i++) {
//                if (b%i);
//                else
//                    sum+=i;
//            }
//            if (sum==a-1)
//                cout << "YES" << endl;
//            else
//                cout << "NO" << endl;
//        }
//        else
//            cout << "NO" << endl;
//        cout << total[a] << " " << total[b] << endl;
        if (total[a]==b-1 && total[b]==a-1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
