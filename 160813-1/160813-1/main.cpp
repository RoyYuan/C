//
//  main.cpp
//  160813-1
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
using namespace std;
const int CHAR = 26;
const int MAXN = 50010;
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
char str[MAXN];
long long int out;
int main(int argc, const char * argv[]) {
    long long int t;
    scanf("%lld",&t);
    while (t--) {
        scanf("%s",str);
        SAM_init();
        for (int i=0; str[i]; i++)
        {
            if (str[i]>='a' && str[i]<='z')
                str[i]+='A'-'a';
            SAM_add(str[i]-'A',i+1);
        }
        out=0;
        for (int i=1; i<SAM_size; i++)
            out+=SAM_node[i].len-SAM_node[i].fa->len;
        printf("%lld\n",out);
    }
    return 0;
}
