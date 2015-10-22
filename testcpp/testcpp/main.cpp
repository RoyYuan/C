#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[100],t[100];

int strcompare(char *a,char *b)
{
    int i=0;
    char x=*(a+i),y=*(b+i);
    while (x!='\0' && y!='\0') {
        x=*(a+i);
        y=*(b+i);
        if (x==y) {
            i++;
            continue;
        }
        else if (x>y)
            return 1;
        else
            return -1;
    }
    return 0;
}

int main()
{
    gets(s);
    gets(t);
    printf("%d\n",strcompare(s,t));
}