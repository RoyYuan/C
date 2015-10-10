//
//  main.cpp
//  简单搜索-D-Flip Tile
//
//  Created by 袁子涵 on 15/7/26.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#define Max 35000

using namespace std;

int flag=0;
int M,N;
int map[20][20];
int b[20][20];
int times[20][20];
int s;
int out[20][20];


void g(int x,int y)
{
//    if (a[x][y]==1) {
//        a[x][y]=0;
//    }
//    else
//    {
//        a[x][y]=1;
//    }
    b[x][y]^=1;
}

//翻转函数
void G(int x,int y)
{
    g(x, y);
    if (x>0) {
        g(x-1, y);
    }
    if (x<M-1) {
        g(x+1, y);
    }
    if (y>0) {
        g(x, y-1);
    }
    if (y<N-1) {
        g(x, y+1);
    }
}

////根据状态推下面格子
//int f(int x)
//{
//    int flag=1;
//    //第一行
//    for (int i=0; i<N; i++) {
//        if (!(x & (1<<(N-i-1)))) {
//            continue;
//        }
//        else
//        {
//            flag=0;
//            times[0][i]++;
//            s++;
//            G(0, i);
//        }
//    }
//    if (flag && x!=0) {
//        return 0;
//    }
//    for (int i=1; i<M; i++) {
//        for (int j=0; j<N; j++) {
//            if (a[i-1][j]==1) {
//                times[i][j]++;
//                s++;
//                G(i, j);
//            }
//        }
//    }
//    for (int i=0; i<N; i++) {
//        if (a[M-1][i]==1) {
//            s=Max;
//            return 0;
//        }
//    }
//    return 1;
//}

bool check(int x){
    for(int i = 0; i < N; i ++){
        if(x & (1 << i)){
            out[0][i] = 1;
            b[0][i] ^= 1;
            if(M > 1)
                b[1][i] ^= 1;
            if(i - 1 >= 0)
                b[0][i - 1] ^= 1;
            if(i + 1 < N)
                b[0][i + 1] ^= 1;
        }
    }
    
    for(int i = 1; i < M; i ++){
        for(int j = 0; j < N; j ++){
            if(b[i - 1][j]){
                out[i][j] = 1;
                b[i][j] ^= 1;
                b[i - 1][j] ^= 1;
                if(i + 1 < M)
                    b[i + 1][j] ^= 1;
                if(j - 1 >= 0)
                    b[i][j - 1] ^= 1;
                if(j + 1 < N)
                    b[i][j + 1] ^= 1;
            }
        }
    }
    
    for(int i = 0; i < N; i ++){
        if(b[M - 1][i])
            return false;
    }
    return true;
}

int main()
{
    int flag=0;
    int Min=Max;
    memset(map, 0, sizeof(map));
    memset(times, 0, sizeof(times));
    cin >> M >> N;
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }
    for (int i=0; i<(1<<N); i++) {
        memcpy(b, map,sizeof(map));
        memset(out, 0, sizeof(times));
        s=0;
        if(check(i))
        {
            flag=1;
            for (int i=0; i<M; i++) {
                for (int j=0; j<N; j++) {
                    cout << out[i][j]<<" ";
                }
                cout << endl;
            }
            return 0;
        }
//        if (s<Min) {
//            Min=s;
//            memcpy(out, times, sizeof(times));
//        }
    }
    cout << "IMPOSSIBLE" << endl;
//    if (Min==Max) {
//        cout << "Impossible" << endl;
//    }
//    else
//    {
//        for (int i=0; i<M; i++) {
//            for (int j=0; j<N; j++) {
//                cout << out[i][j]<<" ";
//                
//            }
//            cout << endl;
//        }
//    }
}
