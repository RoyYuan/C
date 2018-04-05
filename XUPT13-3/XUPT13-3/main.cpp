//
//  main.cpp
//  XUPT13-3
//
//  Created by 袁子涵 on 16/10/28.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <string>

using namespace::std;
char str[200005];
int main(int argc, const char * argv[]){
//    ios::sync_with_stdio(false);
//    char c;
//    bool flag=0;
//    cin >> n >> t;
    int n,t,pos;
    scanf("%d%d", &n, &t);
    scanf("%s",str);
    for (int i=0;i<n;i++)
        if (str[i]=='.'){
            pos=i;
            break;
        }
    int pp=-1;
    for (int i=pos+1;i<n;i++)
        if (str[i]>='5'){
            int j=i;
            while(t && j>pos){
                if (str[j]>'4'){
                    if (str[j]<='9')
                        t--;
                    pp=j;
                    str[j]=0;
                    str[j-1]++;
                }
                j--;
            }
            break;
        }
    if (pp==pos+1 || str[pos]!='.'){
        str[pos-1]++;
        str[pos]=0;
        for (int i=pos-1;i>0;i--)
            if (str[i]>'9'){
                str[i]='0';
                str[i-1]++;
            }
        if (str[0]>'9'){
            printf("1");
            str[0]='0';
        }
        printf("%s\n", str);
    }
    else
        printf("%s\n", str);
    return 0;
}