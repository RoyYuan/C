//
//  main.cpp
//  160804-1
//
//  Created by 袁子涵 on 16/8/4.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include<functional>

using namespace std;

const int size=6000;
int t,k,n,total;
char op[15];
typedef struct block
{
    int length;
    char data[size];
    block *next,*pre;
    block()
    {
        next=pre=NULL;
        length=0;
    }
}block;
block *head;
typedef struct S
{
    int top;
    block* data[size];
    S(){top=0;}
}S;
S s;
typedef struct cursor
{
    int n;
    block *plz;
    cursor()
    {
        plz=head;
        n=0;
    }
    void move(int k)
    {
        n=k;
        plz=head;
        while(n>plz->length)
        {
            n-=plz->length;
            plz=plz->next;
        }
    }
    void pre()
    {
        n--;
        if(n<0)
        {
            plz=plz->pre;
            n=plz->length-1;
        }
    }
    void next()
    {
        n++;
        if(n>plz->length)
        {
            plz=plz->next;
            n=1;
        }
    }
}cursor;
cursor cur;
inline block* new_block()
{
    if (s.top)
        return s.data[s.top--];
    block *tmp=new block();
    return tmp;
}
inline void del_block(block *tmp)
{
    s.data[++s.top]=tmp;
    if (tmp->pre)
        tmp->pre->next=tmp->next;
    if (tmp->next)
        tmp->next->pre=tmp->pre;
    if (tmp==head)
        head=tmp->next;
}
inline void link_block(block *a,block *b)
{
    if (a)  a->next=b;
    if (b)  b->pre=a;
}
inline void spilt_block(block *tmp,int pos)
{
    if (!pos || pos==tmp->length)
        return;
    block *tt=tmp->next;
    tmp->next=new_block();
    block *tmp2=tmp->next;
    tmp2->length=tmp->length-pos;
    for (int i=1; i<=tmp2->length; i++)
        tmp2->data[i]=tmp->data[pos+i];
    tmp->length=pos;
    link_block(tmp2, tt);
    link_block(tmp, tmp2);
}
inline void mix_block(block *a)
{
    if (!a->next)
        return;
    for (int i=1; i<=a->next->length; i++)
        a->data[a->length+i]=a->next->data[i];
    if (cur.plz==a->next) {
        cur.plz=a;
        cur.n+=a->length;
    }
    a->length+=a->next->length;
    del_block(a->next);
}
inline void fresh_block()
{
    int maxsize=min(size,(int)sqrt(total)*2);
    int minsize=(int)sqrt(total)/2;
    block *now=head;
    while (now) {
        while (now->length<minsize || now->length>maxsize) {
            if (now->length<minsize) {
                mix_block(now);
                if (!now->next)
                    break;
            }
            else
            {
                spilt_block(now, (now->length)/2);
                if (cur.plz==now && cur.n>now->length) {
                    cur.n-=cur.plz->length;
                    cur.plz=cur.plz->next;
                }
            }
        }
        now=now->next;
    }
}
inline void _move(int k){cur.move(k);}
inline void _prev(){cur.pre();}
inline void _next(){cur.next();}
inline void _insert(int k)
{
    block *l=new_block(),*r;
    *l=block();
    r=l;
    int maxsize=min(size,(int)sqrt(total));
    for (int i=1; i<=k; i++) {
        char c;
        for (c=getchar();(c<32)||(c>126)||(c=='\n');c=getchar());
        if (r->length>maxsize) {
            block *tmp=r;
            r=new_block();
            *r=block();
            link_block(tmp,r);
        }
        r->data[++r->length]=c;
    }
    if (cur.n) {
        spilt_block(cur.plz, cur.n);
        block *tmp=cur.plz->next;
        link_block(cur.plz, l),link_block(r, tmp);
    }
    else
    {
        link_block(cur.plz->pre, l),link_block(r, cur.plz),cur.plz=l;
        if (head->pre)
            head=l;
    }
    fresh_block();
}
void _delete(int k)
{
    if (!k)
        return;
    if (cur.n) {
        spilt_block(cur.plz, cur.n);
        cur.plz=cur.plz->next;
        cur.n=0;
    }
    while (k>cur.plz->length) {
        del_block(cur.plz);
        k-=cur.plz->length;
        cur.plz=cur.plz->next;
    }
    if (k==cur.plz->length)
        cur.plz->length=0;
    else
    {
        spilt_block(cur.plz, k);
        _delete(k);
    }
    fresh_block();
}
void _get(cursor cur,int n)
{
    int left=cur.plz->length-cur.n;
    if (left>=n)
        for (int i=cur.n+1; i<=cur.n+n; i++)
            putchar(cur.plz->data[i]);
    else
    {
        for (int i=cur.n+1; i<=cur.plz->length; i++)
            putchar(cur.plz->data[i]);
        cur.plz=cur.plz->next;
        cur.n=0;
        _get(cur,n-left);
    }
}
int main(int argc, const char * argv[]) {
    head=new_block();
    cur.plz=head;
    scanf("%d",&t);
    total=0;
    for (int i=1; i<=t; i++) {
        scanf("%s",op);
        switch (op[0]) {
            case 'M':
                scanf("%d",&k);
                _move(k);
                break;
            case 'I':
                scanf("%d",&n);
                total+=n;
                _insert(n);
                break;
            case 'D':
                scanf("%d",&n);
                total-=n;
                _delete(n);
                break;
            case 'G':
                scanf("%d",&n);
                _get(cur,n);
                puts("");
                break;
            case 'P':
                _prev();
                break;
            case 'N':
                _next();
                break;
        }
    }
    return 0;
}
