//
//  main.cpp
//  UOJ-Round 10-1
//
//  Created by 袁子涵 on 15/12/4.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#define MAXSIZE 10005
#define INF 1000000
using namespace std;
int n,atop[4],t;
long long int k;
int a[4][MAXSIZE];
int plz[MAXSIZE];
struct op
{
    int a,b;
};
struct op P[INF];
int main(int argc, const char * argv[]) {
    cin >> n;
    k=1;
    atop[2]=atop[3]=0;
    atop[1]=t=n;
    memset(P, 0, sizeof(P));
    memset(a, 0, sizeof(MAXSIZE));
    for (int i=n; i>0; i--)
    {
        scanf("%d",&a[1][i]);
        plz[i]=1;
    }
    while (t!=0) {
        int tmp=plz[t],go=(tmp==1?2:1);
        while (a[tmp][atop[tmp]]!=t) {
            a[go][++atop[go]]=a[tmp][atop[tmp]];
            plz[a[tmp][atop[tmp]--]]=go;
            P[k].a=tmp;
            P[k++].b=go;
        }
        a[3][++atop[3]]=t;
        plz[t]=3;
        atop[tmp]--;
        P[k].a=tmp;
        P[k++].b=3;
        t--;
    }
    cout << k-1 << endl;
    for (long long int i=1; i<k; i++) {
        printf("%d %d\n",P[i].a,P[i].b);
    }
    return 0;
}
