//
//  main.cpp
//  长大15acm-C
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
#define MAXN 1000005
using namespace std;

long long int pre[MAXN],n,m;
void init()
{
    for (long long int i=1; i<=n; i++)
        pre[i]=i;
}
long long int find(long long int num)
{
    if (pre[num]!=num)
        pre[num]=find(pre[num]);
    return pre[num];
}
void join(long long int num1,long long int num2)
{
    long long int pre1=find(num1),pre2=find(num2);
    if (pre1==pre2) {
        return;
    }
    pre[pre1]=pre2;
}
int main(int argc, const char * argv[]) {
    long long int a,b,pre1,pre2,out=0;
    int t;
    cin >> t;
    while (t--) {
        out=0;
        cin >> n >> m;
        init();
        for (long long int i=1; i<=m; i++) {
            scanf("%lld%lld",&a,&b);
            pre1=find(a);
            pre2=find(b);
            if (pre1!=pre2) {
                out++;
                join(pre1, pre2);
            }
        }
        cout << out << endl;
    }
    return 0;
}
