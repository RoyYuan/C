//
//  main.cpp
//  1014装箱问题
//
//  Created by 袁子涵 on 15/5/21.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define f(x) *(num+x)

int v,n;
int *num;
int min;

void swap(int *a,int *b)
{
    *a+=*b;
    *b=*a-*b;
    *a-=*b;
}

void quicksort(int left,int right)
{
    int i,j,t;
    if (left>right) {
        return ;
    }
    i=left;
    j=right;
    t=*(num+i);
    while (i!=j) {
        while (i<j && f(j)>=t) {
            j--;
        }
        while (i<j && f(i)<=t) {
            i++;
        }
        if (i<j) {
            swap(num+i, num+j);
        }
    }
    if (i!=left) {
        swap(num+i, num+left);
    }
    quicksort(left, i-1);
    quicksort(i+1, right);
}

void dfs(int leave,int q)
{
    if (leave<0) {
        return;
    }
    if (q==n) {
        if (min>leave) {
            min=leave;
        }
        return;
    }
    leave-=f(q);
    dfs(leave, q+1);
    leave+=f(q);
    dfs(leave, q+1);
    return  ;
}

int main(int argc, const char * argv[]) {
    int i;
    scanf("%d%d",&v,&n);
    num=(int*)malloc(sizeof(int)*n);
    for (i=0; i<n; i++) {
        scanf("%d",num+i);
    }
    quicksort(0, n-1);
    min=v;
    dfs(v, 0);
    printf("%d\n",min);
    return 0;
}
