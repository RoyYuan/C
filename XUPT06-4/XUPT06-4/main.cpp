//
//  main.cpp
//  XUPT06-4
//
//  Created by 袁子涵 on 16/9/14.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <utility>
#include <map>

using namespace std;
const int maxn=1000005;
long long int n,m,a[maxn];
long long int num[maxn],sum[maxn],out[maxn];
map<long long int,long long int>last;
vector<pair<long long int,long long int>>q[maxn];
inline long long int LowBit(long long int x)    {return (x&(-x));}
inline long long int GetSum(long long int num)
{
    long long int sum=0;
    while(num>0)
    {
        sum^=a[num];
        num-=LowBit(num);
    }
    return sum;
}
inline void Add(long long int num,long long int x)
{
    while(num<=n)
    {
        a[num]^=x;
        num+=LowBit(num);
    }
}
int main(int argc, const char * argv[]) {
    long long int l,r;
    scanf("%lld",&n);
    for (long long int i=1; i<=n; i++) {
        scanf("%lld",&num[i]);
        sum[i]=sum[i-1]^num[i];
    }
    scanf("%lld",&m);
    for (long long int i=1;i<=m; i++) {
        scanf("%lld%lld",&l,&r);
        q[r].push_back(make_pair(l, i));
    }
    for (long long int i=1; i<=n; i++) {
        if (last[num[i]])
            Add(last[num[i]], num[i]);
        last[num[i]]=i;
        Add(i, num[i]);
        for (long long int j=0; j<q[i].size(); j++) {
            long long int nowleft=q[i][j].first,nownum=q[i][j].second;
            out[nownum]=GetSum(i)^GetSum(nowleft-1)^sum[i]^sum[nowleft-1];
        }
    }
    for (long long int i=1; i<=m; i++)
        printf("%lld\n",out[i]);
    return 0;
}
