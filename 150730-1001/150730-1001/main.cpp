//
//  main.cpp
//  150730-1001
//
//  Created by 袁子涵 on 15/7/30.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

bool beautiful[100001];

bool num[10];
int a[10];
int T;
unsigned long int L,R;

void f()
{
    int flag=0;
    for (int i_1=0; i_1<1; i_1++) {
        memset(num, 0, sizeof(num));
        memset(a, 0, sizeof(a));
        flag=0;
        a[0]=i_1;
        num[i_1]=1;
        if (i_1!=0) {
            flag=1;
        }
        for (int i_2=0; i_2<10; i_2++) {
            if (flag) {
                if (num[i_2]==0) {
                    a[1]=i_2;
                    num[i_2]=1;
                }
                else
                    continue;
            }
            else
            {
                if (i_2!=0) {
                    flag=1;
                }
            }
            for (int i_3=0; i_3<10; i_3++) {
                if (flag) {
                    if (num[i_3]==0) {
                        a[2]=i_3;
                        num[i_3]=1;
                    }
                    else
                        continue;
                }
                else
                {
                    if (i_3!=0) {
                        flag=1;
                    }
                }
                for (int i_4=0; i_4<10; i_4++) {
                    if (flag) {
                        if (num[i_4]==0) {
                            a[3]=i_4;
                            num[i_4]=1;
                        }
                        else
                            continue;
                    }
                    else
                    {
                        if (i_4!=0) {
                            flag=1;
                        }
                    }
                    for (int i_5=0; i_5<10; i_5++) {
                        if (flag) {
                            if (num[i_5]==0) {
                                a[4]=i_5;
                                num[i_5]=1;
                            }
                            else
                                continue;
                        }
                        else
                        {
                            if (i_5!=0) {
                                flag=1;
                                a[4]=i_5;
                                num[i_5]=1;
                            }
                        }
                        for (int i_6=0; i_6<10; i_6++) {
                            if (flag) {
                                if (num[i_6]==0) {
                                    a[6]=i_3;
                                    num[i_6]=1;
                                    beautiful[i_1*100000+i_2*10000+i_3*1000+i_4*100+i_5*10+i_6]=1;
                                }
                                else
                                    continue;
                            }
                            num[i_6]=0;
                        }
                        num[i_5]=0;
                    }
                    num[i_4]=0;
                }
                num[i_3]=0;
            }
            num[i_2]=0;
        }
        num[i_1]=0;
    }
    
}

int main(int argc, const char * argv[]) {
    cin >> T;
    f();
    for (int i=1; i<10; i++) {
        beautiful[i]=1;
    }
    unsigned long long int sum=0;
    while (T--) {
        sum=0;
        cin >> L >> R;
        for (unsigned long int i=L; i<=R; i++) {
            sum+=beautiful[i];
        }
        cout << sum << endl;
    }
    return 0;
}
