//
//  main.cpp
//  最短路练习-H-Cow Contest
//
//  Created by 袁子涵 on 15/10/14.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define INF 999999999
#define maxof(a,b)  ((a)>(b)?(a):(b))
#define minof(a,b)  ((a)>(b)?(b):(a))

using namespace std;

int N,M;
int sum[105],dis[105][105],out=0;

void floyd()
{
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<N; k++) {
                switch (dis[j][i]+dis[i][k]) {
                    case -2:
                        dis[j][k]=-1;
                        break;
                    case 2:
                        dis[j][k]=1;
                    default:
                        break;
                }
            }
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (dis[i][j]!=0) {
                sum[i]++;
            }
        }
    }
    for (int i=0; i<N; i++) {
        if (sum[i]==N-1) {
            out++;
        }
    }
}

int main(int argc, const char * argv[]) {
    int a,b;
    memset(sum, 0, sizeof(sum));
    memset(dis, 0, sizeof(dis));
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        cin >> a >> b;
        a--;
        b--;
        dis[a][b]=1;
        dis[b][a]=-1;
    }
    floyd();
    cout << out << endl;
    return 0;
}
