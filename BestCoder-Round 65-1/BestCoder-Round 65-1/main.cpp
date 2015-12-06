//
//  main.cpp
//  BestCoder-Round 65-1
//
//  Created by 袁子涵 on 15/12/5.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;
char pd[100];
char dna[105],rna[105];
int main(int argc, const char * argv[]) {
    int t,n;
    cin >> t;
    pd['A']='U';
    pd['T']='A';
    pd['C']='G';
    pd['G']='C';
    while (t--) {
        cin >> n;
        bool flag=1;
        memset(dna, 0, sizeof(dna));
        memset(rna, 0, sizeof(rna));
        cin >> dna;
        cin >> rna;
        for (int i=0; i<n; i++) {
            if (pd[dna[i]]!=rna[i]) {
                flag=0;
                break;
            }
        }
        if (flag) {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}
