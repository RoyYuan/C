//
//  main.cpp
//  160811-4
//
//  Created by 袁子涵 on 16/8/11.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define Key_value ch[ch[root][1]][0]
const int MAXN = 300010;
int pre[MAXN],ch[MAXN][2],key[MAXN],size[MAXN];
int root,tot1,now;
int rev[MAXN],s[MAXN],tot2,a[MAXN];
int n,q;
void NewNode(int &r,int father,int k) {
    if(tot2) r = s[tot2--];
    else r = ++tot1;
    pre[r] = father;
    ch[r][0] = ch[r][1] = 0;
    key[r] = k;
    rev[r] =  0;
    size[r] = 1;
}
void Update_Rev(int r) {
    if(!r)return;
    swap(ch[r][0],ch[r][1]);
    rev[r] ^= 1;
}
void Update_Same(int r,int v) {
    if(!r)return;
    key[r] = v;
}
void push_up(int r) {
    int lson = ch[r][0], rson = ch[r][1];
    size[r] = size[lson] + size[rson] + 1;
}
void push_down(int r)
{
    if(rev[r]) {
        Update_Rev(ch[r][0]);
        Update_Rev(ch[r][1]);
        rev[r] = 0;
    }
}
void Build(int &x,int l,int r,int father) {
    if(l > r)return;
    int mid = (l+r)/2;
    NewNode(x,father,a[mid]);
    Build(ch[x][0],l,mid-1,x);
    Build(ch[x][1],mid+1,r,x);
    push_up(x);
}
void Init() {
    now=root = tot1 = tot2 = 0;
    ch[root][0] = ch[root][1] = size[root] = pre[root] = 0;
    rev[root] = key[root] = 0;
    NewNode(root,0,-1);
    NewNode(ch[root][1],root,-1);
    for (int i=0; i<n; i++)
        a[i]=i+1;
    Build(Key_value,0,n-1,ch[root][1]);
    push_up(ch[root][1]);
    push_up(root);
}
void Rotate(int x,int kind) {
    int y = pre[x];
    push_down(y);
    push_down(x);
    ch[y][!kind] = ch[x][kind];
    pre[ch[x][kind]] = y;
    if(pre[y])
        ch[pre[y]][ch[pre[y]][1]==y] = x;
    pre[x] = pre[y];
    ch[x][kind] = y;
    pre[y] = x;
    push_up(y);
}
void Splay(int r,int goal)
{
    push_down(r);
    while(pre[r] != goal)
    {
        if(pre[pre[r]] == goal) {
            push_down(pre[r]);
            push_down(r);
            Rotate(r,ch[pre[r]][0] == r);
        }
        else
        {
            push_down(pre[pre[r]]);
            push_down(pre[r]);
            push_down(r);
            int y = pre[r];
            int kind = ch[pre[y]][0]==y;
            if(ch[y][kind] == r)
            {
                Rotate(r,!kind);
                Rotate(r,kind);
            }
            else
            {
                Rotate(y,kind);
                Rotate(r,kind);
            }
        }
    }
    push_up(r);
    if(goal == 0) root = r;
}
int Get_kth(int r,int k) {
    push_down(r);
    int t = size[ch[r][0]] + 1;
    if(t == k)
        return r;
    if(t > k)
        return Get_kth(ch[r][0],k);
    else
        return Get_kth(ch[r][1],k-t);
}
void Reverse(int pos,int tot)
{
    Splay(Get_kth(root,pos),0);
    Splay(Get_kth(root,pos+tot+1),root);
    Update_Rev(Key_value);
    push_up(ch[root][1]);
    push_up(root);
}
void Cut(int l,int r,int c)
{
    Splay(Get_kth(root,l),0);
    Splay(Get_kth(root,r+2),root);
    int tmp = Key_value;
    Key_value = 0;
    push_up(ch[root][1]);
    push_up(root);
    Splay(Get_kth(root,c+1),0);
    Splay(Get_kth(root,c+2),root);
    Key_value = tmp;
    pre[Key_value] = ch[root][1];
    push_up(ch[root][1]);
    push_up(root);
}
void InOrder(int r) {
    if(!r)return;
    push_down(r);
    InOrder(ch[r][0]);
    if (key[r]>=0)
    {
        printf("%d",key[r]);
        if (now<n-1)
            printf(" ");
        now++;
    }
    InOrder(ch[r][1]);
}
int main(int argc, const char * argv[]) {
    char op[10];
    int a,b,c;
    while (scanf("%d%d",&n,&q)!=EOF && (n>=0 || q>=0)) {
        Init();
        while (q--) {
            scanf("%s",op);
            switch (op[0]) {
                case 'C':
                    scanf("%d%d%d",&a,&b,&c);
                    Cut(a, b, c);
                    break;
                case 'F':
                    scanf("%d%d",&a,&b);
                    Reverse(a, b-a+1);
            }
        }
        InOrder(root);
        puts("");
    }
    return 0;
}
