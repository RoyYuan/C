//
//  main.cpp
//  1219 骑士游历
//
//  Created by 袁子涵 on 15/6/18.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

int n,m;
unsigned long long int s[51][51];
int book[51][51];

struct  place
{
    int x;
    int y;
}hourse,final;

unsigned long long int dp(int x,int y)
{
    if (x==hourse.x && y==hourse.y) {
        return 1;
    }
    if(x<hourse.x || y<1 || x>final.x || y>m)
        return 0;
    if (book[x][y]) {
        return s[x][y];
    }
    s[x][y]=dp(x-1,y-2)+dp(x-1,y+2)+dp(x-2,y-1)+dp(x-2,y+1);
    book[x][y]=1;
    return s[x][y];
}


int main(int argc, const char * argv[]) {
    
    cin>>n>>m;
    cin>>hourse.x>>hourse.y>>final.x>>final.y;
    memset(s, 0, sizeof(s));
    memset(book, 0, sizeof(book));
    dp(final.x, final.y);
    cout<<s[final.x][final.y]<<endl;
    return 0;
}
