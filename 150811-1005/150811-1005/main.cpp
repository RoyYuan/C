//
//  main.cpp
//  150811-1005
//
//  Created by 袁子涵 on 15/8/11.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int n;
long int t;
char num2[100],num[700000];
unsigned long int lth1,lth2,lth3;
unsigned long long int ss;

bool mod11()
{
    lth1=strlen(num);
    unsigned long long int ji=0,ou=0;
    for (int i=0; i<lth1; i+=2) {
        ji+=num[i]-48;
    }
    for (int i=1; i<lth1; i+=2) {
        ou+=num[i]-48;
    }
    if (((ji-ou)>0?(ji-ou):(ou-ji))%11==0 || ji-ou==0) {
        return true;
    }
    else
        return false;
}

void intos(long long int x,char *a)
{
    char biao[10]={'0','1','2','3','4','5','6','7','8','9'};
    long int i=0;
    while (x) {
        a[i]=biao[x%10];
        i++;
        x/=10;
    }
    char temp;
    for (int j=0; j<=(i-1)/2; j++) {
        temp=a[j];
        a[j]=a[i-1-j];
        a[i-1-j]=temp;
    }
    return;
}

int main(int argc, const char * argv[]) {
    int k=1;
    while (scanf("%d %ld",&n,&t)!=EOF && n!=-1 && t!=-1) {
        if (n==0) {
            printf("Case #%d: Yes\n",k);
            k++;
            continue;
        }
        if (t==0) {
            if (n%11==0) {
                printf("Case #%d: Yes\n",k);
                k++;
                continue;
            }
            else
            {
                printf("Case #%d: No\n",k);
                k++;
                continue;
            }
        }
        memset(num, 0, sizeof(num));
        memset(num2, 0, sizeof(num2));
        intos(n, num);
        ss=0;
        lth1=n;
        while (lth1) {
            ss+=lth1%10;
            lth1/=10;
        }
        intos(ss, num2);
        strcat(num, num2);
        t--;
        while (t--) {
            lth1=strlen(num2);
            for (long long int i=0; i<lth1; i++) {
                ss+=num2[i]-48;
            }
            intos(ss, num2);
            strcat(num, num2);
        }
        if (mod11()) {
            printf("Case #%d: Yes\n",k);
        }
        else
            printf("Case #%d: No\n",k);
        k++;
    }
    return 0;
}
