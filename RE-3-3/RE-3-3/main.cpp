//
//  main.cpp
//  RE-3-3
//
//  Created by 袁子涵 on 17/8/2.
//  Copyright © 2017年 袁子涵. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <utility>
using namespace std;
const int maxn=105;
int num[maxn][maxn],n,q,c,x,y,s;
long long int B[maxn][maxn],t;
vector<int>maze[maxn][maxn];
int BB[15][maxn][maxn],maxx,maxy;
int Get_B(int x,int y,int time)
{
    int re=0;
    for (int i=0; i<maze[x][y].size(); i++) {
        re+=(maze[x][y][i]+time)%(c+1);
    }
    return re;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> n >> q >> c;
    for (int i=0; i<n; i++) {
        cin >> x >> y >> s;
        x++,y++;
        num[x][y]++;
        maxx=max(maxx,x);
        maxy=max(maxy,y);
        maze[x][y].push_back(s);
    }
    for (int now=0; now<=c+1; now++) {
//        for (int i=0; i<=maxx; i++) {
//            BB[now][i][0]=Get_B(i, 0, now)+BB[now][i-1][0];
//        }
//        for (int i=0; i<=maxy; i++) {
//            BB[now][0][i]=Get_B(0, i, now)+BB[now][0][i-1];
//        }
        for (int i=2; i<=maxx+1; i++) {
            for (int j=2; j<=maxy+1; j++) {
                BB[now][i][j]=Get_B(i-1,j-1,now)+BB[now][i][j-1]+BB[now][i-1][j]-BB[now][i-1][j-1];
            }
        }
    }
//    for (int i=0; i<=maxx; i++) {
//        B[i][0]=num[i][0]*c+B[i-1][0];
//    }
//    for (int i=0; i<=maxy; i++) {
//        B[0][i]=num[0][i]*c+B[0][i-1];
//    }
//    for (int i=2; i<=maxx+1; i++) {
//        for (int j=2; j<=maxy+1; j++) {
//            B[i][j]=num[i-1][j-1]*c+B[i][j-1]+B[i-1][j]-B[i-1][j-1];
//        }
//    }
    int x1,x2,y1,y2;
    for (int i=0; i<q; i++) {
        cin >> t >> x1 >> y1 >> x2 >> y2;
        t=t%(c+1);
        x2+=2,y2+=2;
        if (x1>maxx && y1>maxy) {
            cout << 0 << endl;
            continue;
        }
        x1=min(x1,maxx+1),x2=min(x2,maxx+1),y1=min(y1,maxy+1),y2=min(y2,maxy+1);
        cout << BB[t][x2][y2]+BB[t][x1+1][y1+1]-BB[t][x1+1][y2]-BB[t][x2][y1+1] << endl;
//        if (t<c) {
//            cout << BB[t][x2][y2]+BB[t][x1][y1]-BB[t][x1][y2]-BB[t][x2][y1] << endl;
//        }
//        else
//            cout << B[x2][y2]+B[x1][y1]-B[x1][y2]-B[x2][y1] << endl;
    }
    return 0;
}
//4 10 2
//0 0 1
//0 1 1
//1 0 1
//1 1 1
//0 0 0 1 1
