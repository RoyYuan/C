//
//  main.cpp
//  160815-2
//
//  Created by 袁子涵 on 16/8/15.
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
#include <map>
#include <utility>
#include <set>
#include <unordered_map>

using namespace std;
const int maxn=100005;
unordered_map<int,int>book;
int num[1<<26];
char str[maxn];
long long int out;
int total,len,now,now_state;
long long dp[maxn][20];
long long get_state(int l, int r)
{
    int k = log2(r - l + 1);
    return dp[l][k] | dp[r - (1 << k) + 1][k];
}
int main(int argc, const char * argv[]) {
    freopen("jingles.in", "r", stdin);
    freopen("jingles.out", "w", stdout);
    int t;
    scanf("%d",&t);
    while (t--) {
        total=0;
        book.clear();
        scanf("%s",str);
        len=strlen(str);
        for (int i=0; i<len; i++) {
            dp[i][0] = 1 << (str[i] - 'a');
        }
        for(int i = 1; i < 20; i ++){
            for(int j = 0; j + (1 << i) <= len; j ++){
                dp[j][i] = dp[j][i - 1] | dp[j + (1 << (i - 1))][i - 1];
            }
        }
        
        for(int i = 0; i < len; i ++){
            int now = get_state(i, len - 1);
            int pre = now;
            book[now] = max(book[now], len - i);
            int temp = __builtin_popcount(now);
            for(int j = 1; j < temp; j ++){
                int last;
                int l = i;
                int r = len - 1;
                while(l <= r){
                    int mid = (l + r) / 2;
                    int num = __builtin_popcount(get_state(i, mid));
                    if(num > j){
                        r = mid - 1;
                    }
                    else{
                        l = mid + 1;
                        last = mid;
                    }
                }
                book[get_state(i, last)] = max(book[get_state(i, last)], last - i + 1);
            }
        }
        
        out=0;
        unordered_map<int,int>::iterator it=book.begin();
        for (; it!=book.end(); it++)
            out+=it->second*__builtin_popcount(it -> first);
        printf("%lu %lld\n",book.size(),out);
    }
    return 0;
}
