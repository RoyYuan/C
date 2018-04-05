//
//  main.cpp
//  贪心7
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
//x*x+x-2n=0;
//1+8n;
//(-1+sqrt(1+8n))/2
int main(int argc, const char * argv[]) {
    int n,out,left;
    cin >> n;
    out=(-1+sqrt(1+8*n))/2;
    left=out-(n-(out*out+out)/2);
    cout << out << endl;
    for (int i=1; i<=out; i++) {
        if (i>left)
            cout << i+1 << " ";
        else
            cout << i << " ";
    }
    cout << endl;
    return 0;
}
