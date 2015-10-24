#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char num[500];

int main()
{
    int l;
    scanf("%s",num);
    l=(int)strlen(num);
    l=num[l-1];
    l-='0';
    if (l%2) {
        printf("ji\n");
    }
    else
        printf("ou\n");
    return 0;
}