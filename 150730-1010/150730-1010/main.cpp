//
//  main.cpp
//  150730-1010
//
//  Created by 袁子涵 on 15/7/30.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int x,y;
int r,c,n,T;
int map[110][110];
int book[110][110];


typedef struct wt
{
    int x,y,direction;
}WT;

typedef struct water
{
    WT ball[4];
    int x,y,size;
    int A,B;
}Water;

Water wtr[110];



int main(int argc, const char * argv[]) {
    int times;
    while (scanf("%d%d%d%d",&r,&c,&n,&T)!=EOF) {
        memset(map, 0, sizeof(map));
        memset(book, 0, sizeof(book));
        for (int i=1; i<=n; i++) {
            cin >> wtr[i].x >> wtr[i].y >> wtr[i].size;
            wtr[i].A=1;
            wtr[i].B=wtr[i].size;
            map[wtr[i].x][wtr[i].y]=wtr[i].size;
            book[wtr[i].x][wtr[i].y]=1;
        }
        cin >> x >>y;
        times=T;
        wtr[0].A=0;
        map[x][y]+=4;
        wtr[0].x=x;
        wtr[0].y=y;
        for (int i=0; i<4; i++) {
            wtr[0].ball[i].x=x;
            wtr[0].ball[i].y=y;
            wtr[0].ball[i].direction=i+1;
        }
        while (times--) {
            
//            
//            for (int i=1; i<=r; i++) {
//                for (int j=1; j<=c; j++) {
//                    cout << map[i][j];
//                }
//                cout << endl;
//            }
//            cout <<endl<<endl;
            
            
            
            
            
            //先看各个小水珠
            for (int i=0; i<=n; i++) {
                //当已经爆裂后
                if (wtr[i].A==0) {
                    //四个小水珠
                    for (int j=0; j<4; j++) {
                        //如果小水珠还在
                        if (wtr[i].ball[j].direction!=-1) {
                            //相应的移动
                            switch (wtr[i].ball[j].direction) {
                                case 1:
                                    if (wtr[i].ball[j].x==1) {
                                        map[wtr[i].ball[j].x][wtr[i].ball[j].y]--;
                                        wtr[i].ball[j].direction=-1;
                                        break;
                                    }
                                    map[wtr[i].ball[j].x][wtr[i].ball[j].y]--;
                                    wtr[i].ball[j].x--;
                                    map[wtr[i].ball[j].x][wtr[i].ball[j].y]++;
                                    if (book[wtr[i].ball[j].x][wtr[i].ball[j].y]) {
                                        wtr[i].ball[j].direction=-1;
                                    }
                                    break;
                                case 2:
                                    if (wtr[i].ball[j].x==r) {
                                        map[wtr[i].ball[j].x][wtr[i].ball[j].y]--;
                                        wtr[i].ball[j].direction=-1;
                                        break;
                                    }
                                    map[wtr[i].ball[j].x][wtr[i].ball[j].y]--;
                                    wtr[i].ball[j].x++;
                                    map[wtr[i].ball[j].x][wtr[i].ball[j].y]++;
                                    if (book[wtr[i].ball[j].x][wtr[i].ball[j].y]) {
                                        wtr[i].ball[j].direction=-1;
                                    }
                                    break;
                                case 3:
                                    if (wtr[i].ball[j].y==1) {
                                        map[wtr[i].ball[j].x][wtr[i].ball[j].y]--;
                                        wtr[i].ball[j].direction=-1;
                                        break;
                                    }
                                    map[wtr[i].ball[j].x][wtr[i].ball[j].y]--;
                                    wtr[i].ball[j].y--;
                                    map[wtr[i].ball[j].x][wtr[i].ball[j].y]++;
                                    if (book[wtr[i].ball[j].x][wtr[i].ball[j].y]) {
                                        wtr[i].ball[j].direction=-1;
                                    }
                                    break;
                                case 4:
                                    if (wtr[i].ball[j].y==c) {
                                        map[wtr[i].ball[j].x][wtr[i].ball[j].y]--;
                                        wtr[i].ball[j].direction=-1;
                                        break;
                                    }
                                    map[wtr[i].ball[j].x][wtr[i].ball[j].y]--;
                                    wtr[i].ball[j].y++;
                                    map[wtr[i].ball[j].x][wtr[i].ball[j].y]++;
                                    if (book[wtr[i].ball[j].x][wtr[i].ball[j].y]) {
                                        wtr[i].ball[j].direction=-1;
                                    }
                                    break;
                                default:
                                    break;
                            }
                        }
                    }
                    continue;
                }
                //水滴未爆裂时
                continue;
            }
            //判断是否有新的水珠爆裂
            for (int i=1; i<=n; i++) {
                //如果还没有爆裂
                if (wtr[i].A==1) {
                    if (map[wtr[i].x][wtr[i].y]>4) {
                        wtr[i].A=0;
                        wtr[i].B=T-times;
                        book[wtr[i].x][wtr[i].y]=0;
                        map[wtr[i].x][wtr[i].y]=4;
                        //clear1(wtr[i].x, wtr[i].y);
                        //自身爆出小水珠
                        for (int j=0; j<4; j++) {
                            wtr[i].ball[j].x=wtr[i].x;
                            wtr[i].ball[j].y=wtr[i].y;
                            wtr[i].ball[j].direction=j+1;
                        }
                    }
                    //如果小于4
                    else if (map[wtr[i].x][wtr[i].y]<=4)
                    {
                        wtr[i].B=map[wtr[i].x][wtr[i].y];
                        wtr[i].size=map[wtr[i].x][wtr[i].y];
                        //clear1(wtr[i].x, wtr[i].y);
                    }
                }
            }
        }
        //读出数据，输出
        for (int i=1; i<=n; i++) {
            cout << wtr[i].A << " " << wtr[i].B << endl;
        }
    }
    return 0;
}
