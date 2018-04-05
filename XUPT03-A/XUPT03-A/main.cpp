//
//  main.cpp
//  XUPT03-A
//
//  Created by 袁子涵 on 16/6/2.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <utility>
using namespace std;
const int MOD=50;
int s1[32],s2[32],tmp,now,End,l,out,S1,S2,N;
bool Stone[50],fin[32];
map<int,bool>vis;
int main(void)
{
    ios::sync_with_stdio(false);
    while(cin >> N >> S1 >> S2)
    {
        vis.clear();
        End=0,l=0,out=0;
        for(int i=0;i<S1;i++)
            cin >> s1[i];
        for(int i=0;i<S2;i++)
            cin >> s2[i];
        for(int i=0;i<N;i++)
            cin >> Stone[i];
        for(int i=0;i<N;i++)
            cin >> fin[i];
        tmp=1<<(N-1);
        for(int i=0;i<N;i++)
        {
            if(fin[i])
                End+=tmp;
            tmp>>=1;
        }
        while(1)
        {
            tmp=1<<(N-1),now=0;
            for(int i=0;i<N;i++)
            {
                if(Stone[(l+i)%MOD])
                    now+=tmp;
                tmp>>=1;
            }
            if(vis[now])
            {
                cout << "poor sisyphus" << endl;
                break;
            }
            if(now==End)
            {
                cout << out << endl;
                break;
            }
            vis[now]=1;
            out++,tmp=0;
            for(int i=0;i<S1;i++)
            {
                if(Stone[(l+s1[i]-1)%MOD])
                    tmp++;
            }
            if(tmp%2)
                Stone[(l+N)%MOD]=1;
            else
                Stone[(l+N)%MOD]=0;
            l++;
            for(int i=0;i<S2;i++)
                Stone[(l+s2[i]-1)%MOD]=!Stone[(l+s2[i]-1)%MOD];
        }
    }
    return 0;
}
