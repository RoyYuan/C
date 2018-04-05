//
//  main.cpp
//  XUPT14-4
//
//  Created by 袁子涵 on 16/11/3.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <utility>

using namespace std;
//1up2down3left4right
typedef struct line
{
    int flag;
    int num;
}line;
vector<line>l;
int n;
typedef struct node
{
    int x,y;
}node;
node a,b,c,d;
int main(int argc,const char * argv[]) {
    scanf("%d",&n);
    a.x=d.x=d.y=c.y=0;
    a.y=b.x=b.y=c.x=n;
    
    return 0;
}
