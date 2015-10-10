#include<stdio.h>
#include<math.h>
typedef struct nn
{
    double dist,x,y;
}Node;
Node node[205];
double map[205][205],max,INF=100000000.0;
int s[205],n;
void set_first()
{
    for(int i=1;i<=n;i++)
    {
        s[i]=0; node[i].dist=INF;
        for(int j=i+1;j<=n;j++)
            map[i][j]=map[j][i]=sqrt(pow(node[i].x-node[j].x,2)+pow(node[i].y-node[j].y,2));
    }
}
void Prim(int m)
{
    double min;
    int tm=m;
    s[m]=1;max=0;
    for(int k=2; k<=n;k++)
    {
        min=INF;
        for(int i=1;i<=n;i++)
            if(s[i]==0)
            {
                if(node[i].dist>map[tm][i])
                    node[i].dist=map[tm][i];
                if(min>node[i].dist)
                {
                    min=node[i].dist; m=i;
                }
                
            }
        s[m]=1;tm=m; if(max<node[m].dist) max=node[m].dist;
        if(m==2) break;//到达
    }
}
int main()
{
    int k=1;
    while(scanf("%d",&n)>0&&n)
    {
        for(int i=1;i<=n;i++)
            scanf("%lf%lf",&node[i].x,&node[i].y);
        set_first();
        Prim(1);
        printf("Scenario #%d\n",k++);
        printf("Frog Distance = %.3f\n\n",max);//要用这样的输出，不能用lf
    }
}
