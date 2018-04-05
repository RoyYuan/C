//
//  main.cpp
//  长大15acm-H
//
//  Created by 袁子涵 on 15/12/8.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std;

struct VIS{
    int flag;
    int step;
}vis[1000001];

int dis[2] = {1, -1};

struct num{
    int n[6];
    int step;
    friend bool operator <(num a, num b)
    {
        return a.step < b.step;
    }
};

int ans[6];
int init[6];
int total(num a){
    int i, sum;
    sum = 0;
    for(i = 0; i < 6; i ++)
        sum = sum * 10 + a.n[i];
    return sum;
}

int bfs(void){
    memset(vis, 0, sizeof(vis));
    queue<num> q;
    queue<num> p;
    num pre, lst;
    int i, t,  sp = 0;
    long sum;
    
    for(i = 0; i < 6; i ++)
        pre.n[i] = init[i];
    sum = total(pre);
    vis[sum].flag = 1;
    vis[sum].step = 0;
    pre.step = 0;
    q.push(pre);
    
    for(i = 0; i < 6; i ++)
        lst.n[i] = ans[i];
    sum = total(lst);
    vis[sum].flag = 2;
    vis[sum].step = 0;
    lst.step = 0;
    p.push(lst);
    
    while(!q.empty() && !p.empty()){
        while(q.front().step == sp){
            pre = q.front();
            q.pop();
            for(i = 0; i < 6; i ++){
                if(i == 0){
                    for(t = 0; t < 2; t ++){
                        lst = pre;
                        lst.n[0] = pre.n[0] + dis[t];
                        if(lst.n[i] < 0)
                            lst.n[i] += 10;
                        else if(lst.n[i] >= 10)
                            lst.n[i] -= 10;
                        sum = total(lst);
                        lst.step = pre.step + 1;
                        if(vis[sum].flag == 1)
                            continue;
                        if(vis[sum].flag == 2)
                            return lst.step + vis[sum].step;
                        vis[sum].flag = 1;
                        vis[sum].step = lst.step;
                        q.push(lst);
                    }
                }
                else if(i == 1){
                    int temp = 0;
                    for(int j = 0; j < 6; j ++){
                        if(pre.n[j] % 2)
                            temp ++;
                        else
                            temp --;
                    }
                    if(temp != 0)
                        continue;
                    for(t = 0; t < 2; t ++){
                        lst = pre;
                        lst.n[1] = pre.n[1] + dis[t];
                        if(lst.n[i] < 0)
                            lst.n[i] += 10;
                        else if(lst.n[i] >= 10)
                            lst.n[i] -= 10;
                        sum = total(lst);
                        lst.step = pre.step + 1;
                        if(vis[sum].flag == 1)
                            continue;
                        if(vis[sum].flag == 2)
                            return lst.step + vis[sum].step;
                        vis[sum].flag = 1;
                        vis[sum].step = lst.step;
                        q.push(lst);
                    }
                }
                else if(i == 2){
                    lst = pre;
                    lst.n[2] = pre.n[2] + 7;
                    if(lst.n[i] < 0)
                        lst.n[i] += 10;
                    else if(lst.n[i] >= 10)
                        lst.n[i] -= 10;
                    sum = total(lst);
                    lst. step = pre.step + 1;
                    if(vis[sum].flag == 1)
                        continue;
                    if(vis[sum].flag == 2)
                        return lst.step + vis[sum].step;
                    vis[sum].flag = 1;
                    vis[sum].step = lst.step;
                    q.push(lst);
                }
                else if(i == 3){
                    lst = pre;
                    int temp = 0;
                    for(int j=0; j<6; j++)
                        temp += lst.n[j];
                    temp = temp % 9 + 1;
                    lst.n[3] = pre.n[3] + temp;
                    if(lst.n[i] < 0)
                        lst.n[i] += 10;
                    else if(lst.n[i] >= 10)
                        lst.n[i] -= 10;
                    sum = total(lst);
                    lst. step = pre.step + 1;
                    if(vis[sum].flag == 1)
                        continue;
                    if(vis[sum].flag == 2)
                        return lst.step + vis[sum].step;
                    vis[sum].flag = 1;
                    vis[sum].step = lst.step;
                    q.push(lst);
                }
                else if(i == 4 && (pre.n[0] + pre.n[2] + pre.n[4] == 9)){
                    for(t = 0; t < 2; t ++){
                        lst = pre;
                        lst.n[4] = pre.n[4] + dis[t];
                        if(lst.n[i] < 0)
                            lst.n[i] += 10;
                        else if(lst.n[i] >= 10)
                            lst.n[i] -= 10;
                        sum = total(lst);
                        lst.step = pre.step + 1;
                        if(vis[sum].flag == 1)
                            continue;
                        if(vis[sum].flag == 2)
                            return lst.step + vis[sum].step;
                        vis[sum].flag = 1;
                        vis[sum].step = lst.step;
                        q.push(lst);
                    }
                }
                else if(i == 5 && pre.n[1] == 0){
                    lst = pre;
                    lst.n[5] = pre.n[5] - 3;
                    if(lst.n[i] < 0)
                        lst.n[i] += 10;
                    else if(lst.n[i] >= 10)
                        lst.n[i] -= 10;
                    sum = total(lst);
                    lst. step = pre.step + 1;
                    if(vis[sum].flag == 1)
                        continue;
                    if(vis[sum].flag == 2)
                        return lst.step + vis[sum].step;
                    vis[sum].flag = 1;
                    vis[sum].step = lst.step;
                    q.push(lst);
                }
            }
        }
        
        
        while(p.front().step == sp){
            pre = p.front();
            p.pop();
            
            for(i = 0; i < 6; i ++){
                if(i == 0){
                    for(t = 0; t < 2; t ++){
                        lst = pre;
                        lst.n[0] = pre.n[0] + dis[t];
                        if(lst.n[i] < 0)
                            lst.n[i] += 10;
                        else if(lst.n[i] >= 10)
                            lst.n[i] -= 10;
                        sum = total(lst);
                        lst.step = pre.step + 1;
                        if(vis[sum].flag == 2)
                            continue;
                        if(vis[sum].flag == 1)
                            return lst.step + vis[sum].step;
                        vis[sum].flag = 2;
                        vis[sum].step = lst.step;
                        p.push(lst);
                    }
                }
                else if(i == 1){
                    for(t = 0; t < 2; t ++){
                        lst = pre;
                        lst.n[1] = pre.n[1] + dis[t];
                        if(lst.n[i] < 0)
                            lst.n[i] += 10;
                        else if(lst.n[i] >= 10)
                            lst.n[i] -= 10;
                        int temp = 0;
                        for(int j = 0; j < 6; j ++)
                            if(lst.n[j] % 2)
                                temp ++;
                            else
                                temp --;
                        if(temp != 0)
                            continue;
                        sum = total(lst);
                        lst.step = pre.step + 1;
                        if(vis[sum].flag == 2)
                            continue;
                        if(vis[sum].flag == 1)
                            return lst.step + vis[sum].step;
                        vis[sum].flag = 2;
                        vis[sum].step = lst.step;
                        p.push(lst);
                    }
                }
                else if(i == 2){
                    lst = pre;
                    lst.n[2] = pre.n[2] - 7;
                    if(lst.n[i] < 0)
                        lst.n[i] += 10;
                    else if(lst.n[i] >= 10)
                        lst.n[i] -= 10;
                    sum = total(lst);
                    lst. step = pre.step + 1;
                    if(vis[sum].flag == 2)
                        continue;
                    if(vis[sum].flag == 1)
                        return lst.step + vis[sum].step;
                    vis[sum].flag = 2;
                    vis[sum].step = lst.step;
                    p.push(lst);
                }
                else if(i == 3){
                    for(t = 0; t < 10; t ++){
                        lst.n[3] = pre.n[3] - t;
                        if(lst.n[i] < 0)
                            lst.n[i] += 10;
                        else if(lst.n[i] >= 10)
                            lst.n[i] -= 10;
                        int temp = 0;
                        for(int j = 0; j < 6; j ++)
                            temp += lst.n[j];
                        if(temp % 9 + 1 != i)
                            continue;
                        sum = total(lst);
                        lst.step = pre.step + 1;
                        if(vis[sum].flag == 2)
                            continue;
                        if(vis[sum].flag == 1)
                            return lst.step + vis[sum].step;
                        vis[sum].flag = 2;
                        vis[sum].step = lst.step;
                        p.push(lst);
                    }
                }
                else if(i == 4){
                    for(t = 0; t < 2; t ++){
                        lst = pre;
                        lst.n[4] = pre.n[4] + dis[t];
                        if(lst.n[i] < 0)
                            lst.n[i] += 10;
                        else if(lst.n[i] >= 10)
                            lst.n[i] -= 10;
                        if(lst.n[0] + lst.n[2] + lst.n[4] != 9)
                            continue;
                        sum = total(lst);
                        lst.step = pre.step + 1;
                        if(vis[sum].flag == 2)
                            continue;
                        if(vis[sum].flag == 1)
                            return lst.step + vis[sum].step;
                        vis[sum].flag = 2;
                        vis[sum].step = lst.step;
                        p.push(lst);
                    }
                }
                else if(i == 5 && pre.n[1] == 0){
                    lst = pre;
                    lst.n[5] = pre.n[5] + 3;
                    if(lst.n[i] < 0)
                        lst.n[i] += 10;
                    else if(lst.n[i] >= 10)
                        lst.n[i] -= 10;
                    sum = total(lst);
                    lst.step = pre.step + 1;
                    if(vis[sum].flag == 2)
                        continue;
                    if(vis[sum].flag == 1)
                        return lst.step + vis[sum].step;
                    vis[sum].flag = 2;
                    vis[sum].step = lst.step;
                    p.push(lst);
                }
            }
        }
        ++sp;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    while(T --){
        bool flag = false;
        for(int i = 0; i < 6; i ++){
            cin >> ans[i];
            init[i] = 0;
            if(ans[i])
                flag = true;
        }
        if(!flag)
            cout << "0" << endl;
        int res = bfs();
        cout << res << endl;
    }
    return 0;
}
