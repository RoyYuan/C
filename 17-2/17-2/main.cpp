//
//  main.cpp
//  17-2
//
//  Created by 袁子涵 on 16/4/17.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

long long int n;
long long int now,total;
long long int tmp1,tmp2,maxs,length;
typedef struct
{
    long long int h,w;
}node;
node Node[10005];
bool cmp(node a,node b)
{
    return a.h>b.h;
}
int main(int argc, const char * argv[]) {
    while (cin >> n) {
        if (n==0) {
            cout << 1 << endl;
            continue;
        }
        memset(Node, 0, sizeof(Node));
        total=maxs=0;
        for (long long int i=0; i<n; i++) {
            scanf("%lld %lld",&Node[i].h,&Node[i].w);
        }
        sort(Node+0,Node+n,cmp);
        maxs=Node[0].h+1;
        for (long long int i=0; i<n; i++) {
            total+=(maxs-Node[i].h)*Node[i].w;
        }
        cout << total << endl;
    }
    return 0;
}
