//
//  main.cpp
//  Codeforces-Round 345.2-3
//
//  Created by 袁子涵 on 16/3/7.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <algorithm>
#include <map>
#define MAX 200005
#define fix 1000000000
using namespace std;
#define MAXN 9999
#define MAXSIZE 1010
#define DLEN 4
map<long long int ,long long int>M1;
map<long long int ,long long int>M2;
typedef struct node{
    long long int x,y;
}Node;
bool cmp(Node a,Node b)
{
    if (a.x<b.x)
        return 1;
    else if (a.x==b.x)
        return a.y<b.y;
    else
        return 0;
}
typedef struct st
{
    long long int num[MAX];
    long long int top;
}ST;
long long int  C(long long int a)
{
    long long int re=1;
    re*=a;
    re*=a-1;
    re/=2;
    return re;
}

long long int n,last;
Node N[MAX];
long long int out=0;
ST st1,st2;
int main(int argc, const char * argv[]) {
    cin >> n;
    M1.clear();
    M2.clear();
    st1.top=0;
    st2.top=0;
    for (long long int i=1; i<=n; i++) {
        scanf("%lld%lld",&N[i].x,&N[i].y);
        N[i].x+=fix;
        N[i].y+=fix;
        st1.num[st1.top++]=N[i].x;
        st2.num[st2.top++]=N[i].y;
    }
    last=1;
    sort(N+1, N+n+1, cmp);
    long long int x=N[1].x,y=N[1].y;
    for (long long int i=2; i<=n; i++) {
        if (N[i].x==x && N[i].y==y) {
            out-=last;
            last++;
        }
        else
            last=1;
        x=N[i].x;
        y=N[i].y;
    }
    for (long long int i=1; i<=n; i++) {
        if (M1[N[i].x]==0) {
            M1[N[i].x]=1;
        }
        else
            M1[N[i].x]++;
        if (M2[N[i].y]==0) {
            M2[N[i].y]=1;
        }
        else
            M2[N[i].y]++;
    }
    while (st1.top>0) {
        st1.top--;
        if (M1[st1.num[st1.top]]>=2) {
            out+=C(M1[st1.num[st1.top]]);
            M1[st1.num[st1.top]]=0;
        }
    }
    while (st2.top>0) {
        st2.top--;
        if (M2[st2.num[st2.top]]>=2) {
            out+=C(M2[st2.num[st2.top]]);
            M2[st2.num[st2.top]]=0;
        }
    }
    cout << out << endl;
    return 0;
}
