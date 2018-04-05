//
//  main.cpp
//  xupt213test
//
//  Created by 袁子涵 on 17/2/13.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <list>
#include <map>

using namespace::std;
//int mv[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
//bool maze[5][5];
//bool vis[5][5];
//typedef struct node
//{
//    int x,y;
//}node;
//queue<node>Q;
//node way[5][5];
//bool check(node now)
//{
//    if (now.x<0 || now.x>4 || now.y<0 || now.y>4 || vis[now.x][now.y]) {
//        return 0;
//    }
//    if (maze[now.x][now.y]==1) {
//        return 0;
//    }
//    return 1;
//}
//int main(int argc, const char * argv[]) {
//    ios::sync_with_stdio(false);
////    int tmp;
//    for (int i=0; i<5; i++) {
//        for (int j=0; j<5; j++) {
//            cin >> maze[i][j];
//        }
//    }
//    node now;
//    now.x=now.y=4;
//    while (!Q.empty()) {
//        Q.pop();
//    }
//    Q.push(now);
//    vis[now.x][now.y]=1;
//    while (!Q.empty()) {
//        now=Q.front();
//        Q.pop();
//        node nxt;
//        for (int i=0; i<4; i+=1) {
//            nxt.x=now.x+mv[i][0];
//            nxt.y=now.y+mv[i][1];
//            if (check(nxt)) {
//                vis[nxt.x][nxt.y]=1;
//                Q.push(nxt);
//                way[nxt.x][nxt.y]=now;
//            }
//        }
//    }
//    now.x=now.y=0;
//    while (now.x!=4 || now.y!=4) {
//        cout << "(" << now.x << ", " << now.y << ")"<< endl;
//        now=way[now.x][now.y];
//    }
//    cout << "(4, 4)" << endl;
//    return 0;
//}
//int n,m;
//const int maxn=1005;
//char maze[maxn][maxn];
//int vis[maxn][maxn];
//vector<int> total;
//int mv[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
//bool check(int x,int y)
//{
//    if (x<0 || x>=n || y<0 || y>=m || vis[x][y]!=0) {
//        return 0;
//    }
//    if (maze[x][y]=='*') {
//        return 0;
//    }
//    return 1;
//}
//int now=0;
//int dfs(int x,int y)
//{
//    if (!check(x, y)) {
//        return 0;
//    }
//    vis[x][y]=now;
//    int tmp=0;
//    for (int i=0; i<4; i++) {
//        tmp+=dfs(x+mv[i][0], y+mv[i][1]);
//    }
//    return tmp+1;
//}
//int main(void)
//{
//    cin >> n >> m;
//    for (int i=0; i<n; i++) {
//        for (int j=0; j<m; j+=1) {
////            scanf("%c",&)
//            cin >> maze[i][j];
//        }
//    }
//    for (int i=0; i<n; i++) {
//        for (int j=0; j<m; j++) {
//            if (check(i, j)) {
//                now++;
//                total.push_back(dfs(i, j));
//            }
//        }
//    }
//    for (int i=0; i<n; i++) {
//        for (int j=0; j<m; j++) {
//            if (maze[i][j]=='*') {
//                set<int>S;
//                S.clear();
//                for (int a=0; a<4; a++) {
//                    int tmpx=i+mv[a][0],tmpy=j+mv[a][1];
//                    if (tmpx<0 || tmpx>=n || tmpy<0 || tmpy>=m) {
//                        continue;
//                    }
//                    if (vis[tmpx][tmpy]) {
//                        S.insert(vis[tmpx][tmpy]);
//                    }
//                }
//                set<int>::iterator it;
//                int tmp=0;
//                for (it=S.begin(); it!=S.end(); it++) {
//                    tmp+=total[*it-1];
//                }
//                cout << (tmp+1)%10;
//            }
//            else
//            {
//                cout << ".";
//            }
//        }
//        cout << endl;
//    }
//    return 0;
//}
//long long int n,a;
//long long int total,now;
//int main(void)
//{
//    cin >> n;
//    for (int i=0; i<n; i++) {
//        cin >> a;
//        total+=abs(a-now);
//        now=a;
//    }
//    cout << total << endl;
//}
//long long int a,b;
//int n,x;
//long long int quick_pow(long long int num,long long int now)
//{
//    long long int ans=1;
//    while (now) {
//        if (now&1) {
//            ans*=num;
//        }
//        num*=num;
//        now>>=1;
//    }
//    return ans;
//}
//
//int main(void)
//{
//    ios::sync_with_stdio(false);
//    cin >> n >> x;
//    long long int bit=quick_pow(x,n-1);
//    int now;
//    for (int i=0; i<n; i++) {
//        cin >> now;
//        a+=bit*now;
//        bit/=x;
//    }
//    cin >> n >> x;
//    bit=quick_pow(x,n-1);
//    for (int i=0; i<n; i++) {
//        cin >> now;
//        b+=bit*now;
//        bit/=x;
//    }
//    if (a==b) {
//        cout << "=" << endl;
//    }
//    else if(a>b)
//    {
//        cout << ">" << endl;
//    }
//    else
//        cout << "<" << endl;
//    return 0;
//}
//limit sum;
//1~limit
//lowbit();
//int sum,limit;
//int lowbit(int num)
//{
//    return num&(-num);
//}
//typedef struct node
//{
//    int num,bit;
//    bool operator < (const node &r)const
//    {
//        return bit<r.bit;
//    }
//}node;
//const int maxn=1e5+5;
//node num[maxn];
//int main(void)
//{
//    ios::sync_with_stdio(false);
//    cin >> sum >> limit;
//    for (int i=1; i<=limit; i++) {
//        num[i].num=i;
//        num[i].bit=lowbit(i);
//    }
//    sort(num+1, num+limit+1);
//    int now=0;
//    vector<int>out;
//    out.clear();
//    for (int i=limit; i>0; i--) {
//        if (now+num[i].bit<=sum) {
//            now+=num[i].bit;
//            out.push_back(num[i].num);
//        }
//    }
//    if (now==sum) {
//        cout << out.size() << endl;
//        for (int i=0; i<out.size(); i++) {
//            cout << out[i] << " ";
//        }
//        cout << endl;
//    }
//    else
//        cout << -1 << endl;
//    return 0;
//}

int main(int argc, const char * argv[]) {
    int n,poke[105],x=0,ans=0;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> poke[i];
        x+=poke[i];
    }
    x/=n;
    for(int i=1;i<n;i++)
    {
        if(poke[i]==x)
            continue;
        poke[i+1]+=poke[i]-x;
        ans++;
    }
    cout << ans << endl;
    return 0;
}

