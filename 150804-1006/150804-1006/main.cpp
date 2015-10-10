//
//  main.cpp
//  150804-1006
//
//  Created by 袁子涵 on 15/8/4.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

typedef struct node
{
    long long int a,b;
    int direct;
}Node;

Node s[300010];
long long int ss[2][300010];
int T;
long long int n,m,a,b;
int flag=0;
long long int leave[300010];

bool success()
{
    long long int t;
    for (unsigned long int i=1; i<=m; i++) {
        t=abs(ss[0][i]-ss[1][i]);
        if (t<=1) {
            continue;
        }
        else
            return 0;
    }
    return 1;
}

bool dfs(unsigned long int step)
{
    long long int g1,g2;
    if (flag==1) {
        return 1;
    }
    if (step==m+1) {
        if (success()) {
            flag=1;
            return 1;
        }
        else
            return 0;
    }
    unsigned long int x,y;
    x=s[step].a;
    y=s[step].b;
    
    leave[x]--;
    leave[y]--;
    
    if (x==y) {
        s[step].direct=1;
        ss[0][x]++;
        ss[1][x]++;
        
        g1=abs(ss[0][x]-ss[1][x]);
        if (g1<=leave[x]+1) {
            if (dfs(step+1)) {
                return 1;
            }
        }
        return 0;
    }
    
    s[step].direct=1;
    ss[0][x]++;
    ss[1][y]++;
    
    g1=abs(ss[0][x]-ss[1][x]);
    g2=abs(ss[0][y]-ss[1][y]);
    if (g1<=leave[x]+1 && g2<=leave[y]+1) {
        if(dfs(step+1))
            return 1;
    }
    s[step].direct=0;
    ss[0][x]--;
    ss[1][y]--;
    
    ss[1][x]++;
    ss[0][y]++;
    
    g1=abs(ss[0][x]-ss[1][x]);
    g2=abs(ss[0][y]-ss[1][y]);
    if (g1<=leave[x]+1&& g2<=leave[y]+1) {
        if(dfs(step+1))
            return 1;
    }
    ss[1][x]--;
    ss[0][y]--;
    
    leave[x]++;
    leave[y]++;
    
    return 0;
}

int main(int argc, const char * argv[]) {
    cin >> T;
    while (T--) {
        cin >> n >> m;
        flag=0;
        memset(ss, 0, sizeof(ss));
        memset(leave, 0, sizeof(leave));
        for (unsigned long int i=1; i<=m; i++) {
            scanf("%lld%lld",&a,&b);
            s[i].a=a;
            s[i].b=b;
            leave[a]++;
            leave[b]++;
        }
        dfs(1);
        if (flag==1) {
            for (unsigned long int i=1; i<=m; i++) {
                printf("%d\n",s[i].direct);
            }
        }
        else
            printf("-1\n");
    }
    return 0;
}
