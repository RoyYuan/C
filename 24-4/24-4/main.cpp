//
//  main.cpp
//  24-4
//
//  Created by 袁子涵 on 16/4/24.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
int n,x;
bool stop[10][40];
int now[10],size[10];
int plz[10];
bool moved[10];
long long int solve(int num)
{
    long long int out=0;
    if (now[num]==x) {
        return 0;
    }
    if (moved[num]==0) {
        plz[num]=now[num];
        while (plz[num]<x) {
            plz[num]++;
            if (stop[num][plz[num]]) {
                out+=20;
            }
            else
                out+=5;
        }
    }
    else
    {
        plz[num]=now[num];
        while (plz[num]>x) {
            plz[num]--;
            if (stop[num][plz[num]]) {
                out+=20;
            }
            else
                out+=5;
        }
    }
    if (stop[num][x]) {
        out-=15;
    }
    return out;
}


int main(int argc, const char * argv[]) {
    while (cin >> n >> x) {
        memset(stop, 0, sizeof(stop));
        memset(now, 0, sizeof(now));
        memset(size, 0, sizeof(size));
        memset(plz, 0, sizeof(plz));
        memset(moved, 0, sizeof(moved));
        for (int i=1; i<=n; i++) {
            cin >> now[i];
            if (now[i]>x) {
                moved[i]=1;
            }
        }
        for (int i=1; i<=n; i++) {
            cin >> size[i];
            for (int j=1; j<=size[i]; j++) {
                int tmp;
                cin >> tmp;
                stop[i][tmp]=1;
            }
        }
        for (int i=1; i<=n; i++) {
            cout << solve(i);
            if (i!=n) {
                cout << " ";
            }
            else
                cout << endl;
        }
    }
    return 0;
}
