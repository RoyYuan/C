//
//  main.cpp
//  hihocoder17-1
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
#include <vector>

using namespace std;

int n,m;
struct st
{
    string ss;
    long long int l;
};
st s[10005];
string w,tmp;
int cmp(struct st a,struct st b)
{
    return a.l<b.l;
}
long long int plz[100005];
int main(int argc, const char * argv[]) {
    cin >> n >> m;
    memset(plz, 0, sizeof(plz));
    for (int i=0; i<n; i++) {
        cin >> tmp;
        s[i].l=tmp.size();
        s[i].ss=tmp;
    }
    sort(s+0, s+n, cmp);
    for (int i=0; i<n; i++) {
        if (plz[s[i].l])
            continue;
        plz[s[i].l]=i+1;
    }
    for (int i=0; i<m; i++) {
        int out=0;
        cin >> w;
        long long int now=plz[w.size()+1]-1;
        while (s[now].l==w.size()+1) {
            int flag=0;
            for (int i=0; i<s[now].l; i++) {
                if (s[now].ss[i+flag]==w[i])
                    continue;
                else
                {
                    if (flag==0) {
                        flag=1;
                        if (s[now].ss[i+flag]==w[i]) {
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
            if (flag==1)
                out++;
            now++;
        }
        cout << out << endl;
    }
    return 0;
}
