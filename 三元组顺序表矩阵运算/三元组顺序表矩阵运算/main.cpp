#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 1000

typedef struct
{
    int row,col,value;
}Triple;

typedef struct
{
    Triple data[MAXSIZE+1];
    int rows,cols,nums;
}TSMatrix;

int m,n;

void TSMatrix_Input(TSMatrix* x)
{
    int i,j,temp;
    x->rows=m;
    x->cols=n;
    x->nums=0;
    printf("请按正常书写格式输入矩阵的数据。\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&temp);
            if(temp!=0)
            {
                x->data[x->nums].value=temp;
                x->data[x->nums].row=i;
                x->data[x->nums++].col=j;
            }
        }
    }
    return;
}

void TSMatrix_Add(TSMatrix* a,TSMatrix* b,TSMatrix* c)
{
    int la=0,lb=0,temp;
    c->nums=0;
    c->cols=n;
    c->rows=m;
    while(la<a->nums && lb<b->nums)
    {
        if(a->data[la].row==b->data[lb].row)
        {
            if(a->data[la].col==b->data[lb].col)
            {
                temp=a->data[la].value+b->data[lb].value;
                if(temp!=0)
                {
                    c->data[c->nums].row=a->data[la].row;
                    c->data[c->nums].col=a->data[la].col;
                    c->data[c->nums++].value=temp;
                    la++;
                    lb++;
                    continue;
                }
                else
                {
                    la++;
                    lb++;
                }
            }
            else if(a->data[la].col<b->data[lb].col)
            {
                c->data[c->nums++]=a->data[la++];
                continue;
            }
            else
            {
                c->data[c->nums++]=b->data[lb++];
                continue;
            }
        }
        else if(a->data[la].row<b->data[lb].row)
        {
            c->data[c->nums++]=a->data[la++];
            continue;
        }
        else
        {
            c->data[c->nums++]=b->data[lb++];
            continue;
        }
    }
    while(la<a->nums)
    {
        c->data[c->nums++]=a->data[la++];
    }
    while(lb<b->nums)
    {
        c->data[c->nums++]=b->data[lb++];
    }
}

void TSMatrix_Sub(TSMatrix* a,TSMatrix* b,TSMatrix* c)
{
    int la=0,lb=0,temp;
    c->nums=0;
    c->cols=n;
    c->rows=m;
    while(la<a->nums && lb<b->nums)
    {
        if(a->data[la].row==b->data[lb].row)
        {
            if(a->data[la].col==b->data[lb].col)
            {
                temp=a->data[la].value-b->data[lb].value;
                if(temp!=0)
                {
                    c->data[c->nums].row=a->data[la].row;
                    c->data[c->nums].col=a->data[la].col;
                    c->data[c->nums++].value=temp;
                    la++;
                    lb++;
                    continue;
                }
                else
                {
                    la++;
                    lb++;
                }
            }
            else if(a->data[la].col<b->data[lb].col)
            {
                c->data[c->nums++]=a->data[la++];
                continue;
            }
            else
            {
                c->data[c->nums]=b->data[lb++];
                c->data[c->nums++].value*=-1;
                continue;
            }
        }
        else if(a->data[la].row<b->data[lb].row)
        {
            c->data[c->nums++]=a->data[la++];
            continue;
        }
        else
        {
            c->data[c->nums]=b->data[lb++];
            c->data[c->nums++].value*=-1;
            continue;
        }
    }
    while(la<a->nums)
    {
        c->data[c->nums++]=a->data[la++];
    }
    while(lb<b->nums)
    {
        c->data[c->nums]=b->data[lb++];
        c->data[c->nums++].value*=-1;
    }
}

void TSMatrix_Output(TSMatrix a)
{
    int i,j,now=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(now>a.nums)
            {
                printf("0\t");
                continue;
            }
            if(a.data[now].row==i && a.data[now].col==j)
            {
                printf("%d\t",a.data[now++].value);
            }
            else
            {
                printf("0\t");
            }
        }
        printf("\n");
    }
}

int main()
{
    TSMatrix A,B,C,D,E;
    printf("请分别输入矩阵的行数和列数。\n");
    scanf("%d%d",&m,&n);
    TSMatrix_Input(&A);
    TSMatrix_Input(&B);
    TSMatrix_Add(&A,&B,&C);
    printf("A+B=\n");
    TSMatrix_Output(C);
    TSMatrix_Sub(&A,&B,&D);
    TSMatrix_Sub(&B,&A,&E);
    printf("A-B=\n");
    TSMatrix_Output(D);
    printf("B-A=\n");
    TSMatrix_Output(E);
    return 0;
}
