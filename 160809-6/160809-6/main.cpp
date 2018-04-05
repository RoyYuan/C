//
//  main.cpp
//  160809-6
//
//  Created by 袁子涵 on 16/8/9.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn=1.5*1e5;
bool can[maxn];
int v[51],m[51];
int main(int argc, const char * argv[]) {
    int n,total,out;
    while (scanf("%d",&n)!=EOF && n>=0) {
        total=out=0;
        memset(can, 0, sizeof(can));
        for (int i=1; i<=n; i++) {
            scanf("%d%d",&v[i],&m[i]);
            total+=v[i]*m[i];
        }
        for (int i=v[1]; i<=v[1]*m[1]; i+=v[1])
            can[i]=1;
        for (int i=2; i<=n; i++) {
            for (int j=0; j<=total/2; j++) {
                if (can[j])
                    for (int k=v[i]; k<=min(total/2-j,v[i]*m[i]); k+=v[i])
                        can[j+k]=1;
            }
        }
        for (int i=total/2; i>=0; i--) {
            if (can[i]) {
                out=i;
                break;
            }
        }
        printf("%d %d\n",total-out,out);
    }
    return 0;
}
