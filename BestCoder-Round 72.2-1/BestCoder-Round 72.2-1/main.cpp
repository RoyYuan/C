//
//  main.cpp
//  BestCoder-Round 72.2-1
//
//  Created by 袁子涵 on 16/2/13.
//  Copyright © 2016年 袁子涵. All rights reserved.
//
//  0ms 1784kb

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>

#define fix 'A'

using namespace std;

int a,b,c,t,total;
bool vis[26],vis1[26],vis2[26],vis3[26],flag,f;
char x;
int num[26],num1[26],num2[26],num3[26],tmp,out,out1,out2,num4[26];

int main(int argc, const char * argv[]) {
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        flag=1;
        total=0;
        memset(vis, 0, sizeof(vis));
        memset(vis1, 0, sizeof(vis1));
        memset(vis2, 0, sizeof(vis2));
        memset(vis3, 0, sizeof(vis3));
        memset(num, 0, sizeof(num));
        memset(num1, 0, sizeof(num1));
        memset(num2, 0, sizeof(num2));
        memset(num3, 0, sizeof(num3));
        for (int i=0; i<a; i++) {
            cin >> x >> tmp;
            vis[x-fix]=vis1[x-fix]=1;
            num1[x-fix]=tmp;
        }
        for (int i=0; i<b; i++) {
            cin >> x >> tmp;
            vis[x-fix]=vis2[x-fix]=1;
            num2[x-fix]=tmp;
        }
        for (int i=0; i<c; i++) {
            cin >> x >> tmp;
            vis3[x-fix]=1;
            num3[x-fix]=tmp;
        }
        for (int i=0; i<26; i++) {
            if (vis3[i]) {
                if (vis[i]==0) {
                    flag=0;
                    break;
                }
                continue;
            }
        }
        if (flag==0) {
            cout << "NO" << endl;
            continue;
        }
        for (int i=0; i<26; i++) {
            if (vis[i]) {
                total++;
            }
        }
        if (total!=c) {
            cout << "NO" << endl;
            continue;
        }
        out2=200;
        for (int i=0; i<26; i++) {
            if (vis2[i]) {
                out2=min(out2,num3[i]/num2[i]);
            }
        }
        f=1;
        while (1) {
            flag=1;
            if (out2<=0) {
                f=0;
                break;
            }
            memset(num4, 0, sizeof(num4));
            for (int i=0; i<26; i++) {
                num4[i]=num3[i]-out2*num2[i];
            }
            for (int i=0; i<26; i++) {
                if (vis1[i]) {
                    if (num4[i]>=num1[i] && num4[i]%num1[i]==0) {
                        num[i]=num4[i]/num1[i];
                    }
                    else
                    {
                        flag=0;
                        break;
                    }
                }
            }
            if (flag==0) {
                out2--;
                continue;
            }
            out=0;
            for (int i=0; i<26; i++) {
                if (out==0) {
                    out=num[i];
                }
                else if (num[i]!=0)
                {
                    if (out==num[i]) {
                        continue;
                    }
                    else
                    {
                        flag=0;
                        break;
                    }
                }
            }
            if (flag==0) {
                out2--;
                continue;
            }
            else
            {
                printf("%d %d\n",out,out2);
                break;
            }
        }
        if (f==0) {
            cout << "NO" << endl;
        }
    }
    return 0;
}
