//
//  main.cpp
//  二叉树的前序、中序、后序
//
//  Created by 袁子涵 on 15/5/18.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>

int n;
int node[17][2];
int pre[17];
int in[17];
int post[17];
int q;

void preorder(int num)//从编号为1的根节点开始找前序
{
    pre[q++]=num;
    if (node[num][0]) {
        preorder(node[num][0]);
    }
    if (node[num][1]) {
        preorder(node[num][1]);
    }
    return;
}

void inorder(int num)//从编号为1的根节点开始找中序
{
    if (node[num][0]) {
        inorder(node[num][0]);
    }
    in[q++]=num;
    if (node[num][1]) {
        inorder(node[num][1]);
    }
    return;
}

void postorder(int num)//从编号为1的根节点开始找后序
{
    if (node[num][0]) {
        postorder(node[num][0]);
    }
    if (node[num][1]) {
        postorder(node[num][1]);
    }
    post[q++]=num;
}

int main(int argc, const char * argv[]) {
    int i,x,y;
    scanf("%d",&n);
    for (i=1; i<=n; i++) {
        scanf("%d %d",&x,&y);
        node[i][0]=x;
        node[i][1]=y;
    }
    q=1;
    preorder(1);
    q=1;
    inorder(1);
    q=1;
    postorder(1);
    for (i=1; i<=n; i++) {
        printf("%d ",pre[i]);
    }
    printf("\n");
    for (i=1; i<=n; i++) {
        printf("%d ",in[i]);
    }
    printf("\n");
    for (i=1; i<=n; i++) {
        printf("%d ",post[i]);
    }
    printf("\n");
    return 0;
}
