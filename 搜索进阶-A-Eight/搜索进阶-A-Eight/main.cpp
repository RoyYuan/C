//
//  main.cpp
//  搜索进阶-A-Eight
//
//  Created by 袁子涵 on 15/8/18.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

bool visit[9][9][9][9][9][9][9][9][9];
char num[3][3];
char opt[500000];

typedef struct dt
{
    int x,y;
    char num[3][3];
    char op;
    struct dt *pre;
}Data;

typedef struct queue
{
    long long int head,tail;
    Data data[500000];
}Queue;

Queue q;
Data *out;

bool success(char x[3][3])
{
    int y=1;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (y==x[i][j]-48) {
                y++;
                continue;
            }
            else
            {
                if (y!=9) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

void bfs()
{
    char temp;
    q.head=0;
    q.tail=0;
    Data t,k;
    memcpy(t.num, num, sizeof(num));
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (num[i][j]=='0') {
                t.x=i;
                t.y=j;
                break;
            }
        }
    }
    t.op=0;
    t.pre=NULL;
    q.data[q.tail++]=t;
    while (q.head!=q.tail) {
        t=q.data[q.head];
        //检测是否达标
        if (success(t.num)) {
            out=&q.data[q.head];
            return;
        }
        //上下左右
        if (t.x>0) {
            k=t;
            temp=k.num[k.x][k.y];
            k.num[k.x][k.y]=k.num[k.x-1][k.y];
            k.num[k.x-1][k.y]=temp;
            k.op='u';
            k.x--;
            k.pre=&q.data[q.head];
            if (!visit[k.num[0][0]-48][k.num[0][1]-48][k.num[0][2]-48][k.num[1][0]-48][k.num[1][1]-48][k.num[1][2]-48][k.num[2][0]-48][k.num[2][1]-48][k.num[2][2]-48]) {
                visit[k.num[0][0]-48][k.num[0][1]-48][k.num[0][2]-48][k.num[1][0]-48][k.num[1][1]-48][k.num[1][2]-48][k.num[2][0]-48][k.num[2][1]-48][k.num[2][2]-48]=1;
                q.data[q.tail++]=k;
            }
        }
        if (t.x<2) {
            k=t;
            temp=k.num[k.x][k.y];
            k.num[k.x][k.y]=k.num[k.x+1][k.y];
            k.num[k.x+1][k.y]=temp;
            k.op='d';
            k.x++;
            k.pre=&q.data[q.head];
            if (!visit[k.num[0][0]-48][k.num[0][1]-48][k.num[0][2]-48][k.num[1][0]-48][k.num[1][1]-48][k.num[1][2]-48][k.num[2][0]-48][k.num[2][1]-48][k.num[2][2]-48]) {
                visit[k.num[0][0]-48][k.num[0][1]-48][k.num[0][2]-48][k.num[1][0]-48][k.num[1][1]-48][k.num[1][2]-48][k.num[2][0]-48][k.num[2][1]-48][k.num[2][2]-48]=1;
                q.data[q.tail++]=k;
            }
        }
        if (t.y>0) {
            k=t;
            temp=k.num[k.x][k.y];
            k.num[k.x][k.y]=k.num[k.x][k.y-1];
            k.num[k.x][k.y-1]=temp;
            k.op='l';
            k.y--;
            k.pre=&q.data[q.head];
            if (!visit[k.num[0][0]-48][k.num[0][1]-48][k.num[0][2]-48][k.num[1][0]-48][k.num[1][1]-48][k.num[1][2]-48][k.num[2][0]-48][k.num[2][1]-48][k.num[2][2]-48]) {
                visit[k.num[0][0]-48][k.num[0][1]-48][k.num[0][2]-48][k.num[1][0]-48][k.num[1][1]-48][k.num[1][2]-48][k.num[2][0]-48][k.num[2][1]-48][k.num[2][2]-48]=1;
                q.data[q.tail++]=k;
            }
        }
        if (t.y<2) {
            k=t;
            temp=k.num[k.x][k.y];
            k.num[k.x][k.y]=k.num[k.x][k.y+1];
            k.num[k.x][k.y+1]=temp;
            k.op='r';
            k.y++;
            k.pre=&q.data[q.head];
            if (!visit[k.num[0][0]-48][k.num[0][1]-48][k.num[0][2]-48][k.num[1][0]-48][k.num[1][1]-48][k.num[1][2]-48][k.num[2][0]-48][k.num[2][1]-48][k.num[2][2]-48]) {
                visit[k.num[0][0]-48][k.num[0][1]-48][k.num[0][2]-48][k.num[1][0]-48][k.num[1][1]-48][k.num[1][2]-48][k.num[2][0]-48][k.num[2][1]-48][k.num[2][2]-48]=1;
                q.data[q.tail++]=k;
            }
        }
        q.head++;
    }
}

int main(int argc, const char * argv[]) {
    while (scanf("%c  %c  %c  %c  %c  %c  %c  %c  %c",&num[0][0],&num[0][1],&num[0][2],&num[1][0],&num[1][1],&num[1][2],&num[2][0],&num[2][1],&num[2][2])!=EOF) {
        memset(visit, 0, sizeof(visit));
        memset(opt, 0, sizeof(opt));
        out=NULL;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (num[i][j]=='x') {
                    num[i][j]='0';
                    break;
                }
            }
        }
        visit[num[0][0]-48][num[0][1]-48][num[0][2]-48][num[1][0]-48][num[1][1]-48][num[1][2]-48][num[2][0]-48][num[2][1]-48][num[2][2]-48]=1;
        bfs();
        if (out==NULL) {
            printf("unsolvable\n");
        }
        else
        {
            long long sum=0;
            while (out->op!=0) {
                opt[sum++]=out->op;
                out=out->pre;
            }
            for (long long int i=sum-1; i>=0; i--) {
                printf("%c",opt[i]);
            }
            printf("\n");
        }
        int c;
        while((c = getchar()) != '\n' && c != EOF);
    }
    return 0;
}
