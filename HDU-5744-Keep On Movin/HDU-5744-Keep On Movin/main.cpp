//
//  main.cpp
//  HDU-5744-Keep On Movin
//
//  Created by 袁子涵 on 16/7/21.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
using namespace std;
int t;
long long int n,num,total1,total2,out;
int main(void)
{
    scanf("%d",&t);
    while (t--) {
        total1=total2=0;
        scanf("%lld",&n);
        for (long long int i=0; i<n; i++)
        {
            scanf("%lld",&num);
            if (num&1)
                total1++;
            total2+=num/2;
        }
        if (total1==0)
            out=total2*2;
        else
            out=2*(total2/total1)+1;
        printf("%lld\n",out);
    }
    return 0;
}
