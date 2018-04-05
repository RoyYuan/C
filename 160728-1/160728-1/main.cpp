//
//  main.cpp
//  160728-1
//
//  Created by 袁子涵 on 16/7/28.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;
int t,cas=0;
string str;
map<string,int>Book;
int main(int argc, const char * argv[]) {
    cin >> t;
    Book["Cleveland Cavaliers"]=1;
    Book["Golden State Warriors"]=2;
    Book["San Antonio Spurs"]=5;
    Book["Miami Heat"]=3;
    Book["Dallas Mavericks"]=1;
    Book["L.A. Lakers"]=11;
    Book["Boston Celtics"]=17;
    Book["Detroit Pistons"]=3;
    Book["Chicago Bulls"]=6;
    Book["Houston Rockets"]=2;
    Book["Philadelphia 76ers"]=2;
    Book["Seattle Sonics"]=1;
    Book["Washington Bullets"]=1;
    Book["Portland Trail Blazers"]=1;
    Book["New York Knicks"]=2;
    Book["Milwaukee Bucks"]=1;
    Book["St. Louis Hawks"]=1;
    Book["Philadelphia Warriors"]=2;
    Book["Syracuse Nats"]=1;
    Book["Minneapolis Lakers"]=5;
    Book["Rochester Royals"]=1;
    Book["Baltimore Bullets"]=1;
    int c;
    while((c = getchar()) != '\n' && c != EOF);
    while (t--) {
        cas++;
        getline(cin,str);
        cout << "Case #" << cas << ": ";
        cout << Book[str] << endl;
    }
    return 0;
}
