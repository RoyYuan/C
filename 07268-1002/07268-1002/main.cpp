//
//  main.cpp
//  07268-1002
//
//  Created by 袁子涵 on 15/7/28.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include<iostream>
#include<string.h>
using namespace std;

#define maxof(a,b) ((a)>(b)?(a):(b))

int s[1000010];
unsigned long long int visit[1000010][10];
unsigned long long int L,R;
unsigned int maxs=0;

void f(unsigned long long int a,unsigned long long int b)
{
    for (int i=0; i<s[b]; i++) {
        for (int j=0; j<s[a]; j++) {
            if (visit[b][i]==visit[a][j]) {
                s[a]--;
                break;
            }
        }
        visit[a][s[a]+1]=visit[b][i];
    }
    s[a]+=s[b];
}

int rgcdq(unsigned long long int num)
{
    unsigned long long int i=2,n=num;
    if (s[num]) {
        return s[num];
    }
    while (n>=i) {
        if (n%i==0) {
            s[num]++;
            visit[num][s[num-1]]=i;
            n/=i;
            if (s[n]) {
                f(num,n);
                return s[num];
            }
        }
        while (n%i==0) {
            n/=i;
            if (s[n]) {
                f(num, n);
                return s[num];
            }
        }
        i++;
    }
    return  s[num];
}



int main()
{
    unsigned long long int n0,i=2;
    cin >> L >> R;
    for (unsigned long long int j=L; j<=R; j++) {
//        if (s[j]) {
//            continue;
//        }
//        n0=j;
//        while(n0>=i)
//        {
//            if(n0%i==0)
//            {
//                s[j]++;
//                visit[j][s[j]-1]=i;
//                n0 /= i;
//                if (s[n0]) {
//                    for (int b=0; b<s[j]; b++) {
//                        for (int c=0; c<s[n0]; c++) {
//                            if (b==c) {
//                                s[j]--;
//                            }
//                        }
//                    }
//                    for (int b=0; b<s[n0]; b++) {
//                        for (int c=0; c<s[j]; c++) {
//                            if (b==c) {
//                                s[j]--;
//                            }
//                            else
//                            {
//                                visit[j][s[j]]=b;
//                            }
//                        }
//                    }
//                    s[j]+=s[n0];
//                    break;
//                }
//                while (n0%i==0) {
//                    n0/=i;
//                }
//            }
//            else
//                i++;
//        }
//        if(n0!=1)
//            s[j]++;
//        i=2;
        rgcdq(j);
    }
    for (unsigned long long int j=L; j<=R; j++) {
        maxs=maxof(maxs, s[j]);
    }
    cout << maxs << endl;
    
}