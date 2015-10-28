#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int m,n;

typedef struct OLNode
{
    int row,col,value;
    struct OLNode *right,*down;
} OLNode,*OLink;

typedef struct List
{
    OLink *rowhead,*colhead;
    int rows,cols,nums;
}*CrossList;

void CrossList_Input(CrossList *CL)
{
    int i,j,temp;
    OLNode *temp1,*temp2;
    (*CL)=(CrossList)malloc(sizeof(struct List));
    (*CL)->rows=m;
    (*CL)->cols=n;
    (*CL)->nums=0;
    (*CL)->rowhead=(OLink*)malloc((m+1)*sizeof(OLink));
    if(!(*CL)->rowhead)
    {
        printf("无法生成行指针数组！\n");
        return;
    }
    for(i=0; i<=m; i++)
        (*CL)->rowhead[i]=NULL;
    (*CL)->colhead=(OLink*)malloc((n+1)*sizeof(OLink));
    if(!(*CL)->colhead)
    {
        printf("无法生成列指针数组！\n");
        return;
    }
    for(i=0; i<=n; i++)
        (*CL)->colhead[i]=NULL;
    printf("请按照正常书写格式输入矩阵数据。\n");
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
        {
            scanf("%d",&temp);
            if(temp!=0)
            {
                temp1=(OLNode*)malloc(sizeof(OLNode));
                temp1->row=i;
                temp1->col=j;
                temp1->value=temp;
                temp1->right=NULL;
                temp1->down=NULL;
                (*CL)->nums++;
                if((*CL)->rowhead[i]!=NULL)
                {
                    temp2=(*CL)->rowhead[i];
                    while(temp2->right!=NULL)
                        temp2=temp2->right;
                    temp1->right=NULL;
                    temp2->right=temp1;
                }
                else
                    (*CL)->rowhead[i]=temp1;
                if((*CL)->colhead[j]!=NULL)
                {
                    temp2=(*CL)->colhead[j];
                    while(temp2->down!=NULL)
                        temp2=temp2->down;
                    temp1->down=NULL;
                    temp2->down=temp1;
                }
                else
                    (*CL)->colhead[j]=temp1;
            }
            
            
            
            
        }
    return;
}

void CrossList_Output(CrossList CL)
{
    int i,j;
    OLNode* temp1;
    for(i=1; i<=m; i++)
    {
        temp1=CL->rowhead[i];
        if(temp1==NULL)
        {
            for(j=0; j<n; j++)
                printf("0\t");
        }
        else
        {
            for(j=1; j<=n; j++)
            {
                if(temp1!=NULL && temp1->col==j)
                {
                    printf("%d\t",temp1->value);
                    temp1=temp1->right;
                }
                else
                {
                    printf("0\t");
                }
            }
        }
        printf("\n");
    }
}

void CrossList_Add(CrossList a,CrossList b,CrossList *c)
{
    int i,j,temp;
    OLNode *temp1,*temp2,*temp3,*temp4;
    (*c)=(CrossList)malloc(sizeof(struct List));
    (*c)->cols=n;
    (*c)->nums=0;
    (*c)->rows=m;
    (*c)->rowhead=(OLink*)malloc((m+1)*sizeof(OLink));
    for(i=0; i<=m; i++)
        (*c)->rowhead[i]=NULL;
    (*c)->colhead=(OLink*)malloc((n+1)*sizeof(OLink));
    for(i=0; i<=n; i++)
        (*c)->colhead[i]=NULL;
    for(i=1; i<=m; i++)
    {
        temp1=a->rowhead[i];
        temp2=b->rowhead[i];
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->col==temp2->col)
            {
                j=temp1->col;
                temp=temp1->value+temp2->value;
                temp1=temp1->right;
                temp2=temp2->right;
                if(temp!=0)
                {
                    temp3=(OLNode*)malloc(sizeof(OLNode));
                    temp3->row=i;
                    temp3->col=j;
                    temp3->value=temp;
                    temp3->right=NULL;
                    temp3->down=NULL;
                    (*c)->nums++;
                    if((*c)->rowhead[i]!=NULL)
                    {
                        temp4=(*c)->rowhead[i];
                        while(temp4->right!=NULL)
                            temp4=temp4->right;
                        temp3->right=NULL;
                        temp4->right=temp3;
                    }
                    else
                        (*c)->rowhead[i]=temp3;
                    if((*c)->colhead[j]!=NULL)
                    {
                        temp4=(*c)->colhead[j];
                        while(temp4->down!=NULL)
                            temp4=temp4->down;
                        temp3->down=NULL;
                        temp4->down=temp3;
                    }
                    else
                        (*c)->colhead[j]=temp3;
                }
                else
                    continue;
            }
            else if(temp1->col<temp2->col)
            {
                j=temp1->col;
                temp=temp1->value;
                temp1=temp1->right;
                temp3=(OLNode*)malloc(sizeof(OLNode));
                temp3->row=i;
                temp3->col=j;
                temp3->value=temp;
                temp3->right=NULL;
                temp3->down=NULL;
                (*c)->nums++;
                if((*c)->rowhead[i]!=NULL)
                {
                    temp4=(*c)->rowhead[i];
                    while(temp4->right!=NULL && temp4->col<j+1)
                        temp4=temp4->right;
                    temp3->right=temp4->right;
                    temp4->right=temp3;
                }
                else
                    (*c)->rowhead[i]=temp3;
                if((*c)->colhead[j]!=NULL)
                {
                    temp4=(*c)->colhead[j];
                    while(temp4->down!=NULL && temp4->row<i+1)
                        temp4=temp4->down;
                    temp3->down=temp4->down;
                    temp4->down=temp3;
                }
                else
                    (*c)->colhead[j]=temp3;
            }
            else
            {
                j=temp2->col;
                temp=temp2->value;
                temp2=temp2->right;
                temp3=(OLNode*)malloc(sizeof(OLNode));
                temp3->row=i;
                temp3->col=j;
                temp3->value=temp;
                temp3->right=NULL;
                temp3->down=NULL;
                (*c)->nums++;
                if((*c)->rowhead[i]!=NULL)
                {
                    temp4=(*c)->rowhead[i];
                    while(temp4->right!=NULL && temp4->col<j+1)
                        temp4=temp4->right;
                    temp3->right=temp4->right;
                    temp4->right=temp3;
                }
                else
                    (*c)->rowhead[i]=temp3;
                if((*c)->colhead[j]!=NULL)
                {
                    temp4=(*c)->colhead[j];
                    while(temp4->down!=NULL && temp4->row<i+1)
                        temp4=temp4->down;
                    temp3->down=temp4->down;
                    temp4->down=temp3;
                }
                else
                    (*c)->colhead[j]=temp3;
            }
        }
        while(temp1!=NULL)
        {
            j=temp1->col;
            temp=temp1->value;
            temp1=temp1->right;
            temp3=(OLNode*)malloc(sizeof(OLNode));
            temp3->row=i;
            temp3->col=j;
            temp3->value=temp;
            temp3->right=NULL;
            temp3->down=NULL;
            (*c)->nums++;
            if((*c)->rowhead[i]!=NULL)
            {
                temp4=(*c)->rowhead[i];
                while(temp4->right!=NULL && temp4->col<j+1)
                    temp4=temp4->right;
                temp3->right=temp4->right;
                temp4->right=temp3;
            }
            else
                (*c)->rowhead[i]=temp3;
            if((*c)->colhead[j]!=NULL)
            {
                temp4=(*c)->colhead[j];
                while(temp4->down!=NULL && temp4->row<i+1)
                    temp4=temp4->down;
                temp3->down=temp4->down;
                temp4->down=temp3;
            }
            else
                (*c)->colhead[j]=temp3;
        }
        while(temp2!=NULL)
        {
            j=temp2->col;
            temp=temp2->value;
            temp2=temp2->right;
            temp3=(OLNode*)malloc(sizeof(OLNode));
            temp3->row=i;
            temp3->col=j;
            temp3->value=temp;
            temp3->right=NULL;
            temp3->down=NULL;
            (*c)->nums++;
            if((*c)->rowhead[i]!=NULL)
            {
                temp4=(*c)->rowhead[i];
                while(temp4->right!=NULL && temp4->col<j+1)
                    temp4=temp4->right;
                temp3->right=temp4->right;
                temp4->right=temp3;
            }
            else
                (*c)->rowhead[i]=temp1;
            if((*c)->colhead[j]!=NULL)
            {
                temp4=(*c)->colhead[j];
                while(temp4->down!=NULL && temp4->row<i+1)
                    temp4=temp4->down;
                temp3->down=temp4->down;
                temp4->down=temp3;
            }
            else
                (*c)->colhead[j]=temp3;
        }
    }
}

void CrossList_Sub(CrossList a,CrossList b,CrossList *c)
{
    int i,j,temp;
    OLNode *temp1,*temp2,*temp3,*temp4;
    (*c)=(CrossList)malloc(sizeof(struct List));
    (*c)->cols=n;
    (*c)->nums=0;
    (*c)->rows=m;
    (*c)->rowhead=(OLink*)malloc((m+1)*sizeof(OLink));
    for(i=0; i<=m; i++)
        (*c)->rowhead[i]=NULL;
    (*c)->colhead=(OLink*)malloc((n+1)*sizeof(OLink));
    for(i=0; i<=n; i++)
        (*c)->colhead[i]=NULL;
    for(i=1; i<=m; i++)
    {
        temp1=a->rowhead[i];
        temp2=b->rowhead[i];
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->col==temp2->col)
            {
                j=temp1->col;
                temp=temp1->value-temp2->value;
                temp1=temp1->right;
                temp2=temp2->right;
                if(temp!=0)
                {
                    temp3=(OLNode*)malloc(sizeof(OLNode));
                    temp3->row=i;
                    temp3->col=j;
                    temp3->value=temp;
                    temp3->right=NULL;
                    temp3->down=NULL;
                    (*c)->nums++;
                    if((*c)->rowhead[i]!=NULL)
                    {
                        temp4=(*c)->rowhead[i];
                        while(temp4->right!=NULL)
                            temp4=temp4->right;
                        temp3->right=NULL;
                        temp4->right=temp3;
                    }
                    else
                        (*c)->rowhead[i]=temp3;
                    if((*c)->colhead[j]!=NULL)
                    {
                        temp4=(*c)->colhead[j];
                        while(temp4->down!=NULL)
                            temp4=temp4->down;
                        temp3->down=NULL;
                        temp4->down=temp3;
                    }
                    else
                        (*c)->colhead[j]=temp3;
                }
                else
                    continue;
            }
            else if(temp1->col<temp2->col)
            {
                j=temp1->col;
                temp=temp1->value;
                temp1=temp1->right;
                temp3=(OLNode*)malloc(sizeof(OLNode));
                temp3->row=i;
                temp3->col=j;
                temp3->value=temp;
                temp3->right=NULL;
                temp3->down=NULL;
                (*c)->nums++;
                if((*c)->rowhead[i]!=NULL)
                {
                    temp4=(*c)->rowhead[i];
                    while(temp4->right!=NULL && temp4->col<j+1)
                        temp4=temp4->right;
                    temp3->right=temp4->right;
                    temp4->right=temp3;
                }
                else
                    (*c)->rowhead[i]=temp3;
                if((*c)->colhead[j]!=NULL)
                {
                    temp4=(*c)->colhead[j];
                    while(temp4->down!=NULL && temp4->row<i+1)
                        temp4=temp4->down;
                    temp3->down=temp4->down;
                    temp4->down=temp3;
                }
                else
                    (*c)->colhead[j]=temp3;
            }
            else
            {
                j=temp2->col;
                temp=-temp2->value;
                temp2=temp2->right;
                temp3=(OLNode*)malloc(sizeof(OLNode));
                temp3->row=i;
                temp3->col=j;
                temp3->value=temp;
                temp3->right=NULL;
                temp3->down=NULL;
                (*c)->nums++;
                if((*c)->rowhead[i]!=NULL)
                {
                    temp4=(*c)->rowhead[i];
                    while(temp4->right!=NULL && temp4->col<j+1)
                        temp4=temp4->right;
                    temp3->right=temp4->right;
                    temp4->right=temp3;
                }
                else
                    (*c)->rowhead[i]=temp3;
                if((*c)->colhead[j]!=NULL)
                {
                    temp4=(*c)->colhead[j];
                    while(temp4->down!=NULL && temp4->row<i+1)
                        temp4=temp4->down;
                    temp3->down=temp4->down;
                    temp4->down=temp3;
                }
                else
                    (*c)->colhead[j]=temp3;
            }
        }
        while(temp1!=NULL)
        {
            j=temp1->col;
            temp=temp1->value;
            temp1=temp1->right;
            temp3=(OLNode*)malloc(sizeof(OLNode));
            temp3->row=i;
            temp3->col=j;
            temp3->value=temp;
            temp3->right=NULL;
            temp3->down=NULL;
            (*c)->nums++;
            if((*c)->rowhead[i]!=NULL)
            {
                temp4=(*c)->rowhead[i];
                while(temp4->right!=NULL && temp4->col<j+1)
                    temp4=temp4->right;
                temp3->right=temp4->right;
                temp4->right=temp3;
            }
            else
                (*c)->rowhead[i]=temp3;
            if((*c)->colhead[j]!=NULL)
            {
                temp4=(*c)->colhead[j];
                while(temp4->down!=NULL && temp4->row<i+1)
                    temp4=temp4->down;
                temp3->down=temp4->down;
                temp4->down=temp3;
            }
            else
                (*c)->colhead[j]=temp3;
        }
        while(temp2!=NULL)
        {
            j=temp2->col;
            temp=-temp2->value;
            temp2=temp2->right;
            temp3=(OLNode*)malloc(sizeof(OLNode));
            temp3->row=i;
            temp3->col=j;
            temp3->value=temp;
            temp3->right=NULL;
            temp3->down=NULL;
            (*c)->nums++;
            if((*c)->rowhead[i]!=NULL)
            {
                temp4=(*c)->rowhead[i];
                while(temp4->right!=NULL && temp4->col<j+1)
                    temp4=temp4->right;
                temp3->right=temp4->right;
                temp4->right=temp3;
            }
            else
                (*c)->rowhead[i]=temp3;
            if((*c)->colhead[j]!=NULL)
            {
                temp4=(*c)->colhead[j];
                while(temp4->down!=NULL && temp4->row<i+1)
                    temp4=temp4->down;
                temp3->down=temp4->down;
                temp4->down=temp3;
            }
            else
                (*c)->colhead[j]=temp3;
        }
    }
}


int main()
{
    CrossList A,B,C,D,E;
    printf("请分别输入矩阵的行数和列数。\n");
    scanf("%d%d",&m,&n);
    CrossList_Input(&A);
    CrossList_Input(&B);
    CrossList_Add(A,B,&C);
    CrossList_Sub(A,B,&D);
    CrossList_Sub(B,A,&E);
    printf("A+B=\n");
    CrossList_Output(C);
    printf("A-B=\n");
    CrossList_Output(D);
    printf("B-A=\n");
    CrossList_Output(E);
    return 0;
}

