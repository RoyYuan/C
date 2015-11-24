#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    char str[100];
    while(cin >> str)
    {
        int l=strlen(str);
        for (int i=0; i<l; i++) {
            if (str[i]=='z') {
                str[i]=='a';
            }
            else
                str[i]++;
        }
        cout << str << " ";
    }
    return 0;
}