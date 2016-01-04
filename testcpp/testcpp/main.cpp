#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;
long long int s[11];
long long int c(long long int a,long long int b)
{
    long long int tmp=1;
    for (long long int i=1; i<=b; i++) {
        tmp*=i;
    }
    for (long long int i=1; i<=a; i++) {
        tmp/=i;
    }
    for (long long int i=b-a; i>=1; i--) {
        tmp/=i;
    }
    return tmp;
}
long long int g(long long int x,long long int k)
{
    long long int tmp;
    if (k%2 || k==0) {
        tmp=1;
    }
    else
        tmp=-1;
    for (long long int i=1; i<=2*x-2*k; i++) {
        tmp*=2;
    }
    tmp*=c(k,2*x-k+1);
    return tmp;
}
long long int f(long long int x)
{
    long long int tmp=0;
    for (long long int k=0; k<=x; k++) {
        tmp+=g(x, k);
    }
    return tmp;
}
int main()
{
    cout << f(6) << endl;
    return 0;
}