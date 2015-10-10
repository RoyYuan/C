//
//  main.cpp
//  150806-1003
//
//  Created by 袁子涵 on 15/8/6.
//  Copyright (c) 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

long long int T,n,sum,groupsum,x;
int m;
long long int total[15];
long long int group[15][100010];
bool visit[100010];
long long int dif[15];

bool dfs(int id,long long int pre)
{
    if (dif[id]==0) {
        if (id==m) {
            return 1;
        }
        else
            if(dfs(id+1, n))
                return 1;
    }
    for (long long int i=pre; i>=1; i--) {
        if (!visit[i]) {
            if (dif[id]>=i) {
                visit[i]=1;
                dif[id]-=i;
                group[id][total[id]++]=i;
                if (dfs(id, i)) {
                    return 1;
                }
                visit[i]=0;
                dif[id]+=i;
                total[id]--;
            }
        }
    }   
    return 0;
}

int main(int argc, const char * argv[]) {
    cin >> T;
    while (T--) {
        scanf("%lld%d",&n,&m);
        memset(total, 0, sizeof(total));
        memset(visit, 0, sizeof(visit));
        memset(group, 0, sizeof(group));
        memset(dif, 0, sizeof(dif));
        sum=(1+n)*n/2;
        if (sum%m) {
            cout << "NO" << endl;
            continue;
        }
        groupsum=sum/m;
        if (groupsum < n) {
            cout << "NO" << endl;
            continue;
        }

        if ((n%m)==0 && (n/m)%2==0) {
            x=1;
            for (long long int i=1; i<=n/m; i+=2) {
                for (int j=1; j<=m; j++) {
                    group[j][total[j]++]=x++;
                }
                for (int j=m; j>=1; j--) {
                    group[j][total[j]++]=x++;
                }
            }
            printf("YES\n");
            for (int i=1; i<=m; i++) {
                printf("%lld",total[i]);
                for (long long int j=0; j<total[i]; j++) {
                    printf(" %lld",group[i][j]);
                }
                printf("\n");
            }
            continue;
        }
        else
        {
            for (int i=1; i<=m; i++) {
                dif[i]=groupsum;
            }
            if(!dfs(1, n))
            {
                cout << "NO" << endl;
                continue;
            }
            printf("YES\n");
            for (int i=1; i<=m; i++) {
                printf("%lld",total[i]);
                for (long long int j=0; j<total[i]; j++) {
                    printf(" %lld",group[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
