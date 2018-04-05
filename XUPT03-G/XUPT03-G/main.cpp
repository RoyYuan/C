//
//  main.cpp
//  XUPT03-G
//
//  Created by 袁子涵 on 16/6/2.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <utility>
#include <set>
using namespace std;

const int MAXN=100005;
set<long long int>S;
set<long long int>Q;
long long int Fi[100];
int t;
bool flag=1;
long long int n,m,a[MAXN],op,l,r;
inline long long int LowBit(long long int x)    {return (x&(-x));}
inline long long int GetSum(long long int num)
{
    long long int sum=0;
    while(num>0)
    {
        sum+=a[num];
        num-=LowBit(num);
    }
    return sum;
}
inline void Add(long long int num,long long int x)
{
    while(num<=n)
    {
        a[num]+=x;
        num+=LowBit(num);
    }
}
int main(void)
{
    long long int total=1;
    Fi[0]=1;
    Fi[1]=1;
    while (total<91) {
        total++;
        Fi[total]=Fi[total-2]+Fi[total-1];
    }
    for (int i=0; i<=total; i++)
        S.insert(Fi[i]);
    while (scanf("%lld%lld",&n,&m)!=EOF) {
        Q.clear();
        for (long long int i=1; i<=n; i++) {
            Q.insert(i);
        }
        memset(a, 0, sizeof(a));
        for (long long int i=1; i<=m; i++) {
            scanf("%lld%lld%lld",&op,&l,&r);
            if (op==1)
            {
                Add(l, r);
                Q.insert(l);
            }
            else if (op==2)
                printf("%lld\n",GetSum(r)-GetSum(l-1));
            else
            {
                set<long long int>::iterator it=Q.lower_bound(l);
                while (it!=Q.end() && *it<=r) {
                    long long int tmp3=GetSum(*it)-GetSum(*it-1);
                    if (tmp3==1) {
                        Q.erase(it);
                        it=Q.lower_bound(l);
                        continue;
                    }
                    if (tmp3==0) {
                        Add(*it, 1);
                        Q.erase(it);
                        it=Q.lower_bound(l);
                        continue;
                    }
                    long long int tmp1=*(--S.lower_bound(tmp3)),tmp2=*S.lower_bound(tmp3);
                    if (abs(tmp1-tmp3)<=abs(tmp2-tmp3))
                        Add(*it, tmp1-tmp3);
                    else
                        Add(*it, tmp2-tmp3);
                    Q.erase(it);
                    it=Q.lower_bound(l);
                }
            }
        }
    }
    return 0;
}
