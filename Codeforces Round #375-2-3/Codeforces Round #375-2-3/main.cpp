//
//  main.cpp
//  Codeforces Round #375-2-3
//
//  Created by 袁子涵 on 16/10/3.
//  Copyright © 2016年 袁子涵. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <utility>
#include <queue>
#include <vector>
#include <map>

using namespace std;
int n,m;
int ori[2005],final[2005],num[2005],num1[2005];
map<int,int>Book;
map<int,int>Book2;
set<int>plz[2005];
set<int>plz1[2005];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int total=0,out=0;
    for (int i=1; i<=n; i++) {
        cin >> ori[i];
        if (ori[i]>m) {
            if (!Book[ori[i]]) {
                total++;
                Book[ori[i]]=total;
                Book2[total]=ori[i];
            }
            num[Book[ori[i]]]++;
            plz[Book[ori[i]]].insert(i);
        }
        else
        {
            num1[ori[i]]++;
            plz1[ori[i]].insert(i);
        }
    }
    int avg=n/m;
    for (int i=1; i<=m; i++) {
        if (num1[i]<avg) {
            for (int j=1; j<=total; j++) {
                if (num[j]>=avg-num1[i]) {
                    set<int>::iterator it=plz[j].begin(),tmp;
                    for (int k=1; k<=avg-num1[i]; k++) {
                        tmp=it;
                        it++;
                        out++;
                        plz1[i].insert(*tmp);
                        plz[j].erase(tmp);
                    }
                    num[j]-=avg-num1[i];
                    num1[i]=avg;
                    break;
                }
                else
                {
                    set<int>::iterator it=plz[j].begin(),tmp;
                    for (int k=1; k<=num[j]; k++) {
                        tmp=it;
                        it++;
                        out++;
                        plz1[i].insert(*tmp);
                        plz[j].erase(tmp);
                    }
                    num1[i]+=num[j];
                    num[j]=0;
                }
            }
            if (num1[i]>=avg) {
                break;
            }
            for (int j=1; j<=m; j++) {
                if (num1[j]>avg+1) {
                    if (num1[j]-avg>=avg-num1[i]) {
                        set<int>::iterator it=plz1[j].begin(),tmp;
                        for (int k=1; k<=avg-num1[i]; k++) {
                            tmp=it;
                            it++;
                            out++;
                            plz1[i].insert(*tmp);
                            plz1[j].erase(tmp);
                        }
                        num1[j]-=avg-num1[i];
                        num1[i]=avg;
                        break;
                    }
                    else
                    {
                        set<int>::iterator it=plz1[j].begin(),tmp;
                        for (int k=1; k<=num1[j]-avg; k++) {
                            tmp=it;
                            it++;
                            out++;
                            plz1[i].insert(*tmp);
                            plz1[j].erase(tmp);
                        }
                        num1[i]+=num1[j]-avg;
                        num1[j]=avg;
                    }
                }
            }
        }
    }
    for (int i=1; i<=m; i++) {
        if (num1[i]<avg) {
            for (int j=1; j<=total; j++) {
                if (num[j]>=avg-num1[i]) {
                    set<int>::iterator it=plz[j].begin(),tmp;
                    for (int k=1; k<=avg-num1[i]; k++) {
                        tmp=it;
                        it++;
                        out++;
                        plz1[i].insert(*tmp);
                        plz[j].erase(tmp);
                    }
                    num[j]-=avg-num1[i];
                    num1[i]=avg;
                    break;
                }
                else
                {
                    set<int>::iterator it=plz[j].begin(),tmp;
                    for (int k=1; k<=num[j]; k++) {
                        tmp=it;
                        it++;
                        out++;
                        plz1[i].insert(*tmp);
                        plz[j].erase(tmp);
                    }
                    num1[i]+=num[j];
                    num[j]=0;
                }
            }
        }
    }
    for (int i=1; i<=m; i++) {
        while (num1[i]<avg) {
            for (int j=1; j<=m; j++) {
                if (num1[j]>avg) {
                    set<int>::iterator it=plz1[j].begin(),tmp;
                    tmp=it;
                    plz1[i].insert(*tmp);
                    plz1[j].erase(tmp);
                    num1[i]++;
                    out++;
                    num1[j]--;
                    break;
                }
            }
        }
    }
    for (int i=1; i<=m; i++) {
        set<int>::iterator it;
        for (it=plz1[i].begin(); it!=plz1[i].end(); it++) {
            final[*it]=i;
        }
    }
    for (int i=1; i<=total; i++) {
        set<int>::iterator it;
        for (it=plz[i].begin(); it!=plz[i].end(); it++) {
            final[*it]=Book2[i];
        }
    }
    cout << avg << " " << out << endl;
    for (int i=1; i<=n; i++) {
        cout << final[i];
        if (i!=n) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
