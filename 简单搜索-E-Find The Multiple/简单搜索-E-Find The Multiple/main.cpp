//
//  main.cpp
//  简单搜索-E-Find The Multiple
//
//  Created by 袁子涵 on 15/8/1.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int n;
unsigned long long int m;

int dfs(int step,unsigned long long int num)
{
    if (num%n==0) {
        m=num;
        return 1;
    }
    if (step>=19) {
        return 0;
    }
    if(dfs(step+1, num*10))
        return 1;
    if(dfs(step+1, num*10+1))
        return 1;
    return 0;
}


int main(int argc, const char * argv[]) {
    while (scanf("%d",&n)!=EOF) {
        if (n==0) {
            break;
        }

        dfs(0,1);
        cout << m << endl;
    }
    return 0;
}
