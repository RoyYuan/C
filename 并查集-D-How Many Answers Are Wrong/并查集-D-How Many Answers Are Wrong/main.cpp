//
//  main.cpp
//  并查集-D-How Many Answers Are Wrong
//
//  Created by 袁子涵 on 16/2/18.
//  Copyright © 2016年 袁子涵. All rights reserved.
//
//  78ms    4348KB

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define MAXN 200005
using namespace::std;
long long int n,m,a,b,sum,total=0;
long long int father[MAXN],num[MAXN];

long long int find(long long int p)
{
    long long int tmp;
    if (p!=father[p])
    {
        tmp=father[p];
        father[p]=find(father[p]);
        num[p]+=num[tmp];
    }
    return father[p];
}

int main(int argc, const char * argv[]) {
    while (cin >> n >> m) {
        total=0;
        memset(num, 0, sizeof(num));
        for (long long int i=0; i<=n; i++)
            father[i]=i;
        for (long long int i=1; i<=m; i++) {
            scanf("%lld %lld %lld",&a,&b,&sum);
            a--;
            long long int fa=find(a),fb=find(b);
            if (fa==fb) {
                if (num[b]-num[a]!=sum)
                    total++;
            }
            else
            {
                father[fb]=fa;
                num[fb]=sum+num[a]-num[b];
            }
        }
        cout << total << endl;
    }
    return 0;
}
