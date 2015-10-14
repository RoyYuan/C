//
//  main.cpp
//  最短路练习-G-MPI maelstrom
//
//  Created by 袁子涵 on 15/10/14.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define minof(a,b)  ((a)>(b)?(b):(a))
#define maxof(a,b)  ((a)>(b)?(a):(b))
#define INF 999999999
using namespace std;

int n;
long long int map[105][105],dis[105],mins,out;
bool book[105];

void dijkstra()
{
    int next=0;
    for (int i=0; i<n; i++) {
        dis[i]=map[0][i];
    }
    book[0]=1;
    for (int i=0; i<n; i++) {
        mins=INF;
        for (int j=0; j<n; j++) {
            if (mins>dis[j] && book[j]==0) {
                mins=dis[j];
                next=j;
            }
        }
        book[next]=1;
        for (int j=0; j<n; j++) {
            if (mins+map[next][j]<dis[j]) {
                dis[j]=mins+map[next][j];
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    char in1[20];
    long long int in2;
    memset(book, 0, sizeof(book));
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            cin >> in1;
            if (in1[0]=='x') {
                map[i][j]=INF;
                map[j][i]=INF;
                continue;
            }
            in2=atoi(in1);
            map[i][j]=in2;
            map[j][i]=in2;
        }
        map[i][i]=0;
    }
    dijkstra();
    out=0;
    for (int i=0; i<n; i++) {
        out=maxof(out, dis[i]);
    }
    cout << out << endl;
    return 0;
}
