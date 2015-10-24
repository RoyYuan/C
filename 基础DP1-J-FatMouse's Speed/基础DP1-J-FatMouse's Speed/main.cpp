//
//  main.cpp
//  基础DP1-J-FatMouse's Speed
//
//  Created by 袁子涵 on 15/10/24.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  15ms    1604KB

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

using namespace std;

typedef struct{
    int wt,spd,pre,num;
}mouse;

mouse mice[1005];
bool visit[1005];
int n=1,num=1;

int DP(int x)
{
    if (visit[x]) {
        return mice[x].num;
    }
    for (int i=1; i<=num; i++) {
        if (mice[i].wt<mice[x].wt && mice[i].spd>mice[x].spd && DP(i)+1>mice[x].num) {
            mice[x].num=mice[i].num+1;
            mice[x].pre=i;
        }
    }
    visit[x]=1;
    return mice[x].num;
}

void output(int x)
{
    if (mice[x].pre) {
        output(mice[x].pre);
    }
    printf("%d\n",x);
}

int main(int argc, const char * argv[]) {
    int tail=1;
    memset(visit, 0, sizeof(visit));
    while (scanf("%d%d",&mice[num].wt,&mice[num].spd)!=EOF && mice[num].wt!=0) {
        mice[num].pre=0;
        mice[num].num=1;
        num++;
    }
    for (int i=1; i<=num; i++) {
        if (DP(i)>n) {
            n=mice[i].num;
            tail=i;
        }
    }
    cout << n << endl;
    output(tail);
    return 0;
}
