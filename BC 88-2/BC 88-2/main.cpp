//
//  main.cpp
//  BC 88-2
//
//  Created by 袁子涵 on 16/10/1.
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
#include <set>

using namespace std;
const int maxn=100005;
int n,num[maxn];
map<int,int>Book;
bool check(int k)
{
    map<int,int>L,N;
    L.clear();
    for (int i=1; i<=k; i++) {
        L[num[i]]++;
    }
    for (int i=k+1; i<=n; i+=k) {
        N.clear();
        for (int j=0; j<k; j++) {
            N[num[i+j]]++;
        }
        if (N!=L) {
            return 0;
        }
    }
    return 1;
}
inline int gcd(int a,int b)
{
    int c;
    while (a%b) {
        c=b;
        b=a%b;
        a=c;
    }
    return b;
}
int main(int argc, const char * argv[]) {
    int t;
    freopen("//Users//RoyYuan//c//C//BC\ 88-2//BC\ 88-2//out", "r", stdin);
    scanf("%d",&t);
    while (t--) {
        Book.clear();
        scanf("%d",&n);
        for (int i=1; i<=n; i++) {
            scanf("%d",&num[i]);
            Book[num[i]]++;
        }
        if (Book.size()==1) {
            for (int i=1; i<=n; i++) {
                if (n%i) {
                    continue;
                }
                printf("%d",i);
                if (i!=n) {
                    printf(" ");
                }
                else
                {
                    printf("\n");
                }
            }
        }
        else
        {
            map<int,int>::iterator it=Book.begin();
            int G=it->second;
            it++;
            for (; it!=Book.end(); it++) {
                G=gcd(G,it->second);
            }
            for (int i=G; i>=1; i--) {
                if (G%i && n%i) {
                    continue;
                }
                else
                {
                    if (check(n/i)) {
                        printf("%d",n/i);
                        if (i!=1) {
                            printf(" ");
                        }
                    }
                }
            }
            printf("\n");
        }
    }
    return 0;
}
