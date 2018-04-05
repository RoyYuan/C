//
//  main.cpp
//  160812-1
//
//  Created by 袁子涵 on 16/8/12.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <set>
#include <utility>
#include <vector>
#include <queue>
#define fix(x) (x-'a')
using namespace::std;
const int MX_SZ=26;
typedef struct TrieNode
{
    int end;
    TrieNode *next[MX_SZ],*fail;
    TrieNode()
    {
        end=0;
        fail=NULL;
        for (int i=0;i<MX_SZ;i++)
            next[i]=NULL;
    }
}TrieNode;
TrieNode *root;
TrieNode* NewNode()
{
    TrieNode *p;
    p=new TrieNode;
    return p;
}
void AddNewStr(char* str)
{
    int len=strlen(str);
    TrieNode *p=root,*q;
    for (int i=0; i<len; i++) {
        int id=fix(str[i]);
        if (p->next[id]==NULL) {
            q=NewNode();
            p->next[id]=q;
            p=q;
        }
        else
            p=p->next[id];
    }
    p->end++;
}
void BuildAC()
{
    TrieNode *now;
    queue<TrieNode*>Q;
    while (!Q.empty())
        Q.pop();
    root->fail=root;
    for (int i=0; i<MX_SZ; i++) {
        if (root->next[i]==NULL)
            root->next[i]=root;
        else
        {
            root->next[i]->fail=root;
            Q.push(root->next[i]);
        }
    }
    while (!Q.empty()) {
        now=Q.front();
        Q.pop();
        for (int i=0; i<MX_SZ; i++) {
            if (now->next[i]==NULL)
                now->next[i]=now->fail->next[i];
            else
            {
                now->next[i]->fail=now->fail->next[i];
                Q.push(now->next[i]);
            }
        }
    }
}
int GetAns(char *str)
{
    int out=0,len=strlen(str),id;
    TrieNode *now=root,*tmp;
    for (int i=0; i<len; i++) {
        id=fix(str[i]);
        now=now->next[id];
        tmp=now;
        while (tmp!=root && tmp!=NULL) {
            out+=tmp->end;
            tmp->end=0;
            tmp=tmp->fail;
        }
    }
    return out;
}
void init()
{
    root=NewNode();
}
int main(int argc, const char * argv[]) {
    int t,n;
    char str[1000005];
    scanf("%d",&t);
    while (t--) {
        init();
        scanf("%d",&n);
        for (int i=1; i<=n; i++) {
            scanf("%s",str);
            AddNewStr(str);
        }
        BuildAC();
        scanf("%s",str);
        printf("%d\n",GetAns(str));
    }
    return 0;
}
