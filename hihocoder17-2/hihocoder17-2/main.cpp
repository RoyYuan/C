//
//  main.cpp
//  hihocoder17-2
//
//  Created by 袁子涵 on 15/12/27.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

typedef struct {
    string s;
    long long int l,num;
}Ss;
Ss ss[10005];
int n,m;
long long int plz[100005];
string tmp;
int cmp(Ss a,Ss b)
{
    if (a.l<b.l) {
        return 1;
    }
    else if(a.l==b.l)
        return a.num<b.num;
    else
        return 0;
        
}
int main(int argc, const char * argv[]) {
    cin >> n >> m;
    memset(plz, 0, sizeof(plz));
    for (int i=0; i<n; i++) {
        cin >> ss[i].s;
        ss[i].l=ss[i].s.size();
        ss[i].num=i+1;
    }
    sort(ss+0, ss+n, cmp);
    for (int i=0; i<n; i++) {
        if (plz[ss[i].l]) {
            continue;
        }
        else
            plz[ss[i].l]=i+1;
    }
    for (int i=0; i<m; i++) {
        cin >> tmp;
        long long int now=plz[tmp.size()+2]-1;
        int flag=0,out1=0,x[4];
        memset(x, -1, sizeof(x));
        if (now>=0 && now<n) {
            while (ss[now].l==tmp.size()+2) {
                flag=0;
                for (int j=0; j<tmp.size(); j++) {
                    if (ss[now].s[j+flag]==tmp[j]) {
                        continue;
                    }
                    else
                    {
                        if (flag<2) {
                            flag++;
                            if (ss[now].s[j+flag]==tmp[j]) {
                                continue;
                            }
                            else
                            {
                                if (flag<2) {
                                    flag++;
                                    if (ss[now].s[j+flag]==tmp[j]) {
                                        continue;
                                    }
                                    else
                                    {
                                        flag++;
                                        break;
                                    }
                                }
                                else
                                {
                                    flag++;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            flag++;
                            break;
                        }
                    }
                }
                if (flag<=2) {
                    out1++;
                    x[out1]=ss[now].num;
                }
                now++;
            }
        }
        printf("%d %d %d\n",x[1],x[2],x[3]);
        memset(x, -1, sizeof(x));
        now=plz[tmp.size()]-1;
        int out2=0;
        flag=0;
        if (now>=0 && now<n) {
            while (ss[now].l==tmp.size()) {
                flag=0;
                for (int j=0; j<tmp.size(); j++) {
                    if (ss[now].s[j]==tmp[j]) {
                        continue;
                    }
                    else
                    {
                        flag++;
                        if (flag>2) {
                            break;
                        }
                    }
                }
                if (flag<=2) {
                    out2++;
                    x[out2]=ss[now].num;
                }
                now++;
            }
        }
        printf("%d %d %d\n",x[1],x[2],x[3]);
        memset(x, -1, sizeof(x));
        now=plz[tmp.size()-2]-1;
        flag=0;
        int out3=0;
        if (now>=0 && now<n) {
            while (ss[now].l==tmp.size()-2) {
                flag=0;
                for (int j=0; j<ss[now].l; j++) {
                    if (ss[now].s[j]==tmp[j+flag]) {
                        continue;
                    }
                    else
                    {
                        if (flag==0 || flag==1) {
                            flag++;
                            if (ss[now].s[j]==tmp[j+flag]) {
                                continue;
                            }
                            else
                            {
                                if (flag==1) {
                                    flag++;
                                    if (ss[now].s[j]==tmp[j+flag]) {
                                        continue;
                                    }
                                    else
                                    {
                                        flag++;
                                        break;
                                    }
                                }
                                else
                                {
                                    flag++;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            flag++;
                            break;
                        }
                    }
                }
                if (flag<=2) {
                    out3++;
                    x[out3]=ss[now].num;
                }
                now++;
            }
        }
        printf("%d %d %d\n",x[1],x[2],x[3]);
    }
    return 0;
}
