//
//  main.cpp
//  XUPT05-B
//
//  Created by 袁子涵 on 16/9/9.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <set>

using namespace std;
typedef struct Node
{
    long long int price,num;
    bool operator<(const Node &r)const
    {
        return price<r.price;
    }
}Node;
vector<Node>node;
long long int n,q,now,maxp;
int main(int argc, const char * argv[]) {
    Node tmp;
    scanf("%lld",&n);
    for (long long int i=1; i<=n; i++)
    {
        scanf("%lld",&tmp.price);
        maxp=max(maxp,tmp.price);
        node.push_back(tmp);
    }
    sort(node.begin(),node.end());
    scanf("%lld",&q);
    vector<Node>::iterator it=node.begin();
    for (long long int i=1; it!=node.end(); it++,i++)
        it->num=i;
    for (long long int i=1; i<=q; i++) {
        scanf("%lld",&now);
        if (now>=maxp) {
            printf("%lld\n",n);
            continue;
        }
        tmp.price=now;
        tmp.num=1;
        it=upper_bound(node.begin(), node.end(), tmp);
        if (it==node.end()) {
            printf("%lld\n",n);
            continue;
        }
        printf("%lld\n",it->num-1);
    }
    return 0;
}
