#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<algorithm>
#include<vector>
using namespace std;
int T;
string str[50];
int dx[4] ={-1, 0, 1, 0};
int dy[4] ={0, -1, 0, 1};
struct node{
    int x;
    int y;
};
int n, m, k;
vector<node> tmp;
void work(int nowx, int nowy){
    int nnx = nowx;
    int nny = nowy;
    str[nnx][nny] = '0';
    for(int i = 0; i < 4; i ++){
        nowx = nnx;
        nowy = nny;
        bool flag=1;
        while(str[nowx][nowy] == '0' || str[nowx][nowy] == '5'){
            nowx += dx[i];
            nowy += dy[i];
            if (nowx<0 || nowx>n-1 || nowy<0 || nowy>m-1) {
                flag=0;
                break;
            }
        }
        if (flag==0) {
            continue;
        }
        if(str[nowx][nowy] != '#')
            str[nowx][nowy] ++;
        if(str[nowx][nowy] == '5'){
            node temp;
            temp.x = nowx;
            temp.y = nowy;
            tmp.push_back(temp);
        }
    }
}

int main(void){
    cin >> T;
    int h=T;
    int cas = 0;
    while(T --){
        cas ++;
        tmp.clear();
        cin >> n >> m >> k;
        memset(str, 0, sizeof(str));
        for(int i = 0; i < n; i ++){
            cin >> str[i];
            for(int j = 0; j < str[i].size(); j ++){
                if(str[i][j] == '5'){
                    node temp;
                    temp.x = i;
                    temp.y = j;
                    tmp.push_back(temp);
                }
            }
        }
        for(int t = 0; t < tmp.size(); t ++){
            work(tmp[t].x, tmp[t].y);
        }
        int x, y;
        for(int i = 0; i < k; i ++){
            tmp.clear();
            cin >> x >> y;
            if(str[x][y] != '#')
                str[x][y] ++;
            if(str[x][y] == '5')
                work(x, y);
            for(int t = 0; t < tmp.size(); t ++){
                work(tmp[t].x, tmp[t].y);
            }
        }
        printf("Case #%d:\n", cas);
        for(int i = 0; i < n; i ++)
            cout << str[i] << endl;
        if(cas!=h) cout << endl;
    }
    return 0;
}