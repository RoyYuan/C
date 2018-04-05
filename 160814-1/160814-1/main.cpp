//
//  main.cpp
//  160814-1
//
//  Created by 袁子涵 on 16/8/14.
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
#include <map>
#include <utility>
#include <set>

using namespace std;
char str[10000005];
int main(int argc, const char * argv[]) {
    int cas=0;
    while (scanf("%s",str)!=EOF) {
        int yushu=0;
        printf("Case #%d: ",++cas);
        for (int i=0; i<strlen(str); i++) {
            yushu=yushu*10+str[i]-48;
            yushu%=10001;
        }
        if (yushu==0)
            printf("YES");
        else
            printf("NO");
        puts("");
    }
    return 0;
}
