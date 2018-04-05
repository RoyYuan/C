//
//  main.cpp
//  160807-10
//
//  Created by 袁子涵 on 16/8/7.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <set>
#include <string>
#include <map>

using namespace std;
int maze[4][4];
bool check()
{
    if (maze[0][0]==maze[1][0]) {
        for (int i=1; i<4; i++) {
            for (int j=0; j<4; j++) {
                if (maze[i][j]!=maze[i-1][j]) {
                    return 0;
                }
            }
        }
        return 1;
    }
    else
    {
        for (int i=1; i<4; i++) {
            for (int j=0; j<4; j++) {
                if (maze[j][i]!=maze[j][i-1]) {
                    return 0;
                }
            }
        }
        return 1;
    }
}
int Func()
{
    int out1=0,out2=0;
    for (int i=0; i<4; i++) {
        int num[5]={0},tmp=0;
        for (int j=0; j<4; j++)
            num[maze[i][j]]++;
        for (int j=1; j<=4; j++)
            tmp+=num[j];
        out1=max(out1,4-tmp);
    }
    for (int i=0; i<4; i++) {
        int num[5]={0},tmp=0;
        for (int j=0; j<4; j++)
            num[maze[j][i]]++;
        for (int j=1; j<=4; j++)
            tmp+=num[j];
        out2=max(out2,4-tmp);
    }
    return min(out1,out2);
}
void move(int mode,int num)
{
    if (mode==1) {
        int tmp=maze[num][0];
        for (int i=0; i<3; i++)
            maze[num][i]=maze[num][i+1];
        maze[num][3]=tmp;
    }
    else if (mode==2)
    {
        int tmp=maze[num][3];
        for (int i=3; i>0; i--)
            maze[num][i]=maze[num][i-1];
        maze[num][0]=tmp;
    }
    else if (mode==3)
    {
        int tmp=maze[0][num];
        for (int i=0; i<3; i++)
            maze[i][num]=maze[i+1][num];
        maze[3][num]=tmp;
    }
    else if (mode==4)
    {
        int tmp=maze[3][num];
        for (int i=3; i>0; i--)
            maze[i][num]=maze[i-1][num];
        maze[0][num]=tmp;
    }
}
bool dfs(int limit,int now)
{
    if (limit==now)
        return check();
    if (now+Func()>limit)
        return 0;
    for (int i=0; i<4; i++) {
        move(1,i);
        if (dfs(limit, now+1))
            return 1;
        move(2,i);
        move(2,i);
        if (dfs(limit, now+1))
            return 1;
        move(1,i);
        move(3,i);
        if (dfs(limit, now+1))
            return 1;
        move(4,i);
        move(4,i);
        if (dfs(limit, now+1))
            return 1;
        move(3,i);
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    int t,out;
    scanf("%d",&t);
    while (t--) {
        out=-1;
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                scanf("%d",&maze[i][j]);
            }
        }
        if (check()) {
            puts("0");
            continue;
        }
        for (int i=1; i<=5; i++) {
            if (dfs(i, 0)) {
                out=i;
                break;
            }
        }
        if (out>0)
            printf("%d\n",out);
        else
            puts("-1");
    }
    return 0;
}
