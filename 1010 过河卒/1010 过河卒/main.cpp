//
//  main.cpp
//  1010 过河卒
//
//  Created by 袁子涵 on 15/5/21.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int sum;
bool book[20][20];

struct coordinate
{
    int x;
    int y;
}final,hourse,origin;

void sign()
{
    book[hourse.x][hourse.y]=1;
    if (hourse.x>=2) {
        book[hourse.x-2][hourse.y+1]=1;
        if (hourse.y>=1) {
            book[hourse.x-2][hourse.y-1]=1;
        }
    }
    if (hourse.x>=1) {
        if (hourse.y>=2) {
            book[hourse.x-1][hourse.y-2]=1;
        }
        book[hourse.x-1][hourse.y+2]=1;
    }
    if (hourse.y>=2) {
        book[hourse.x+1][hourse.y-2]=1;
    }
    if (hourse.y>=1) {
        book[hourse.x+2][hourse.y-1]=1;
    }
    book[hourse.x+1][hourse.y+2]=1;
    book[hourse.x+2][hourse.y+1]=1;
    
}

void dfs(struct coordinate now)//先下后右
{
    if (now.x==final.x && now.y==final.y) {
        sum++;
        return;
    }
    if (now.x<final.x && !book[now.x+1][now.y]) {
        now.x++;
        dfs(now);
        now.x--;
    }
    if (now.y<final.y && !book[now.x][now.y+1]) {
        now.y++;
        dfs(now);
        now.y--;
    }
    return;
    
}

int main(int argc, const char * argv[]) {
    scanf("%d%d%d%d",&final.x,&final.y,&hourse.x,&hourse.y);
    memset(book,0,sizeof(book));
    origin.x=0;
    origin.y=0;
    sign();
    dfs(origin);
    printf("%d",sum);
    return 0;
}
