//
//  main.cpp
//  150818-1004
//
//  Created by 袁子涵 on 15/8/18.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int n,m;

long long int f[110][110];
char a[100000];
string k;

bool visit[110];

bool injective,unknown;
int unkn;


char arr[100000];
char arr1[100000];
void factorial(int n)//求阶乘
{
    memset(arr,0,sizeof(arr));
    arr[0]='1';
    int c=0,temp,temp1;
    for(int i=2;i<=n;i++)
    {
        temp=0;
        for(long int j=0;j<=c;j++)
        {
            temp1=(arr[j]-48)*i+temp;
            arr[j]=temp1%10+48;
            temp=temp1/10;
        }
        while(temp!=0)//
        {
            arr[++c]=temp%10+48;
            temp/=10;
        }
    }
    for (long int i=0; i<=c; i++) {
        arr1[i]=arr[c-i];
    }
}



//高精度加法
//只能是两个正数相加
string add(string str1,string str2)//高精度加法
{
    string str;
    
    long long int len1=str1.length();
    long long int len2=str2.length();
    //前面补0，弄成长度相同
    if(len1<len2)
    {
        for(long int i=1;i<=len2-len1;i++)
            str1="0"+str1;
    }
    else
    {
        for(int i=1;i<=len1-len2;i++)
            str2="0"+str2;
    }
    len1=str1.length();
    int cf=0;
    int temp;
    for(long long int i=len1-1;i>=0;i--)
    {
        temp=str1[i]-'0'+str2[i]-'0'+cf;
        cf=temp/10;
        temp%=10;
        str=char(temp+'0')+str;
    }
    if(cf!=0)  str=char(cf+'0')+str;
    return str;
}

//高精度乘法
//只能是两个正数相乘
string mul(string str1,string str2)
{
    string str;
    long long int len1=str1.length();
    long long int len2=str2.length();
    string tempstr;
    for(long long int i=len2-1;i>=0;i--)
    {
        tempstr="";
        int temp=str2[i]-'0';
        int t=0;
        int cf=0;
        if(temp!=0)
        {
            for(int j=1;j<=len2-1-i;j++)
                tempstr+="0";
            for(long long int j=len1-1;j>=0;j--)
            {
                t=(temp*(str1[j]-'0')+cf)%10;
                cf=(temp*(str1[j]-'0')+cf)/10;
                tempstr=char(t+'0')+tempstr;
            }
            if(cf!=0) tempstr=char(cf+'0')+tempstr;
        }
        str=add(str,tempstr);
    }
    str.erase(0,str.find_first_not_of('0'));
    return str;
}

long long int mod(string a,long long int b)//高精度a除以单精度b
{
    long long int d=0;
    for(int i=0;i<a.size();i++) d=(d*10+(a[i]-'0'))%b;//求出余数
    return d;
}

long long int g(long long int num,int step)
{
    if (step==m) {
        return f[0][num];
    }
    else
    {
        return g(f[m-step][num],step+1);
    }
}

bool nounkn()
{
    for (int i=0; i<n; i++) {
        if (i==g(i,1)-1) {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void cal()
{
    
    factorial(n);
    for (int i=2; i<=unkn; i++) {
        k=mul(k, arr1);
    }
}

int main(int argc, const char * argv[]) {
    while (scanf("%d%d",&n,&m)!=EOF) {
        memset(f, 0, sizeof(f));
        memset(a, 0, sizeof(a));
        memset(arr1, 0, sizeof(arr1));
        memset(arr, 0, sizeof(arr));
        injective=0;
        unknown=0;
        unkn=0;
        for (int i=0; i<m; i++) {
            scanf("%lld",&f[i][0]);
            if (f[i][0]==-1) {
                unkn++;
                unknown=1;
                continue;
            }
            else
            {
                memset(visit, 0, sizeof(visit));
                visit[f[i][0]]=1;
                for (int j=1; j<n; j++) {
                    scanf("%lld",&f[i][j]);
                    if (visit[f[i][j]]==1) {
                        injective=1;
                    }
                    visit[f[i][j]]=1;
                }
            }
        }
        if (injective) {
            cout << "0" << endl;
            continue;
        }
        if (unknown==0) {
            if (nounkn()) {
                cout << "1" << endl;
            }
            else
            {
                cout << "0" << endl;
            }
            continue;
        }
        else
        {
            if (unkn==1) {
                cout << "1" << endl;
            }
            else
            {
                if (n==1) {
                    cout << "1" << endl;
                    continue;
                }
                a[0]='1';
                k=a;
                cal();
                cout << mod(k, 1000000007) << endl;
            }
        }
    }
    return 0;
}
