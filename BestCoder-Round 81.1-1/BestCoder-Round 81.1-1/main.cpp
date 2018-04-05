//
//  main.cpp
//  BestCoder-Round 81.1-1
//
//  Created by 袁子涵 on 16/4/22.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace::std;

int t;
int n,m,a,x,y;
long long int q;
int M[10005][10005];
void f1()
{
    for (int i=1; i<=m; i++) {
        swap(M[x][i], M[y][i]);
    }
}
void f2()
{
    for (int i=1; i<=n; i++) {
        swap(M[i][x], M[i][y]);
    }
}
void f3()
{
    for (int i=1; i<=m; i++) {
        M[x][i]+=y;
    }
}
void f4()
{
    for (int i=1; i<=n; i++) {
        M[i][x]+=y;
    }
}
void f()
{
    switch (a) {
        case 1:
            f1();
            break;
        case 2:
            f2();
            break;
        case 3:
            f3();
            break;
        case 4:
            f4();
            break;
        default:
            break;
    }
}

int main(int argc, const char * argv[]) {
    cin >> t;
    while (t--) {
        scanf("%d%d%lld",&n,&m,&q);
        for(int i=1;i<=n;i++)
        {
            for (int j=1; j<=m; j++) {
                scanf("%d",&M[i][j]);
            }
        }
        for (long long int i=1; i<=q; i++) {
            scanf("%d%d%d",&a,&x,&y);
            f();
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                printf("%d",M[i][j]);
                if (j!=m) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
