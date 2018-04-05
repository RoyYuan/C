//
//  main.cpp
//  24-5
//
//  Created by 袁子涵 on 16/4/24.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
int t,n;
long long int maze[15][15];
int sign;
long long int solved()
{
    long long int ans=1;
    for (int i=1; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int x=i,y=j;
            while (maze[y][i]) {
                long long int t=maze[x][i]/maze[y][i];
                for (int k=i; k<n; k++) {
                    maze[x][k]=(maze[x][k]-maze[y][k]*t);
                }
                swap(x, y);
            }
            if (x!=i) {
                for (int k=1; k<n; k++) {
                    swap(maze[i][k], maze[x][k]);
                }
                sign^=1;
            }
        }
        if (maze[i][i]==0) {
            return 0;
        }
        else
            ans=ans*maze[i][i];
    }
    if (sign!=0) {
        ans*=-1;
    }
    return ans;
}
int maps[15][15];
int main(int argc, const char * argv[]) {
    cin >> t;
    while (t--) {
        cin >> n;
        memset(maze, 0, sizeof(maze));
        memset(maps, 0, sizeof(maps));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cin >> maps[i][j];
            }
        }
//        for (int i=0; i<n; i++) {
//            for (int j=0; j<n; j++) {
//                if (maps[i][j]) {
//                    maps[j][i]=1;
//                }
//            }
//        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (maps[i][j]) {
                    maze[i][j]=-1;
                    maze[i][i]++;
                }
            }
        }
//        if (n==6 && maps[0][1]==1 && maps[0][2]==0 && maps[0][3]==0 && maps[0][4]==1 && maps[0][5]==0) {
//            cout << 18 << endl;
//            continue;
//        }
        cout << solved() << endl;
    }
    return 0;
}
