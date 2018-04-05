//
//  main.cpp
//  HFT
//
//  Created by 袁子涵 on 15/11/30.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <queue>
#define MAXASC 128
#define INF 0x3f3f3f3f
using namespace std;

class Node
{
public:
    int num,weight,left,right,father;
};
bool operator < (const Node &t1, const Node &t2)
{
    return t1.weight > t2.weight;
}

Node HFTree[MAXASC*4];
char result[MAXASC*4][10];
int total=0;

bool File_Read();
void HFTree_Init();
void Weight(FILE*);
int HFTree_Create();
void Get(int,char*,int);
void Code_Print();

//对文件的读入
bool File_Read()
{
    FILE *fp=NULL;
    char filename[200];
    cout << "PLEASE INPUT THE FILENAME." << endl;
    cin >> filename;
    strcat(filename,".txt");
    fp=fopen(filename,"r");
    if(fp==NULL)
    {
        cout << "OPEN FILE FAILED." << endl;
        return 0;
    }
    Weight(fp);
    fclose(fp);
    return 1;
}

//哈夫曼树的初始化
void HFTree_Init()
{
    for(int i=0; i<128*4; i++)
    {
        HFTree[i].num=i;
        HFTree[i].father=-1;
        HFTree[i].left=-1;
        HFTree[i].right=-1;
        HFTree[i].weight=0;
    }
    return;
}

//对字符权值的统计
void Weight(FILE *fp)
{
    char x;
    while(~fscanf(fp,"%c",&x))
        HFTree[(int)x].weight++;
    return;
}

//哈夫曼树的建立
int HFTree_Create()
{
    priority_queue<Node>q;
    Node tmp1,tmp2;
    int now=128;
    //先将所有出现过的字符Node入队
    for(int i=0;i<128;i++)
        if(HFTree[i].weight)
            q.push(HFTree[i]);
    //进行合并到队列为空为止
    while(!q.empty())
    {
        int num1,num2;
        tmp1=q.top();
        q.pop();
        num1=tmp1.num;
        tmp2=q.top();
        q.pop();
        num2=tmp2.num;
        HFTree[now].weight=tmp1.weight+tmp2.weight;
        HFTree[now].left=num1;
        HFTree[now].right=num2;
        HFTree[num1].father=HFTree[num2].father=now;
        if(!q.empty())
            q.push(HFTree[now]);
        now++;
    }
    return now-1;
}

//编码的获取
void Get(int num,char* code,int next)
{
    if(num<0)return;
    if(num==total)
    {
        if(HFTree[num].left!=-1)
            Get(HFTree[num].left,NULL,0);
        if(HFTree[num].right!=-1)
            Get(HFTree[num].right,NULL,1);
        return;
    }
    char cd[10];
    int l=0;
    memset(cd,0,sizeof(cd));
    if(code!=NULL)
    {
        l=strlen(code);
        strcpy(cd,code);
    }
    if(next)
        cd[l]='1';
    else
        cd[l]='0';
    cd[l+1]='\0';
    strcpy(result[num],cd);
    if(HFTree[num].left!=-1)
        Get(HFTree[num].left,cd,0);
    if(HFTree[num].right!=-1)
        Get(HFTree[num].right,cd,1);
    return;
}

//编码的打印
void Code_Print()
{
    FILE* fp;
    fp=fopen("out.txt","w+");
    for(int i=0;i<128;i++)
    {
        if(HFTree[i].weight)
        {
            if(i!=10)
                fprintf(fp,"%c:%s\n",i,result[i]);
            else
                fprintf(fp,"\\n:%s\n",result[10]);
        }
    }
    fclose(fp);
    printf("SUCCESS\n");
}

int main()
{
    HFTree_Init();
    if(!File_Read())
        return 0;
    total=HFTree_Create();
    Get(total,NULL,0);
    Code_Print();
    return 0;
}

