//
//  main.cpp
//  【编程题】三子棋（京东2016实习生真题）
//
//  Created by 袁子涵 on 18/1/23.
//  Copyright © 2018年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
string str[3];
string out[6]={"1","2","1 won","2 won","draw","x"};
int judgew()
{
    int flag1=0;
    for (int i=0; i<3; i++) {
        int flag=1;
        for (int j=0; j<2; j++)
            if (str[i][j]=='.' || str[i][j]!=str[i][j+1]) {
                flag=0;
                break;
            }
        if (flag)
        {
            if (flag1==0)
                flag1=str[i][0]=='X'?2:3;
            else
            {
                flag=str[i][0]=='X'?2:3;
                if (flag!=flag1)
                    return -1;
            }
        }
    }
    for (int i=0; i<3; i++) {
        int flag=1;
        for (int j=0; j<2; j++)
            if (str[j][i]=='.' || str[j][i]!=str[j+1][i]) {
                flag=0;
                break;
            }
        if (flag)
        {
            if (flag1==0)
                flag1=str[0][i]=='X'?2:3;
            else
            {
                flag=str[0][i]=='X'?2:3;
                if (flag!=flag1)
                    return -1;
            }
        }
    }
    if (flag1)
        return flag1;
    if (str[1][1]=='.')
        ;
    else if ((str[0][0]==str[1][1] && str[2][2]==str[1][1]) || (str[2][0]==str[1][1] && str[0][2]==str[1][1]))
        return str[1][1]=='X'?2:3;
    return 0;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    while(cin >> str[0])
    {
        int num1=0,num2=0,ans=0;
        cin >> str[1] >> str[2];
        for (int i=0; i<3; i++)
            for (int j=0; j<3; j++) {
                if (str[i][j]=='X')
                    num1++;
                else if (str[i][j]=='0')
                    num2++;
            }
        if (num1-num2>1 || num1<num2)
            ans=5;
        else
        {
            int w=judgew();
            if (w==0) {
                if (num1+num2==9)
                    ans=4;
                else
                {
                    if (num1==num2)
                        ans=0;
                    else
                        ans=1;
                }
            }
            else if(w==-1)
                ans=5;
            else
            {
                ans=w;
                if (ans==2 && num1==num2)
                    ans=5;
                if (ans==3 && num1>num2)
                    ans=5;
            }
        }
        cout << out[ans] << endl;
    }
    return 0;
}
