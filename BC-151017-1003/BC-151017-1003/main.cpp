//
//  main.cpp
//  BC-151017-1003
//
//  Created by 袁子涵 on 15/10/17.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <map>

using namespace std;
#define maxof(a,b)  ((a)>(b)?(a):(b))

int sum,leave,maxs,nums;
int g[31][11],size[31];
int num[305];
bool s[305][31];
bool book[31];

int main(int argc, const char * argv[]) {
    int T,N,L;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&N,&L);
        sum=0;
        leave=N;
        maxs=0;
        memset(num, 0, sizeof(num));
        memset(s, 0, sizeof(s));
        memset(book, 0, sizeof(book));
        for (int i=0; i<N; i++) {
            scanf("%d",&size[i]);
            for (int j=0; j<size[i]; j++) {
                scanf("%d",&g[i][j]);
                num[g[i][j]]++;
                s[g[i][j]][i]=1;
            }
        }
        while (leave>0) {
            for (int i=0; i<301; i++) {
                if (num[i]>0) {
                    maxs=maxof(maxs,num[i]);
                    nums=i;
                }
            }
            leave-=maxs;
            for (int i=0; i<N; i++) {
                if (s[maxs][i]==1) {
                    book[i]=1;
                }
            }
            memset(num, 0, sizeof(num));
            memset(s, 0, sizeof(s));
            for (int i=0; i<N; i++) {
                if (book[i]==0) {
                    for (int j=0; j<size[i]; j++) {
                        num[g[i][j]]++;
                        s[g[i][j]][i]=1;
                    }
                }
            }
            sum++;
        }
        if (sum<=L) {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
        
    }
    return 0;
}
