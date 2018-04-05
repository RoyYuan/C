//
//  main.cpp
//  160721-1009
//
//  Created by 袁子涵 on 16/7/21.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int t,n,m,head,tail,now,fz,fm,nextmax,yue;
typedef struct
{
    int plz,num;
}node;
node data[105];
int cmp(node a,node b)
{
    return a.plz<b.plz;
}
int gcd(int a,int b)
{
    if (b==0)
        return a;
    return gcd(b, a%b);
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i=0; i<m; i++)
            cin >> data[i].plz >> data[i].num;
        head=fz=fm=0;
        tail=m;
        nextmax=100;
        now=1;
        data[tail].plz=n+1,data[tail].num=0;
        sort(data+0, data+m, cmp);
        for (int i=0; i<=m; i++) {
            while (now<=min(2,data[i].plz-1)) {
                fz+=nextmax;
                fm+=nextmax;
                now++;
            }
            if (now<=2) {
                fz+=data[i].num;
                fm+=data[i].num;
            }
            else
                fm+=(data[i].plz+1-now)*data[i].num;
            now=data[i].plz+1;
            nextmax=data[i].num;
        }
        yue=gcd(fm,fz);
        fm/=yue;
        fz/=yue;
        cout << fz << '/' << fm << endl;
    }
    return 0;
}