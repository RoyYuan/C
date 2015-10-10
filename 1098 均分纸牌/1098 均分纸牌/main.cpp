//
//  main.cpp
//  1098 均分纸牌
//
//  Created by 袁子涵 on 15/6/4.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    int i,time=0;
    long long int sum=0;
    int n,avg;
    int poke[100]={0};
    scanf("%d",&n);
    for (i=0; i<n; i++) {
        scanf("%d",&poke[i]);
        sum+=poke[i];
    }
    avg=(int)sum / n;
    for (i=0; i<n-1; i++) {
        if (poke[i]<avg) {
            poke[i+1]-=avg-poke[i];
            poke[i]=avg;
            time++;
        }
        if (poke[i]>avg) {
            poke[i+1]+=poke[i]-avg;
            poke[i]=avg;
            time++;
        }
    }
    printf("%d\n",time);
    return 0;
}
