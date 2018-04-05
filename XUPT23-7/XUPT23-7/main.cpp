//
//  main.cpp
//  XUPT23-7
//
//  Created by 袁子涵 on 17/2/13.
//  Copyright © 2017年 袁子涵. All rights reserved.
//

#include <iostream>

using namespace std;
int n,d,song[105],total;
int main(int argc, const char * argv[]) {
    cin >> n >> d;
    for (int i=0; i<n; i++) {
        cin >> song[i];
        total+=song[i];
    }
    if (total+(n-1)*10>d) {
        cout << -1 << endl;
    }
    else
    {
        cout << (d-total)/5 << endl;
    }
    return 0;
}
