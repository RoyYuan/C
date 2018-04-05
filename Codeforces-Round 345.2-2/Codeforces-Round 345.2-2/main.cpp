//
//  main.cpp
//  Codeforces-Round 345.2-2
//
//  Created by 袁子涵 on 16/3/7.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long int n;
int x;
long long int num[1005];
typedef struct{
    long long int num,sum;
}E;
typedef struct {
    E data[1000005];
    long long int head,tail;
}q;
q Q;
long long int out=0;
int main(int argc, const char * argv[]) {
    cin >> n;
    Q.head=Q.tail=0;
    memset(num, 0, sizeof(num));
    for (long long int i=1; i<=n; i++) {
        scanf("%d",&x);
        num[x]++;
    }
    for (long long int i=1; i<=1000; i++) {
        if (num[i]) {
            Q.data[Q.tail].sum=num[i];
            Q.data[Q.tail++].num=i;
        }
    }
    while (Q.head!=Q.tail) {
        E tmp;
        tmp=Q.data[Q.head++];
        tmp.sum--;
        if (tmp.num<Q.data[Q.head].num) {
            out++;
        }
        if (tmp.sum) {
            Q.data[Q.tail++]=tmp;
        }
    }
    cout << out << endl;
    return 0;
}
