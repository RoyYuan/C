//
//  main.cpp
//  160813-2
//
//  Created by 袁子涵 on 16/8/13.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <utility>
#include <queue>
#include <vector>
#define fix(x) (x-'a')
using namespace std;
const int CHAR = 26;
const int MAXN = 250000;
struct SAM_Node
{
    SAM_Node *fa,*next[CHAR];
    int len;
    int id,pos;
    SAM_Node(){}
    SAM_Node(int _len) {
        fa = 0;
        len = _len;
        memset(next,0,sizeof(next));
    }
};
SAM_Node SAM_node[MAXN*2], *SAM_root, *SAM_last;
int SAM_size;
SAM_Node *newSAM_Node(int len)
{
    SAM_node[SAM_size] = SAM_Node(len);
    SAM_node[SAM_size].id = SAM_size;
    return &SAM_node[SAM_size++];
}
SAM_Node *newSAM_Node(SAM_Node *p) {
    SAM_node[SAM_size] = *p;
    SAM_node[SAM_size].id = SAM_size;
    return &SAM_node[SAM_size++];
}
void SAM_init() {
    SAM_size = 0;
    SAM_root = SAM_last = newSAM_Node(0);
    SAM_node[0].pos = 0;
}
void SAM_add(int x,int len) {
    SAM_Node *p = SAM_last, *np = newSAM_Node(p->len+1);
    np->pos = len;
    SAM_last = np;
    for(;p && !p->next[x];p = p->fa)
        p->next[x] = np;
    if(!p)
    {
        np->fa = SAM_root;
        return;
    }
    SAM_Node *q = p->next[x];
    if(q->len == p->len + 1)
    {
        np->fa = q;
        return;
    }
    SAM_Node *nq = newSAM_Node(q);
    nq->len = p->len + 1;
    q->fa = nq;
    np->fa = nq;
    for(;p && p->next[x] == q;p = p->fa)
        p->next[x] = nq;
}
char str1[MAXN],str2[MAXN];
SAM_Node *now;
long long int out,tmp;
int main(int argc, const char * argv[]) {
    while (~scanf("%s%s",str1,str2)) {
        SAM_init();
        out=tmp=0;
        now=SAM_root;
        for (int i=0; str1[i]; i++)
            SAM_add(fix(str1[i]), i+1);
        for (int i=0; str2[i]; i++) {
            if (now->next[fix(str2[i])]) {
                now=now->next[fix(str2[i])];
                tmp++;
            }
            else
            {
                while (now && !now->next[fix(str2[i])])
                    now=now->fa;
                if (now) {
                    tmp=now->len+1;
                    now=now->next[fix(str2[i])];
                }
                else
                {
                    tmp=0;
                    now=SAM_root;
                }
            }
            out=max(out,tmp);
        }
        printf("%lld\n",out);
    }
    return 0;
}