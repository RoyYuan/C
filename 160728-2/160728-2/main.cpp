//
//  main.cpp
//  160728-2
//
//  Created by 袁子涵 on 16/7/28.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int MAXN=100005;
long long int n,a[MAXN],tmp;
long long int out[MAXN],l,R,L;
inline long long int LowBit(long long int x)
{
    return x&(-x);
}
inline void Add(long long int num,long long int x)
{
    while(num>0)
    {
        a[num]+=x;
        num-=LowBit(num);
    }
}
inline long long int GetVaule(long long int num)
{
    long long int sum=0;
    while(num<=n)
    {
        sum+=a[num];
        num+=LowBit(num);
    }
    return sum;
}
int t;
int main(int argc, const char * argv[]) {
    scanf("%d",&t);
    int cas=0;
    while (t--) {
        cas++;
        scanf("%lld",&n);
        memset(a, 0, sizeof(a));
        for (long long int i=1; i<=n; i++) {
            scanf("%lld",&tmp);
            l=GetVaule(tmp);
            L=min(i-l,tmp);
            R=max(tmp,i);
            out[tmp]=abs(L-R);
            Add(tmp-1, 1);
        }
        printf("Case #%d:",cas);
        for (long long int i=1; i<=n; i++) {
            printf(" %lld",out[i]);
        }
        printf("\n");
    }
    return 0;
}
