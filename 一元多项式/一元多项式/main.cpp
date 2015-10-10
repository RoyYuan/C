#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1000000007

typedef struct Linklist
{
    long long int index_num;
    long long int coefficient_num;
    struct Linklist *next;
}*LinkList,LinkNode;

char input[10000];

//快速幂
long long int quickpow(long long int m,long long int n)
{
    long long int b = 1;
    while(n>0)
    {
        if(n&1)
            b=(b*m)%N;
        n=n>>1 ;
        m=(m*m)%N;
    }
    return b;
}

//创建链表存储一元多项式
LinkList Create_LinkList()
{
    LinkList head,temp,temp1;
    bool flag=0,f=0;
    long long int i=0,length1,length2,mm;
    char index[100],coefficient[10];
    head=(LinkList)malloc(sizeof(LinkNode));
    temp=(LinkList)malloc(sizeof(LinkNode));
    temp->index_num=0;
    temp->coefficient_num=0;
    head->next=NULL;
    length1=0;
    length2=0;
    memset(input,0,sizeof(input));
    memset(index,0,sizeof(index));
    memset(coefficient,0,sizeof(coefficient));
    scanf("%s",input);
    /*从字符串中识别*/
    while(input[i]!='\0')
    {
        /*当检测到减号时*/
        if(input[i]=='-')
        {
            if(i!=0)
            {
                /*将系数存入index*/
                int k=strlen(index),a;
                //当系数为1时
                if(k==0)
                {
                    temp->index_num=1;
                }
                else
                {
                    //当系数不为负时
                    if(index[0]!='-')
                    {
                        mm=1;
                        for(a=k-1; a>=0; a--)
                        {
                            temp->index_num+=(index[a]-48)*mm;
                            mm*=10;
                        }
                    }
                    //当系数为负时
                    else
                    {
                        if(k==1)
                        {
                            temp->index_num=-1;
                        }
                        else
                        {
                            mm=-1;
                            for(a=k-1; a>0; a--)
                            {
                                temp->index_num=(index[a]-48)*mm;
                                mm*=10;
                            }
                        }
                    }
                }
                
                /*将指数存好*/
                int t=strlen(coefficient),b;
                //当指数为1时
                if(t==0 && f==1)
                {
                    temp->coefficient_num=1;
                }
                else
                {
                    if(t==0 && f==0)
                        temp->coefficient_num=0;
                    else
                    {
                        mm=1;
                        for(b=t-1; b>=0; b--)
                        {
                            temp->coefficient_num+=(coefficient[b]-48)*mm;
                            mm*=10;
                        }
                    }
                }
                
                /*将数据存入链表中*/
                temp1=head;
                if(temp1->next==NULL)
                {
                    head->next=temp;
                    temp->next=NULL;
                }
                else
                {
                    while(temp1->next!=NULL && ((temp1->next)->coefficient_num)<=(temp->coefficient_num))
                    {
                        temp1=temp1->next;
                    }
                    //指数相同时
                    if(temp1->coefficient_num==temp->coefficient_num)
                    {
                        temp1->index_num+=temp->index_num;
                    }
                    else
                    {
                        temp->next=temp1->next;
                        temp1->next=temp;
                    }
                }
            }
            //分配新的空间给下一个数据并初始化
            temp=(LinkList)malloc(sizeof(LinkNode));
            temp->coefficient_num=0;
            temp->index_num=0;
            //初始化系数指数存储
            length1=0;
            length2=0;
            memset(index,0,sizeof(index));
            memset(coefficient,0,sizeof(coefficient));
            flag=0;
            f=0;
            //将负号存入系数存储
            index[0]='-';
            length1++;
            
            i++;
            continue;
        }
        /*当检测到加号时*/
        if(input[i]=='+')
        {
            /*将系数存入index*/
            int k=strlen(index),a;
            //当系数为1时
            if(k==0)
            {
                temp->index_num=1;
            }
            else
            {
                //当系数不为负时
                if(index[0]!='-')
                {
                    mm=1;
                    for(a=k-1; a>=0; a--)
                    {
                        temp->index_num+=(index[a]-48)*mm;
                        mm*=10;
                    }
                }
                //当系数为负时
                else
                {
                    if(k==1)
                    {
                        temp->index_num=-1;
                    }
                    else
                    {
                        mm=-1;
                        for(a=k-1; a>0; a--)
                        {
                            temp->index_num=(index[a]-48)*mm;
                            mm*=10;
                        }
                    }
                }
            }
            
            /*将指数存好*/
            int t=strlen(coefficient),b;
            //当指数为1时
            if(t==0 && f==1)
            {
                temp->coefficient_num=1;
            }
            else
            {
                if(t==0 && f==0)
                    temp->coefficient_num=0;
                else
                {
                    mm=1;
                    for(b=t-1; b>=0; b--)
                    {
                        temp->coefficient_num+=(coefficient[b]-48)*mm;
                        mm*=10;
                    }
                }
            }
            
            /*将数据存入链表中*/
            temp1=head;
            if(temp1->next==NULL)
            {
                head->next=temp;
                temp->next=NULL;
            }
            else
            {
                while(temp1->next!=NULL && ((temp1->next)->coefficient_num)<=(temp->coefficient_num))
                {
                    temp1=temp1->next;
                }
                //当指数相同时
                if(temp1->coefficient_num==temp->coefficient_num)
                {
                    temp1->index_num+=temp->index_num;
                }
                else
                {
                    temp->next=temp1->next;
                    temp1->next=temp;
                }
            }
            
            //分配新的空间给下一个数据并初始化
            temp=(LinkList)malloc(sizeof(LinkNode));
            temp->coefficient_num=0;
            temp->index_num=0;
            //初始化系数指数存储
            length1=0;
            length2=0;
            memset(index,0,sizeof(index));
            memset(coefficient,0,sizeof(coefficient));
            flag=0;
            f=0;
            
            i++;
            continue;
        }
        /*当检测到未知数时*/
        if((input[i]>=65 && input[i]<=90) || (input[i]>=97 && input[i]<=122))
        {
            //开始读取指数
            flag=1;
            f=1;
            i++;
            continue;
        }
        /*当检测到^符号时*/
        if(input[i]=='^')
        {
            flag=1;
            f=1;
            i++;
            
            continue;
        }
        /*当检测到数时*/
        if(input[i]>='0' && input[i]<='9')
        {
            //当在读取系数时
            if(flag==0)
            {
                index[length1++]=input[i];
            }
            //当在读取指数时
            else
            {
                coefficient[length2++]=input[i];
            }
            i++;
            continue;
        }
    }
    /*将系数存入index*/
    int k=strlen(index),a;
    //当系数为1时
    if(k==0)
    {
        temp->index_num=1;
    }
    else
    {
        //当系数不为负时
        if(index[0]!='-')
        {
            mm=1;
            for(a=k-1; a>=0; a--)
            {
                temp->index_num+=(index[a]-48)*mm;
                mm*=10;
            }
        }
        //当系数为负时
        else
        {
            if(k==1)
            {
                temp->index_num=-1;
            }
            else
            {
                mm=-1;
                for(a=k-1; a>0; a--)
                {
                    temp->index_num=(index[a]-48)*mm;
                    mm*=10;
                }
            }
        }
    }
    
    /*将指数存好*/
    int t=strlen(coefficient),b;
    //当指数为1时
    if(t==0 && f==1)
    {
        temp->coefficient_num=1;
    }
    else
    {
        if(t==0 && f==0)
            temp->coefficient_num=0;
        else
        {
            mm=1;
            for(b=t-1; b>=0; b--)
            {
                temp->coefficient_num+=(coefficient[b]-48)*mm;
                mm*=10;
            }
        }
    }
    
    /*将数据存入链表中*/
    temp1=head;
    if(temp1->next==NULL)
    {
        head->next=temp;
        temp->next=NULL;
    }
    else
    {
        while(temp1->next!=NULL && ((temp1->next)->coefficient_num)<=(temp->coefficient_num))
        {
            temp1=temp1->next;
        }
        if(temp1->coefficient_num==temp->coefficient_num)
        {
            temp1->index_num+=temp->index_num;
        }
        else
        {
            temp->next=temp1->next;
            temp1->next=temp;
        }
    }
    return head;
}

//输出一元多项式
void Print_LinkList(LinkList head)
{
    LinkList temp;
    if(head==NULL || head->next==NULL)
    {
        printf("0\n");
        return;
    }
    temp=head->next;
    printf("%lld",temp->index_num);
    if(temp->coefficient_num!=0)
        printf("*x^%lld",temp->coefficient_num);
    temp=temp->next;
    while(temp!=NULL)
    {
        if(temp->index_num>0)
            printf("+%lld*x^%lld",temp->index_num,temp->coefficient_num);
        else
            printf("%lld*x^%lld",temp->index_num,temp->coefficient_num);
        temp=temp->next;
    }
    printf("\n");
}

//链表的复制
LinkList Copy_LinkList(LinkList a)
{
    LinkList b,temp,temp1,temp2;
    b=(LinkList)malloc(sizeof(LinkNode));
    temp1=b;
    temp=a->next;
    while(temp!=NULL)
    {
        temp2=(LinkList)malloc(sizeof(LinkNode));
        temp1->next=temp2;
        temp2->coefficient_num=temp->coefficient_num;
        temp2->index_num=temp->index_num;
        temp2->next=NULL;
        temp1=temp2;
        temp2=temp1->next;
        temp=temp->next;
    }
    return b;
}

//两个一元多项式的相加
LinkList Add_LinkList(LinkList a,LinkList b)
{
    LinkList temp,temp1=a->next,temp2=b->next;
    LinkList c,temp3;
    c=(LinkList)malloc(sizeof(LinkNode));
    //先将链表b复制到链表c
    c=Copy_LinkList(b);
    //将链表a中数据逐个插入到c中
    while(temp1!=NULL)
    {
        temp=(LinkList)malloc(sizeof(LinkNode));
        temp->coefficient_num=temp1->coefficient_num;
        temp->index_num=temp1->index_num;
        temp->next=NULL;
        temp2=c;
        while(temp2->next!=NULL && ((temp2->next)->coefficient_num)<(temp->coefficient_num))
        {
            temp2=temp2->next;
        }
        if(temp2->next==NULL)
        {
            temp->next=NULL;
            temp2->next=temp;
        }
        else
        {
            if(temp2->next->coefficient_num==temp->coefficient_num)
            {
                temp3=temp2->next;
                temp3->index_num+=temp->index_num;
                //当系数为0时消去此项
                if(temp3->index_num==0)
                {
                    temp2->next=temp3->next;
                    free(temp3);
                }
            }
            else
            {
                temp->next=temp2->next;
                temp2->next=temp;
            }
        }
        temp1=temp1->next;
    }
    return c;
}

//两个一元多项式的相减
LinkList subtract_LinkList(LinkList a,LinkList b)
{
    LinkList temp,temp1=a->next,temp2=b->next;
    LinkList c,temp3;
    c=(LinkList)malloc(sizeof(LinkNode));
    //先将被减链表a复制到链表c
    c=Copy_LinkList(a);
    //将链表b中数据的系数加上负号后逐个插入到c中
    while(temp2!=NULL)
    {
        temp=(LinkList)malloc(sizeof(LinkNode));
        temp->coefficient_num=temp2->coefficient_num;
        temp->index_num=-temp2->index_num;
        temp->next=NULL;
        temp1=c;
        while(temp1->next!=NULL && ((temp1->next)->coefficient_num)<(temp->coefficient_num))
        {
            temp1=temp1->next;
        }
        if(temp1->next==NULL)
        {
            temp->next=NULL;
            temp1->next=temp;
        }
        else
        {
            if(temp1->next->coefficient_num==temp->coefficient_num)
            {
                temp3=temp1->next;
                temp3->index_num+=temp->index_num;
                //当系数为0时消去此项
                if(temp3->index_num==0)
                {
                    temp1->next=temp3->next;
                    free(temp3);
                }
            }
            else
            {
                temp->next=temp1->next;
                temp1->next=temp;
            }
        }
        temp2=temp2->next;
    }
    return c;
}

//两个一元多项式相乘
LinkList Mul_LinkList(LinkList a,LinkList b)
{
    LinkList temp1,temp2,temp3,temp4;
    LinkList c=NULL,d=NULL;
    temp1=a->next;
    while(temp1!=NULL)
    {
        //将b复制到c
        c=Copy_LinkList(b);
        //用temp1与c中各项相乘
        temp2=c;
        while(temp2->next!=NULL)
        {
            //将temp1与temp2->next相乘
            temp2->next->coefficient_num+=temp1->coefficient_num;
            temp2->next->index_num*=temp1->index_num;
            //当系数为0时消去此项
            if(temp2->next->index_num==0)
            {
                temp3=temp2->next;
                temp2->next=temp3->next;
                free(temp3);
            }
            //c中下一项
            temp2=temp2->next;
        }
        //将乘后的结果与之前的相加
        if(d==NULL)
            d=c;
        else
        {
            d=Add_LinkList(c,d);
            //释放链表c
            temp4=c->next;
            while(temp4!=NULL)
            {
                free(c);
                c=temp4;
                temp4=temp4->next;
            }
        }
        //a中下一项
        temp1=temp1->next;
    }
    return d;
}

//计算一元多项式的值
long long int Cal_LinkList(LinkList a,long long int x)
{
    long long int sum=0;
    LinkList temp1;
    temp1=a->next;
    while(temp1!=NULL)
    {
        sum+=(temp1->index_num*quickpow(x,temp1->coefficient_num));
        sum%=N;
        temp1=temp1->next;
    }
    return sum;
}

//一元多项式的求导
LinkList Der_LinkList(LinkList a)
{
    LinkList b,temp1,temp2,temp3;
    temp1=a->next;
    b=(LinkList)malloc(sizeof(LinkNode));
    b->next=NULL;
    temp3=b;
    while(temp1!=NULL)
    {
        temp2=(LinkList)malloc(sizeof(LinkNode));
        //常数项直接跳过
        if(temp1->coefficient_num==0)
            temp1=temp1->next;
        else
        {
            temp3->next=temp2;
            temp2->coefficient_num=temp1->coefficient_num-1;
            temp2->index_num=(temp1->index_num*temp1->coefficient_num);
            temp2->next=NULL;
            temp3=temp2;
            temp2=temp3->next;
            temp1=temp1->next;
        }
    }
    return b;
}

//提示打印
void print_hint()
{
    printf("欢迎使用一元多项式计算器，请仔细阅读以下规则。\n");
    printf("1、由于只有一元，程序中一概用x代表未知数。\n");
    printf("2、程序中的求值计算皆在正负10^10内计算，超出范围不保证精度。\n");
    printf("3、程序只限于指数为正的多项式计算。\n");
    printf("4、已尽量适应多种输入方式，请严格遵守输入格式，否则易出错。\n");
    return ;
}

void menu()
{
    LinkList s1,s2;
    int choose;
    long long int x;
    print_hint();
    printf("下面请先输入您要输入的两个多项式。\n");
    printf("输入格式样例：x+1;2x2+3x^2...\n");
    printf("s1=");
    s1=Create_LinkList();
    printf("s2=");
    s2=Create_LinkList();
    while(1)
    {
        printf("下面请选择您要进行的计算。\n");
        printf("1、相加；\n2、相减；\n3、相乘；\n4、求值；\n5、求导；\n6、输出多项式；\n0、退出。\n");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:
                printf("s1+s2=");
                Print_LinkList(Add_LinkList(s1,s2));
                system("pause");
                break;
            case 2:
                printf("s1-s2=");
                Print_LinkList(subtract_LinkList(s1,s2));
                printf("s2-s1=");
                Print_LinkList(subtract_LinkList(s2,s1));
                system("pause");
                break;
            case 3:
                printf("s1*s2=");
                Print_LinkList(Mul_LinkList(s1,s2));
                system("pause");
                break;
            case 4:
                scanf("%lld",&x);
                printf("s1=%lld\ns2=%lld\n",Cal_LinkList(s1,x),Cal_LinkList(s2,x));
                system("pause");
                break;
            case 5:
                printf("(s1)'=");
                Print_LinkList(Der_LinkList(s1));
                printf("(s2)'=");
                Print_LinkList(Der_LinkList(s2));
                system("pause");
                break;
            case 6:
                printf("s1=");
                Print_LinkList(s1);
                printf("s2=");
                Print_LinkList(s2);
                system("pause");
                break;
            case 0:
                printf("退出中...\n");
                return ;
            default:
                printf("输入有误。\n");
                system("pause");
                break;
        }
        system("cls");
        print_hint();
    }
    return ;
}

int main()
{
    menu();
    return 0;
}
