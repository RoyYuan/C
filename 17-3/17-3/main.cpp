//
//  main.cpp
//  17-3
//
//  Created by 袁子涵 on 16/4/17.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define INF 0x3f3f3f3f
using namespace std;
int t;
long long int n;
long long int num[50005],out=0;
long long int S[50005],d[50005];
/*最长不上升子序列 POJ 1887*/
void init()
{
    for(long long int i = 1; i <= n; i++) S[i] = -INF; //注意初始值
    memset(d, 0, sizeof(d));
}

long long int BSearch(long long int x, long long int y,long long int v)
{
    while(x <= y)
    {
        long long int mid = x+(y-x)/2;
        if(S[mid] > v) x = mid+1; //注意看二分的变化
        else y = mid-1;
    }
    return x;
}

long long int  dp()
{
    init();
    long long int ans = 0;
    for(long long int i = 1; i <= n; i++)
    {
        long long int x = 1, y = i;
        long long int pos = BSearch(x, y, num[i]);
        d[i] = pos;
        S[d[i]] = max(S[d[i]], num[i]); //max
        ans = max(ans, d[i]);
    }
    return ans;
}




int main(int argc, const char * argv[]) {
    cin >> t;
    while (t--) {
        scanf("%lld",&n);
        memset(num, 0, sizeof(num));
        for (long long int i=1; i<=n; i++) {
            scanf("%lld",&num[i]);
        }
        out=dp();
        cout << out << endl;
    }
    return 0;
}
