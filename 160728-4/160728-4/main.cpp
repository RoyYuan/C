//
//  main.cpp
//  160728-4
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
int t,cas;
long long int n,b[MAXN],out,tmp;
long long int num[MAXN];
long long int Search(long long int num,long long int low,long long int high)
{
    long long int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(num>=b[mid])  low=mid+1;
        else   high=mid-1;
    }
    return low;
}
long long int DP(long long int n)
{
    long long int i,len,pos;
    b[1]=num[1];
    len=1;
    for(i=2;i<=n;i++)
    {
        if(num[i]>b[len])
        {
            len=len+1;
            b[len]=num[i];
        }
        else
        {
            pos=Search(num[i],1,len);
            b[pos]=num[i];
        }
    }
    return len;
}
long long int total=0;
bool flag;
int main(int argc, const char * argv[]) {
    scanf("%d",&t);
    while (t--) {
        long long int now=0;
        total=0;
        cas++;
        scanf("%lld",&n);
        for (long long int i=1; i<=n; i++) {
            scanf("%lld",&tmp);
            if (tmp==0)
                total++;
            else
                num[++now]=tmp-total;
        }
        out=DP(now);
        if (total==n)
            out=0;
        cout << "Case #" << cas << ": " << out+total << endl;
    }
    return 0;
}
