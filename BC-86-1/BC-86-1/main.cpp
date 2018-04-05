//
//  main.cpp
//  BC-86-1
//
//  Created by 袁子涵 on 16/8/6.
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
#include <queue>
#include <stack>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        long long int total=0,tmp;
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            scanf("%lld",&tmp);
            total+=tmp;
        }
        for (int i=1; i<=m; i++) {
            scanf("%lld",&tmp);
            if (tmp>total) {
                printf("1");
            }
            else
                printf("0");
        }
        printf("\n");
    }
    return 0;
}
