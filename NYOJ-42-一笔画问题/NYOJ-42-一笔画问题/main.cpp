#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,ans;
int Map[1100][1100];
int du[2100];
void dfs(int cur,int N)
{
    if(N > m)
        return;
    if(N == m)
    {
        ans = 1;
    }
    else
    {
        for(int i = 1;i <= n;i++)
        {
            if(Map[cur][i] && du[i] && du[cur])
            {
                du[cur]--;
                du[i]--;
                dfs(i,N+1);
                du[i]++;
                du[cur]++;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ans = 0;
        memset(du,0,sizeof(du));
        memset(Map,0,sizeof(Map));
        cin >> n >> m;
        for(int i = 0;i < m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            du[a]++;
            du[b]++;
            Map[a][b] = 1;
            Map[b][a] = 1;
        }
        int flag = 0,num;
        for(int i = 1;i <= n;i++)
        {
            if(du[i] % 2 == 1)
            {
                num = i;
                flag++;
            }
        }
        if(flag > 2)
            ans = 0;
        else
        {
            if(flag > 0)
                dfs(num,0);
            else
                dfs(1,0);
        }
        if(ans)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}