//
//  main.cpp
//  POJ-3660-Cow Contest
//
//  Created by 袁子涵 on 15/11/28.
//  Copyright © 2015年 袁子涵. All rights reserved.
//
//  32ms    780KB

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#define MAXN 105
#define INF 0x3f3f3f3f

using namespace std;
int N,M,sum=0;
int dis[MAXN][MAXN];
int main(int argc, const char * argv[]) {

    cin >> N >> M;
    memset(dis, 0, sizeof(dis));
    int a,b;
    for (int i=1; i<=M; i++) {
        scanf("%d %d",&a,&b);
        dis[a][b]=1;
        dis[b][a]=-1;
    }
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            for (int k=1; k<=N; k++) {
                if (dis[j][k]==0 && abs(dis[j][i]+dis[i][k])==2) {
                    dis[j][k]=dis[j][i];
                }
            }
        }
    }
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (dis[i][j]==0 && i!=j) {
                break;
            }
            if (j==N) {
                sum++;
            }
        }
    }
    cout << sum << endl;
    return 0;
}
