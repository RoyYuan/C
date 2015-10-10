//
//  main.cpp
//  BC-150718-2
//
//  Created by 袁子涵 on 15/7/18.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int connect[100000][100000];
long int gnum[100000];
long int sum_1=0;
long int sum_2=0;
int main(int argc, const char * argv[]) {
    int T;
    long int m,n,x,y;
    scanf("%d",&T);
    for (int i=0; i<T; i++) {
        sum_1=0;
        sum_2=0;
        memset(connect,0,sizeof(connect));
        memset(gnum, 0, sizeof(gnum));
        scanf("%ld %ld",&n,&m);
        for (long int j=0; j<m; j++) {
            scanf("%ld %ld",&x,&y);
            connect[x-1][y-1]=1;
            connect[y-1][x-1]=1;
        }
        gnum[0]=1;
        sum_1++;
        for (long int i=1; i<n; i++) {
            if (connect[i][0]) {
                gnum[i]=2;
            }
        }
        for (long int i=1; i<n; i++) {
            if (gnum[i]==0) {
            }
        }
    }
    return 0;
}
