//
//  main.cpp
//  基础DP1-D-Doing Homework
//
//  Created by 袁子涵 on 15/10/23.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

#define INF 0x7fffffff

using namespace std;

int N;

typedef struct {
    char name[105];
    int d,c;
}course;

typedef struct {
    int cost,substract,pre,pres;
}Dp;

course classes[20];
Dp dp[(1<<15)+10];

void outputname(int num)
{
    if (num==0) {
        return;
    }
    outputname(num-dp[num].pres);
    printf("%s\n",classes[dp[num].pre].name);
    
}
int main(int argc, const char * argv[]) {
    int T,sub,temp,bit;
    cin  >> T;
    while (T--) {
        cin >> N;
        for (int i=1; i<=N; i++) {
            scanf("%s%d%d",classes[i].name,&classes[i].d,&classes[i].c);
        }
        dp[0].cost=0;
        dp[0].pre=0;
        dp[0].substract=0;
        bit=1<<N;
        for (int i=1; i<=bit-1; i++) {
            dp[i].substract=INF;
            for (int j=N; j>=1; j--) {
                temp=1<<(j-1);
                if (i&temp) {
                    sub=dp[i-temp].cost+classes[j].c-classes[j].d;
                    if (sub<0) {
                        sub=0;
                    }
                    if (dp[i].substract>sub+dp[i-temp].substract) {
                        dp[i].substract=min(sub+dp[i-temp].substract,dp[i].substract);
                        dp[i].cost=dp[i-temp].cost+classes[j].c;
                        dp[i].pres=temp;
                        dp[i].pre=j;
                    }
                }
            }
        }
        cout << dp[bit-1].substract << endl;
        outputname(bit-1);
    }
    return 0;
}
