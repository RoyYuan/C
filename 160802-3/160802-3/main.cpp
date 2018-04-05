//
//  main.cpp
//  160802-3
//
//  Created by 袁子涵 on 16/8/2.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct point
{
    int x,y;
}point;
inline int point_line_plz(point a,point b,point c)
{
    return a.x*b.y+b.x*c.y+c.x*a.y-a.x*c.y-b.x*a.y-c.x*b.y;
}
inline double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
point o,node[200];
int n,total,out,le,on,ri;
double r;
int main(int argc, const char * argv[]) {
    point tmp;
    while (scanf("%d%d%lf",&o.x,&o.y,&r)!=EOF && r>=0) {
        out=0;
        scanf("%d",&n);
        total=0;
        for (int i=1; i<=n; i++) {
            scanf("%d%d",&tmp.x,&tmp.y);
            if (dis(o, tmp)>r)
                continue;
            node[++total]=tmp;
        }
        for (int i=1; i<=total; i++) {
            le=on=ri=0;
            for (int j=1; j<=total; j++) {
                int tt=point_line_plz(o, node[i], node[j]);
                if (tt==0)
                    on++;
                else if (tt>0)
                    le++;
                else
                    ri++;
            }
            on+=max(le,ri);
            out=max(out,on);
        }
        printf("%d\n",out);
    }
    return 0;
}
