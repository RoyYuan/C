//
//  main.cpp
//  POJ-1015 Jury Compromise
//
//  Created by 袁子涵 on 15/8/5.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define maxof(a,b) ((a)>(b)?(a):(b))

using namespace std;

//数据组数
int T=1;

//人数
int n,m;

//存最大辩检和
int dp[25][810];

//存每个方案的最后一个被选者编号
int chosen[25][810];

//候选者数据
int d[205];
int p[205];
int sum[205];
int dif[205];

//输出数据
int maxsum;
int mindif;
int out[25];

bool check(int i,int j,int k)
{
    while (i>0) {
        if(chosen[i][j]==k)
            return false;
        j-=dif[chosen[i][j]];
        i--;
    }
    if (i==0) {
        return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    while (cin >> n >> m && n) {
        
        //初始化
        memset(dp, -1, sizeof(dp));
        memset(chosen, 0, sizeof(chosen));
        memset(d, 0, sizeof(d));
        memset(p, 0, sizeof(p));
        memset(sum, 0, sizeof(sum));
        memset(dif, 0, sizeof(dif));
        memset(out, 0, sizeof(out));
        
        //输入并给候选者数据赋值
        for (int i=1; i<=n; i++) {
            cin >> d[i] >> p[i];
            sum[i]=d[i]+p[i];
            dif[i]=d[i]-p[i];
        }
        //修正值
        int fix=m*20;
        
        //dp
        dp[0][fix]=0;
        //从选择1个人到选择m个人
        for (int i=1; i<=m; i++) {
            //找到成立的选择i-1个人的方案
            for (int j=0; j<=2*fix; j++) {
                if (dp[i-1][j]!=-1) {
                    //找下一个人
                    for (int k=1; k<=n; k++) {
                        //当下一个选择第k号，如果辩检和比原来的大
                        if (dp[i-1][j]+sum[k]>dp[i][j+dif[k]]) {
                            //检查这个人是否被选过
                            if (check(i-1,j,k)) {
                                dp[i][j+dif[k]]=dp[i-1][j]+sum[k];
                                chosen[i][j+dif[k]]=k;
                            }
                        }
                    }
                }
            }
        }
        
        //找到要输出的值
        for (int i=0; i<=fix; i++) {
            if (dp[m][fix-i]!=-1 || dp[m][fix+i]!=-1) {
                maxsum=maxof(dp[m][fix-i], dp[m][fix+i]);
                mindif=dp[m][fix-i]>dp[m][fix+i]?(-i):(i);
                break;
            }
        }
        int x=m,y=mindif+fix;
        while (x!=0) {
            out[x]=chosen[x][y];
            y-=dif[chosen[x][y]];
            x--;
        }
        //排序
        sort(out+1,out+m+1);
        //输出
        cout << "Jury #" << T++ << endl;
        cout << "Best jury has value " << (maxsum+mindif)/2 << " for prosecution and value " << (maxsum-mindif)/2 << " for defence: " << endl;
        for (int i=1; i<=m; i++) {
            cout << " " << out[i];
        }
        cout << endl<<endl;
    }
    return 0;
}
