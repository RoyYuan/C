//
//  main.cpp
//  hihocoder17-3
//
//  Created by 袁子涵 on 15/12/27.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;
int n;
typedef struct {
    string s;
    long long int l;
}S;
S s[205];
int plz[1000005];
bool vis[205][205];
long long int out[10];
int cmp(S a,S b)
{
    return a.l<b.l;
}
int g(int a,int b,long long int num1,long long int num2,int op)
{
    int flag=9;
    if (op>8) {
        return 9;
    }
    if (num1==s[a].l && num2==s[b].l) {
        return op;
    }
    if (num1>=s[a].l) {
        op+=s[b].l-num2;
        return min(9,op);
    }
    if (num2>=s[b].l) {
        op+=s[a].l-num1;
        return min(9,op);
    }
    while (s[a].s[num1]==s[b].s[num2]) {
        num1++;
        num2++;
        if (num1==s[a].l && num2==s[b].l) {
            return op;
        }
        if (num1>=s[a].l) {
            op+=s[b].l-num2;
            return min(op,9);
        }
        if (num2>=s[b].l) {
            op+=s[a].l-num1;
            return min(9,op);
        }
    }
    flag=min(flag,g(a,b,num1,num2+1,op+1));
    if (flag==1) {
        return 1;
    }
    flag=min(flag,g(a,b,num1+1,num2+1,op+1));
    if (flag==1) {
        return 1;
    }
    flag=min(flag,g(a,b,num1+1,num2,op+1));
    return flag;
}
int main(int argc, const char * argv[]) {
    cin >> n;
    memset(plz, 0, sizeof(plz));
    memset(vis, 0, sizeof(vis));
    memset(out, 0, sizeof(out));
    for (int i=0; i<n; i++) {
        cin >> s[i].s;
        s[i].l=s[i].s.size();
    }
    sort(s+0, s+n, cmp);
    for (int i=0; i<n; i++) {
        if (plz[s[i].s.size()])
            continue;
        plz[s[i].l]=i+1;
    }
    for (int i=0; i<n; i++) {
        int now=plz[s[i].l-8];
        for (int j=-8; j<=8; j++) {
            if (now>0 && now<=n) {
                break;
            }
            now=plz[s[i].l+j];
            if (j==8 &&(now<=0 || now>n)) {
                now=-1;
                break;
            }
        }
        if (now!=-1) {
            now--;
            while (s[now].l<s[i].l+9 && now<n) {
                if (vis[i][now] || now==i) {
                    now++;
                    continue;
                }
                else
                    out[g(i,now,0,0,0)]++;
                vis[i][now]=vis[now][i]=1;
                now++;
            }
        }
        
    }
    out[9]=n*(n-1)/2;
    for (int i=1; i<9; i++) {
        out[9]-=out[i];
    }
    for (int i=1; i<10; i++) {
        printf("%lld",out[i]);
        if (i!=9) {
            printf(" ");
        }
    }
    return 0;
}
