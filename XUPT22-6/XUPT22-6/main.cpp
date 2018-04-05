//
//  main.cpp
//  XUPT22-6
//
//  Created by 袁子涵 on 16/12/2.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

const double PI=3.141592653589793;
typedef struct node
{
    double x,y;
}node;
typedef struct edge
{
    int flag;
    double k,b;
}edge;
edge Edge[3];
node Node[4],O;
int main(int argc, const char * argv[]) {
    while (cin >> Node[1].x >> Node[1].y >> Node[2].x >> Node[2].y >> Node[3].x >> Node[3].y) {
        memset(Edge, 0, sizeof(Edge));
        if (Node[1].x==Node[2].x) {
            Edge[1].flag=1;
            Edge[1].b=Node[1].x;
        }
        else
        {
            Edge[1].k=(Node[1].y-Node[2].y)/(Node[1].x-Node[2].x);
            Edge[1].b=Node[1].y-Node[1].x*Edge[1].k;
        }
        if (Node[2].x==Node[3].x) {
            Edge[2].flag=1;
            Edge[2].b=Node[2].x;
        }
        else
        {
            Edge[2].k=(Node[2].y-Node[3].y)/(Node[2].x-Node[3].x);
            Edge[2].b=Node[2].y-Node[2].x*Edge[2].k;
        }
        if (Edge[1].flag) {
            Edge[1].k=0;
            Edge[1].b=(Node[1].y+Node[2].y)/2;
        }
        else
        {
            if (Edge[1].k==0) {
                Edge[1].flag=1;
                Edge[1].b=(Node[1].x+Node[2].x)/2;
            }
            else
            {
                node mid;
                mid.x=(Node[1].x+Node[2].x)/2;
                mid.y=(Node[1].y+Node[2].y)/2;
                Edge[1].k=(-1/Edge[1].k);
                Edge[1].b=mid.y-Edge[1].k*mid.x;
            }
        }
        if (Edge[2].flag) {
            Edge[2].k=0;
            Edge[2].b=(Node[3].y+Node[2].y)/2;
        }
        else
        {
            if (Edge[2].k==0) {
                Edge[2].flag=1;
                Edge[2].b=(Node[3].x+Node[2].x)/2;
            }
            else
            {
                node mid;
                mid.x=(Node[3].x+Node[2].x)/2;
                mid.y=(Node[3].y+Node[2].y)/2;
                Edge[2].k=(-1/Edge[2].k);
                Edge[2].b=mid.y-Edge[2].k*mid.x;
            }
        }
        if (Edge[1].flag || Edge[2].flag) {
            if (Edge[1].flag) {
                O.x=Edge[1].b;
                O.y=Edge[2].k*O.x+Edge[2].b;
            }
            else
            {
                O.x=Edge[2].b;
                O.y=Edge[1].k*O.x+Edge[1].b;
            }
        }
        else
        {
            O.x=(Edge[2].b-Edge[1].b)/(Edge[1].k-Edge[2].k);
            O.y=Edge[1].k*O.x+Edge[1].b;
        }
        double r=sqrt((O.x-Node[1].x)*(O.x-Node[1].x)+(O.y-Node[1].y)*(O.y-Node[1].y));
        printf("%.2f\n",r*2*PI);
    }
    return 0;
}
