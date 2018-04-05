//
//  main.cpp
//  XUPT04-B
//
//  Created by 袁子涵 on 16/9/8.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>

using namespace std;
const int N=1e5+10;
const int INF=0x7fffffff;
int node[N];

int dis(int l,int r,int now){
    if(now<=l)  return r-now;
    if(now>=r)  return now-l;
    return min(now-2*l+r,2*r-now-l);
}
int main(int argc, const char * argv[]) {
    int n,a;
    for(int i=0;i<n;i++)
        scanf("%d",&node[i]);
    sort(node,node+n);
    if(n==1)
    {
        printf("0\n");
        return 0;
    }
    int ans=INF;
    if(a<=node[0])
        ans=min(ans,node[n-2]-a);
    else if(a>=node[n-1])
        ans=min(ans,a-node[1]);
    else {
        ans=min(ans,dis(node[1],node[n-1],a));
        ans=min(ans,dis(node[0],node[n-2],a));
    }
    printf("%d\n",ans);
    return 0;
}
