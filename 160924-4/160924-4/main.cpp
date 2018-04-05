//
//  main.cpp
//  160924-4
//
//  Created by 袁子涵 on 16/9/24.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <utility>

using namespace std;
#define player (0)
#define system (1)
const int maxn=205;
int n,m,c,e;
int G[maxn][maxn];//行走消耗
int occ[maxn][maxn];//被哪支队伍占据
int dp[maxn][maxn];//DP
typedef struct character
{
    int HP,AT,MV,AD1,AD2,STX,STY,GR,D;
}Cha;//角色结构体
typedef struct movenode
{
    int x,y,mv;
}MVN;//移动结构体
Cha C[maxn];
//坐标能否移动检查
bool check(int x,int y)
{
    if (x<1 || x>n || y<1 || y>m)
        return 0;
    return 1;
}
//移动数组
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
//计算距离
inline int getG(int x,int y,int x1,int y1)
{
    return abs(x-x1)+abs(y-y1);
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    string str;
    while (cin >> n >> m >> c >> e) {
        //初始化
        memset(occ, -1, sizeof(occ));
        memset(C, 0, sizeof(C));
        //读入行走消耗
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                cin >> G[i][j];
            }
        }
        //读入角色数据
        for (int i=1; i<=c; i++) {
            cin >> C[i].HP >> C[i].AT >> C[i].MV >> C[i].AD1 >> C[i].AD2 >> C[i].STX >> C[i].STY >> C[i].GR;
            C[i].D=0;
            //将占据信息初始化
            occ[C[i].STX][C[i].STY]=C[i].GR;
        }
        int nowGR,nowID;
//        getchar();
        //读入行动数据
        while (e--) {
            getline(cin,str);
            if (str.size()==0) {
                e++;
                continue;
            }
            if (str[0]=='R') {
                //Round
                nowGR=0;
                int i=str.size();
                nowGR=str[i-1]-'0';
            }
            else if (str[0]=='A' && str[1]=='c')
            {
                //Charactor ID
                int i=str.size(),bit=1;
                nowID=0;
                while (1) {
                    i--;
                    if (str[i]<'0' || str[i]>'9') {
                        break;
                    }
                    nowID+=(str[i]-'0')*bit;
                    bit*=10;
                }
            }
            else if (str[0]=='M')
            {
                //Move
                //从str中提出x,y
                int x=0,y=0,bit=1;
                int i=str.size();
                --i;
                while (1) {
                    i--;
                    if (str[i]<'0' || str[i]>'9') {
                        break;
                    }
                    y+=(str[i]-'0')*bit;
                    bit*=10;
                }
                bit=1;
                while (1) {
                    i--;
                    if (str[i]<'0' || str[i]>'9') {
                        break;
                    }
                    x+=(str[i]-'0')*bit;
                    bit*=10;
                }
                //跑一次DP
                memset(dp, -1, sizeof(dp));
                //当前角色
                Cha now=C[nowID];
                dp[now.STX][now.STY]=now.MV;
                MVN tt;
                queue<MVN>Q;
                while (!Q.empty())  Q.pop();
                tt.x=now.STX,tt.y=now.STY,tt.mv=now.MV;
                Q.push(tt);
                while (!Q.empty()) {
                    tt=Q.front();
                    int nowx=tt.x,nowy=tt.y,nowmv=tt.mv;
                    int nextx,nexty,nextmv;
                    Q.pop();
                    for (int i=0; i<4; i++) {
                        nextx=nowx+dir[i][0],nexty=nowy+dir[i][1];
                        if (check(nextx, nexty)) {
                            if (occ[nextx][nexty]!=-1) {
                                continue;
                            }
                            nextmv=nowmv-G[nextx][nexty];
                            if (dp[nextx][nexty]<nextmv) {
                                dp[nextx][nexty]=nextmv;
                                tt.x=nextx,tt.y=nexty,tt.mv=nextmv;
                                Q.push(tt);
                            }
                        }
                    }
                }
                //得到最大体力值
                int final=dp[x][y];
                if (final>=0) {
                    //检查边缘是否有敌人
                    int nx,ny;
                    for (int i=0; i<4; i++) {
                        nx=x+dir[i][0],ny=y+dir[i][1];
                        if (check(nx, ny)) {
                            if (occ[nx][ny]==-1) {
                                continue;
                            }
                            else if (occ[nx][ny]!=nowGR)
                                final=0;
                        }
                    }
                    cout << final << endl;
                    //将原来位置的人移动
                    occ[now.STX][now.STY]=-1;
                    C[nowID].STX=x,C[nowID].STY=y;
                    occ[x][y]=nowGR;
                }
                else
                {
                    cout << "INVALID" << endl;
                    continue;
                }
            }
            else if (str[0]=='A' && str[1]=='t')
            {
                //Attack
                //从str中提出ID
                int atkID=0,bit=1;
                int i=str.length();
                while (1) {
                    i--;
                    if (str[i]<'0' || str[i]>'9') {
                        break;
                    }
                    atkID+=(str[i]-'0')*bit;
                    bit*=10;
                }
                //当前攻击者
                Cha now=C[nowID];
                //被攻击者
                Cha under=C[atkID];
                if (under.D) {
                    cout << "INVALID" << endl;
                    continue;
                }
                //检查距离
                int dis=getG(now.STX, now.STY,under.STX,under.STY);
                if (dis<now.AD1 || dis>now.AD2) {
                    cout << "INVALID" << endl;
                    continue;
                }
                else
                {
                    //检查剩余血量
                    int lefthp=under.HP-now.AT;
                    if (lefthp>0) {
                        cout << lefthp << endl;
                        //更新剩余血量
                        C[atkID].HP=lefthp;
                    }
                    else
                    {
                        cout << "INVALID" << endl;
                        continue;
                    }
                }
            }
            else if (str[0]=='D')
            {
                //Drive out
                //从str中提出ID
                int atkID=0,bit=1;
                int i=str.length();
                while (1) {
                    i--;
                    if (str[i]<'0' || str[i]>'9') {
                        break;
                    }
                    atkID+=(str[i]-'0')*bit;
                    bit*=10;
                }
                //当前攻击者
                Cha now=C[nowID];
                //被攻击者
                Cha under=C[atkID];
                if (under.D) {
                    cout << "INVALID" << endl;
                    continue;
                }
                //检查距离
                int dis=getG(now.STX, now.STY,under.STX,under.STY);
                if (dis<now.AD1 || dis>now.AD2) {
                    cout << "INVALID" << endl;
                    continue;
                }
                else
                {
                    //检查剩余血量
                    int lefthp=under.HP-now.AT;
                    if (lefthp<0) {
                        cout << lefthp << endl;
                        //将人移除
                        C[atkID].D=1;
                        occ[under.STX][under.STY]=-1;
                    }
                    else
                    {
                        cout << "INVALID" << endl;
                        continue;
                    }
                }
            }
        }
        
    }
    return 0;
}
