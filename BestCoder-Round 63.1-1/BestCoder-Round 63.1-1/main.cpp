//
//  main.cpp
//  BestCoder-Round 63.1-1
//
//  Created by 袁子涵 on 15/11/21.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <stdio.h>

using namespace std;

int n,k;
long long int b[110];

const  int MAXL = 500;
struct  BigNum
{
    int  num[MAXL];
    int  len;
};
struct BigNum sum;
BigNum dp[110][110];

struct BigNum Add1(BigNum &a, BigNum &b)
{
    struct BigNum c;
    int  i, len;
    len = (a.len > b.len) ? a.len : b.len;
    memset(c.num, 0, sizeof(c.num));
    for(i = 0; i < len; i++)
    {
        c.num[i] += (a.num[i]+b.num[i]);
        if(c.num[i] >= 10)
        {
            c.num[i+1]++;
            c.num[i] -= 10;
        }
    }
    if(c.num[len])
        len++;
    c.len = len;
    return  c;
}

void swap(int *a,int *b)
{
    *a+=*b;
    *b=*a-*b;
    *a-=*b;
}

void change(BigNum *num,long long int x)
{
    long long int temp=x;
    memset(num, 0, sizeof(BigNum));
    while (temp) {
        num->num[num->len++]=temp%10;
        temp/=10;
    }
    for (int i=0; i<num->len/2; i++) {
        swap(num->num[i],num->num[num->len-i-1]);
    }
}

void  print(BigNum &a)
{
    int  i;
    if (a.len==0) {
        printf("0\n");
        return;
    }
    for(i = a.len-1; i >= 0; i--)
        printf("%d", a.num[i]);
    printf("\n");
}

int main(int argc, const char * argv[]) {
    while (cin >> n >> k) {
        struct BigNum temp;
        sum.len=0;
        memset(sum.num, 0, sizeof(sum.num));
        memset(b, 0, sizeof(b));
        memset(dp, 0, sizeof(dp));
        for (int i=0; i<n; i++) {
            scanf("%lld",&b[i]);
            dp[i][1].num[0]=1;
            dp[i][1].len=1;
        }
        if (n==k) {
            bool flag=1;
            for (int i=1; i<n; i++) {
                if (b[i]>b[i-1]) {
                    continue;
                }
                else
                {
                    flag=0;
                    printf("0\n");
                    break;
                }
            }
            if (flag) {
                printf("1\n");
            }
        }
        else
        {
            temp.num[0]=1;
            temp.len=1;
            for (int i=0; i<n; i++) {
                for (int j=0; j<i; j++) {
                    if (b[i]>b[j]) {
                        for (int p=1; p<k; p++) {
                            temp=dp[i][p+1];
                            dp[i][p+1]=Add1(temp, dp[j][p]);
                        }
                    }
                }
            }
            for (int i=0; i<n; i++) {
                temp=sum;
                sum=Add1(temp, dp[i][k]);
            }
            print(sum);
        }
    }
    return 0;
}
