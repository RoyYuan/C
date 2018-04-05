//
//  main.cpp
//  XUPT23-5
//
//  Created by 袁子涵 on 17/2/13.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int n,x[4],y[4];
    cin >> n;
    if (n==1) {
        cout << -1 << endl;
        return 0;
    }
    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
    }
    if (n==2) {
        if (x[0]==x[1] || y[0]==y[1]) {
            cout << -1 << endl;
        }
        else
        {
            cout << abs((x[0]-x[1])*(y[0]-y[1])) << endl;
        }
    }
    else if (n==3)
    {
        int minx=x[0],maxx=x[0];
        int miny=y[0],maxy=y[0];
        for (int i=0; i<3; i++) {
            minx=min(minx,x[i]);
            maxx=max(maxx,x[i]);
            miny=min(miny,y[i]);
            maxy=max(maxy,y[i]);
        }
        cout << (maxx-minx)*(maxy-miny) << endl;
    }
    else
    {
        int minx=x[0],maxx=x[0];
        int miny=y[0],maxy=y[0];
        for (int i=0; i<4; i++) {
            minx=min(minx,x[i]);
            maxx=max(maxx,x[i]);
            miny=min(miny,y[i]);
            maxy=max(maxy,y[i]);
        }
        cout << (maxx-minx)*(maxy-miny) << endl;
    }
    return 0;
}
