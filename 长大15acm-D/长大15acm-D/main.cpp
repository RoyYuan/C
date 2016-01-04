//
//  main.cpp
//  长大15acm-D
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
int num[6];
long long int mins,maxs,out,now;
int price[6][11];
long long int temp[100005];

void dfs(int n,int next,long long int pre)
{
    if (n>5)
        return;
    for (int i=next; i<=num[n]; i++) {
        long long int tmp=pre+price[n][i];
        if (tmp<=maxs) {
            dfs(n+1,1,tmp);
            if (next==1)
                dfs(n, i+1, tmp);
            if (n==5)
                temp[++now]=tmp;
        }
    }
}
int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        out=0;
        now=0;
        for (int i=1; i<=5; i++)
            cin >> num[i];
        for (int i=1; i<=5; i++)
            for (int j=1; j<=num[i]; j++)
                cin >> price[i][j];
        cin >> mins >> maxs;
        dfs(4, 1, 0);
        for (int i=1; i<=num[3]; i++)
            for (long long int j=1; j<=now; j++) {
                long long int tmp=price[3][i]+temp[j];
                if (tmp>=mins && tmp<=maxs)
                    out++;
            }
        for (int i=1; i<=num[1]; i++)
            for (int j=1; j<=num[2]; j++)
                for (long long int x=1; x<=now; x++) {
                    long long int tmp=price[1][i]+price[2][j]+temp[x];
                    if (tmp>=mins && tmp<=maxs)
                        out++;
                }
        cout << out << endl;
    }
    return 0;
}
