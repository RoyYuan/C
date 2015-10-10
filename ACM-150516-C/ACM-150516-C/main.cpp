#include <stdio.h>
#include <stdlib.h>

int *a,n;

void swap(int *a,int *b)
{
    *a+=*b;
    *b=*a-*b;
    *a-=*b;
}

void quicksort(int left,int right)
{
    int i,j,t;
    if(left>right)
        return;
    i=left;
    j=right;
    t=*(a+left);
    while (i!=j) {
        while (i<j && *(a+j)>=t) {
            j--;
        }
        while (i<j && *(a+i)<=t) {
            i++;
        }
        if(i<j)
            swap(a+i, a+j);
    }
    if(i!=left)
        swap(a+i, a+left);
    quicksort(left, i-1);
    quicksort(i+1, right);
}

int f(int k)
{
    if(k==1)
        return *(a+n-1);
    return *(a+n-k)*k+f(k-1);
}



int main(void)
{
    int t,i,sum;
    scanf("%d",&t);
    while (t) {
        scanf("%d",&n);
        a=(int*)malloc(n*sizeof(int));
        for (i=0; i<n; i++) {
            scanf("%d",a+i);
        }
        quicksort(0, n-1);
        sum=f(n);
        printf("%d\n",sum);
        t--;
    }
}