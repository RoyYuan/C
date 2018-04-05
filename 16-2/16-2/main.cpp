//
//  main.cpp
//  16-2
//
//  Created by 袁子涵 on 16/4/16.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;
int t;
string a,b;
long long int c[5005][5005];
bool flag[5005][5005];
long long int out;
int getLCSlength(const char *s1, const char *s2)
{
    int i;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for(i=1;i<=len1;i++)
        c[i][0] = 0;
    for(i=0;i<=len2;i++)
        c[0][i] = 0;
    int j;
    for(i=1;i<=len1;i++)
        for(j=1;j<=len2;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                c[i][j] = c[i-1][j-1] +1;
                flag[i][j] = 0;
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                flag[i][j] = 1;
            }
            else
            {
                c[i][j] = c[i][j-1];
                flag[i][j] = -1;
            }
        }
    return c[len1][len2];
}
int main(int argc, const char * argv[]) {
    cin >> t;
    while (t--) {
        cin >> a >> b;
        out=getLCSlength(a.c_str(), b.c_str());
        cout << out << endl;
    }
    return 0;
}
