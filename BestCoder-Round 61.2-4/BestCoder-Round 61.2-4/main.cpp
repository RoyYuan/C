//
//  main.cpp
//  BestCoder-Round 61.2-4
//
//  Created by 袁子涵 on 15/11/14.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

typedef struct data
{
    long long int wt;
    long long int num;
}Data;

using namespace std;
Data a[10000010];
long long int seed,q,n,out;
long long int rand(long long int l,long long int r) {
    static long long mo=1e9+7, g=78125;
    return l+((seed*=g)%=mo)%(r-l+1);
}

int cmp(Data a,Data b)
{
    if (a.wt<b.wt) {
        return 1;
    }
    if (a.wt==b.wt) {
        return a.num>b.num;
    }
    else
        return 0;
}

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    while (T--) {
        long long int temp,now;
        cin >> n >> q >> seed;
        temp=q;
        now=n;
        memset(a, 0, sizeof(a));
        long long int sum=rand(q, 10000000);
        for(long long int i=1; i<=n; i++) {
            a[i].wt=rand(0, sum/(n-i+1));
            sum-=a[i].wt;
            a[i].num=i;
        }
        a[rand(1, n)].wt+=sum;
        sort(a+1, a+n+1, cmp);
        while (temp) {
            temp--;
            if (a[now].wt>a[now-1].wt && a[now].wt>a[now+1].wt) {
                a[now].wt--;
                continue;
            }
            else if(a[now].wt==a[now-1].wt){
                a[now].wt--;
                now--;
                continue;
            }
            else if(a[now].wt==a[now+1].wt){
                a[now+1].wt--;
                continue;
            }
        }
        sum=a[1].wt+a[1].num;
        for (long long int i=2; i<=n; i++) {
            sum^=(a[i].wt+a[i].num);
        }
        cout << sum << endl;
    }
    return 0;
}
