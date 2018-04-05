//
//  main.cpp
//  XUPT21-5
//
//  Created by 袁子涵 on 16/12/1.
//
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
map<int,int>Book;
const int maxn=1005;
int num[maxn];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        if (n==0) {
            break;
        }
        Book.clear();
        for (int i=1; i<=n; i++) {
            cin >> num[i];
            Book[num[i]]++;
        }
        sort(num+1,num+n+1);
        bool flag=0;
        int out;
        for (int i=n; i>=1; i--) {
            for (int j=n; j>=1; j--) {
                if (i==j) {
                    continue;
                }
                for (int z=n; z>=1; z--) {
                    if (z==j || z==i) {
                        continue;
                    }
                    int tt=num[i]-num[j]-num[z],nn=0;
                    if (tt==num[i]) {
                        nn++;
                    }
                    if (tt==num[j]) {
                        nn++;
                    }
                    if (tt==num[z]) {
                        nn++;
                    }
                    if (Book[tt]>nn) {
                        flag=1;
                        out=num[i];
                        break;
                    }
                }
                if (flag) {
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        if (flag) {
            cout << out << endl;
        }
        else
            cout << "no solution" << endl;
    }
    return 0;
}
