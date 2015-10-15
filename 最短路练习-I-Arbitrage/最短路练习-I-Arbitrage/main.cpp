//
//  main.cpp
//  最短路练习-I-Arbitrage
//
//  Created by 袁子涵 on 15/10/15.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string,double>STL;

int n,m;
string cur,a,b;
double c;

typedef struct edge
{
    string a,b;
    double c;
}Edge;
Edge eg[10000];

bool bellmanford()
{
    bool flag=0;
    for (int i=0; i<n; i++) {
        flag=0;
        for (int j=0; j<m; j++) {
            if (STL[eg[j].b]<STL[eg[j].a]*eg[j].c) {
                STL[eg[j].b]=STL[eg[j].a]*eg[j].c;
                flag=1;
            }
        }
        if (!flag) {
            break;
        }
    }
    for (int i=0; i<m; i++) {
        if (STL[eg[i].b]<STL[eg[i].a]*eg[i].c) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    int t=0;
    while (scanf("%d",&n)!=EOF && n!=0) {
        memset(eg, 0, sizeof(eg));
        t++;
        cin >> cur;
        STL[cur]=1;
        for (int i=1; i<n; i++) {
            cin >> cur;
            STL[cur]=0;
        }
        scanf("%d",&m);
        for (int i=0; i<m; i++) {
            cin >> a >> c >> b;
            eg[i].a=a;
            eg[i].b=b;
            eg[i].c=c;
        }
        if (bellmanford())
            printf("Case %d: Yes\n",t);
        else
            printf("Case %d: No\n",t);
        STL.clear();
        
        getchar();
    }
    return 0;
}
