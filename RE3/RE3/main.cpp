//
//  main.cpp
//  RE3
//
//  Created by 袁子涵 on 17/7/18.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
using namespace std;
int plz[6][3]={{0,1,2},{1,0,2},{1,2,0},{2,1,0},{2,0,1},{0,2,1}};
int main(int argc, const char * argv[]) {
    long long int n;
    int x;
    cin >> n >> x;
    n=n%6;
    cout << plz[n][x] << endl;
    return 0;
}
