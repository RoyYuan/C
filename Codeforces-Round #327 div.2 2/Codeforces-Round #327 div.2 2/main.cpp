//
//  main.cpp
//  Codeforces-Round #327 div.2 2
//
//  Created by 袁子涵 on 15/10/25.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

using namespace std;

void safe_flush(FILE *fp)
{
    int ch;
    while( (ch = fgetc(fp)) != EOF && ch != '\n' );
}

long long int n,m;
int sum=0;
char name[210000];
char change[200];
int main(int argc, const char * argv[]) {
    char x,y;
    cin >> n >> m;
    cin >> name;
    for (int i=0; i<=200; i++) {
        change[i]=i;
    }
    for (long long int i=1; i<=m; i++) {
        safe_flush(stdin);
        scanf("%c %c",&x,&y);
        if (x==y) {
            continue;
        }
        for (int j=90; j<130; j++) {
            if (change[j]==x) {
                change[j]=y;
            }
            else
                if (change[j]==y) {
                    change[j]=x;
                }
        }
    }
    for (long long int i=0; i<n; i++) {
        name[i]=change[name[i]];
    }
    printf("%s",name);

    return 0;
}
