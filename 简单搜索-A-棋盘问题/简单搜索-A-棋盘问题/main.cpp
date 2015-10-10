//
//  main.cpp
//  简单搜索-A-棋盘问题
//
//  Created by 袁子涵 on 15/7/19.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

int n,k;
unsigned int sum;
int book[8][8];
int sign[8];

void Search(int num,int left)
{
    if (left==0) {
        sum++;
        return;
    }
    if (num==n) {
        return;
    }
    Search(num+1,left);
    for (int i=0; i<n; i++) {
        if (book[num][i]==1) {
            if (sign[i]==0) {
                sign[i]=1;
                Search(num+1,left-1);
                sign[i]=0;
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    char x;
    while (1) {
        cin >> n >> k;
        if (n==-1 && k==-1) {
            break;
        }
        sum=0;
        memset(book, 0, sizeof(book));
        memset(sign, 0, sizeof(sign));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cin >> x;
                if (x=='#') {
                    book[i][j]=1;
                }
                else
                    book[i][j]=0;
            }
        }
        Search(0,k);
        cout << sum << endl;
    }
    return 0;
}
