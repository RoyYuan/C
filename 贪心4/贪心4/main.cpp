//
//  main.cpp
//  贪心4
//
//  Created by 袁子涵 on 17/2/21.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <list>
#include <map>
using namespace::std;
typedef struct programme
{
    int start,end;
    bool operator < (const programme &r)const
    {return end<r.end;}
}programme;
programme PG[105];
int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
        if (n==0)   break;
        for (int i=0; i<n; i++)
            cin >> PG[i].start >> PG[i].end;
        sort(PG+0,PG+n);
        int now=PG[0].end,out=1;
        for (int i=1; i<n; i++) {
            if (PG[i].start>=now) {
                out++;
                now=PG[i].end;
            }
        }
        cout << out << endl;
    }
    return 0;
}
