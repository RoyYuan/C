//
//  main.cpp
//  1220数字三角形
//
//  Created by 袁子涵 on 15/6/18.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

int N;
int tri[100][100];
int book[100][100];


int main(int argc, const char * argv[]) {
    cin>>N;
    memset(tri, 0, sizeof(tri));
    memset(book, 0, sizeof(book));
    for (int i=0; i<N; i++) {
        for (int j=0; j<=i; j++) {
            cin>>tri[i][j];
        }
    }
    
    return 0;
}
