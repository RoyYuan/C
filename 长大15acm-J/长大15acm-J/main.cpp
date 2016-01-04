//
//  main.cpp
//  长大15acm-J
//
//  Created by 袁子涵 on 15/12/8.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#define on 1
#define down 2
#define left 3
#define right 4
#define front 5
#define behind 6
using namespace std;
char set[7]={' ','W','Y','O','R','G','B'};
char s[105];
typedef struct cube
{
    char color[7][3][3];
}Cube;
Cube C;
void Cube_Init()
{
    for (int i=1; i<=6; i++)
        for (int j=1; j<=2; j++)
            for (int k=1; k<=2; k++)
                C.color[i][j][k]=set[i];
}
void U()
{
    Cube tmp=C;
    tmp.color[right][1][1]=C.color[behind][1][1];
    tmp.color[right][1][2]=C.color[behind][1][2];
    tmp.color[front][1][1]=C.color[right][1][1];
    tmp.color[front][1][2]=C.color[right][1][2];
    tmp.color[left][1][1]=C.color[front][1][1];
    tmp.color[left][1][2]=C.color[front][1][2];
    tmp.color[behind][1][1]=C.color[left][1][1];
    tmp.color[behind][1][2]=C.color[left][1][2];
    tmp.color[on][1][1]=C.color[on][2][1];
    tmp.color[on][1][2]=C.color[on][1][1];
    tmp.color[on][2][1]=C.color[on][2][2];
    tmp.color[on][2][2]=C.color[on][1][2];
    C=tmp;
}
void U1()
{
    U();
    U();
    U();
}
void U2()
{
    U();
    U();
}
void R()
{
    Cube tmp=C;
    tmp.color[on][2][1]=C.color[front][2][2];
    tmp.color[on][2][2]=C.color[front][1][2];
    tmp.color[front][1][2]=C.color[down][2][1];
    tmp.color[front][2][2]=C.color[down][2][2];
    tmp.color[down][2][1]=C.color[behind][2][1];
    tmp.color[down][2][2]=C.color[behind][1][1];
    tmp.color[behind][1][1]=C.color[on][2][1];
    tmp.color[behind][2][1]=C.color[on][2][2];
    tmp.color[right][1][1]=C.color[right][2][1];
    tmp.color[right][1][2]=C.color[right][1][1];
    tmp.color[right][2][1]=C.color[right][2][2];
    tmp.color[right][2][2]=C.color[right][1][2];
    C=tmp;
}
void R1()
{
    R();
    R();
    R();
}
void R2()
{
    R();
    R();
}
void F()
{
    Cube tmp=C;
    tmp.color[right][1][1]=C.color[on][1][1];
    tmp.color[right][2][1]=C.color[on][2][1];
    tmp.color[on][1][1]=C.color[left][2][2];
    tmp.color[on][2][1]=C.color[left][1][2];
    tmp.color[left][1][2]=C.color[down][1][1];
    tmp.color[left][2][2]=C.color[down][2][1];
    tmp.color[down][1][1]=C.color[right][2][1];
    tmp.color[down][2][1]=C.color[right][1][1];
    tmp.color[front][1][1]=C.color[front][2][1];
    tmp.color[front][1][2]=C.color[front][1][1];
    tmp.color[front][2][1]=C.color[front][2][2];
    tmp.color[front][2][2]=C.color[front][1][2];
    C=tmp;
}
void F1()
{
    F();
    F();
    F();
}
void F2()
{
    F();
    F();
    F();
}
void D()
{
    Cube tmp=C;
    tmp.color[right][2][1]=C.color[front][2][1];
    tmp.color[right][2][2]=C.color[front][2][2];
    tmp.color[front][2][1]=C.color[left][2][1];
    tmp.color[front][2][2]=C.color[left][2][2];
    tmp.color[left][2][1]=C.color[behind][2][1];
    tmp.color[left][2][2]=C.color[behind][2][2];
    tmp.color[behind][2][1]=C.color[right][2][1];
    tmp.color[behind][2][2]=C.color[right][2][2];
    tmp.color[down][1][1]=C.color[down][1][2];
    tmp.color[down][1][2]=C.color[down][2][2];
    tmp.color[down][2][1]=C.color[down][1][1];
    tmp.color[down][2][2]=C.color[down][2][1];
    C=tmp;
}
void D1()
{
    D();
    D();
    D();
}
void D2()
{
    D();
    D();
}
void L()
{
    Cube tmp=C;
    tmp.color[on][1][1]=C.color[behind][1][2];
    tmp.color[on][1][2]=C.color[behind][2][2];
    tmp.color[behind][1][2]=C.color[down][1][2];
    tmp.color[behind][2][2]=C.color[down][1][1];
    tmp.color[down][1][1]=C.color[front][1][1];
    tmp.color[down][1][2]=C.color[front][2][1];
    tmp.color[front][1][1]=C.color[on][1][2];
    tmp.color[front][2][1]=C.color[on][1][1];
    tmp.color[left][1][1]=C.color[left][2][1];
    tmp.color[left][1][2]=C.color[left][1][1];
    tmp.color[left][2][1]=C.color[left][2][2];
    tmp.color[left][2][2]=C.color[left][1][2];
    C=tmp;
}
void L1()
{
    L();
    L();
    L();
}
void L2()
{
    L();
    L();
}
void B()
{
    Cube tmp=C;
    tmp.color[right][1][2]=C.color[down][2][2];
    tmp.color[right][2][2]=C.color[down][1][2];
    tmp.color[down][2][2]=C.color[left][1][2];
    tmp.color[down][1][2]=C.color[left][1][1];
    tmp.color[left][1][1]=C.color[on][2][2];
    tmp.color[left][2][1]=C.color[on][1][2];
    tmp.color[on][1][2]=C.color[right][1][2];
    tmp.color[on][2][2]=C.color[right][2][2];
    tmp.color[behind][1][1]=C.color[behind][2][1];
    tmp.color[behind][1][2]=C.color[behind][1][1];
    tmp.color[behind][2][1]=C.color[behind][2][2];
    tmp.color[behind][2][2]=C.color[behind][1][2];
    C=tmp;
}
void B1()
{
    B();
    B();
    B();
}
void B2()
{
    B();
    B();
}

int main(int argc, const char * argv[]) {
    int T,now;
    cin >> T;
    while (T--) {
        Cube_Init();
        cin >> s;
        now=0;
        while (s[now]!='\0') {
            if (s[now+1]=='2') {
                switch (s[now]) {
                    case 'U':
                        U2();
                        break;
                    case 'R':
                        R2();
                        break;
                    case 'F':
                        F2();
                        break;
                    case 'D':
                        D2();
                        break;
                    case 'L':
                        L2();
                        break;
                    case 'B':
                        B2();
                        break;
                    default:
                        break;
                }
                now+=2;
                continue;
            }
            if (s[now+1]=='\'') {
                switch (s[now]) {
                    case 'U':
                        U1();
                        break;
                    case 'R':
                        R1();
                        break;
                    case 'F':
                        F1();
                        break;
                    case 'D':
                        D1();
                        break;
                    case 'L':
                        L1();
                        break;
                    case 'B':
                        B1();
                        break;
                    default:
                        break;
                }
                now+=2;
                continue;
            }
            else
            {
                switch (s[now]) {
                    case 'U':
                        U();
                        break;
                    case 'R':
                        R();
                        break;
                    case 'F':
                        F();
                        break;
                    case 'D':
                        D();
                        break;
                    case 'L':
                        L();
                        break;
                    case 'B':
                        B();
                        break;
                    default:
                        break;
                }
                now++;
            }
        }
        for (int i=1; i<=2; i++) {
            for (int j=1; j<=2; j++) {
                printf("%c ",C.color[front][i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
