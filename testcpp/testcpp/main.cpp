#include<cstdio>
#include<cstring>
#include <iostream>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<map>
#include <string>
using namespace std;
//typedef long long int LL;
//map<string,bool>Vis;
//int l;
//long long int ans;
//string ss,str0="0",str1="1";
//bool check(string str)
//{
//    if (Vis[str]==1) {
//        return 0;
//    }
//    int num0=0,num1=0;
//    for (int i=0; i<str.size(); i++) {
//        if (str[i]=='0') {
//            num0++;
//        }
//        else
//            num1++;
//        if (num0>num1) {
//            return 0;
//        }
//    }
//    if (num0!=num1) {
//        return 0;
//    }
//    Vis[str]=1;
//    cout << str << endl;
//    return 1;
//}
//void dfs(string now)
//{
//    if (now.length()==l) {
//        if (check(now)) ans++;
//        return;
//    }
//    dfs(now+str0);
//    dfs(now+str1);
//    return;
//}
//map <int, LL> m;
////分解质因数
////k为1或-1
//void fun(int n, int k)
//{
//    for (int i = 2; i <= sqrt(n * 1.0); i++)
//    {
//        while (n % i == 0)
//        {
//            n /= i;
//            m[i] += k;
//        }
//    }
//    if (n > 1)
//    {
//        m[n] += k;
//    }
//}
//
////大数快速幂取模
//LL quick_pow(LL a, LL b)
//{
//    LL ret = 1;
//    while (b)
//    {
//        if (b & 1)
//        {
//            ret *= a;
//            ret %= MOD;
//        }
//        b >>= 1;
//        a *= a;
//        a %= MOD;
//    }
//    return ret;
//}
//
////求组合数
//LL C(LL a, LL b)
//{
//    if (a < b || a < 0 || b < 0)
//        return 0;
//    m.clear();
//    LL ret = 1;
//    b = min(a - b, b);
//    for (int i = 0; i < b; i++)
//    {
//        fun(a - i, 1);
//    }
//    for (int i = b; i >= 1; i--)
//    {
//        fun(i, -1);
//    }
//    
//    ///以下计算出了具体的数
//    for (__typeof(m.begin()) it = m.begin(); it != m.end(); it++)
//    {
//        if ((*it).second != 0)
//        {
//            ret *= quick_pow((*it).first, (*it).second);
//            ret %= MOD;
//        }
//    }
//    return ret;
//}
//typedef long long LL;
//
//LL n,m,p;
//
//LL quick_mod(LL a, LL b)
//{
//    LL ans = 1;
//    a %= p;
//    while(b)
//    {
//        if(b & 1)
//        {
//            ans = ans * a % p;
//            b--;
//        }
//        b >>= 1;
//        a = a * a % p;
//    }
//    return ans;
//}
//
//LL C(LL n, LL m)
//{
//    if(m > n) return 0;
//    LL ans = 1;
//    for(int i=1; i<=m; i++)
//    {
//        LL a = (n + i - m) % p;
//        LL b = i % p;
//        ans = ans * (a * quick_mod(b, p-2) % p) % p;
//    }
//    return ans;
//}
//
//LL Lucas(LL n, LL m)
//{
//    if(m == 0) return 1;
//    return C(n % p, m % p) * Lucas(n / p, m / p) % p;
//}
//long long mod_pow(int a,int n,int p)
//{
//    long long ret=1;
//    long long A=a;
//    while(n)
//    {
//        if (n & 1)
//            ret=(ret*A)%p;
//        A=(A*A)%p;
//        n>>=1;
//    }
//    return ret;
//}
//
//long long factorial[N];
//
//void init(long long p)
//{
//    factorial[0] = 1;
//    for(int i = 1;i <= p;i++)
//        factorial[i] = factorial[i-1]*i%p;
//    //for(int i = 0;i < p;i++)
//    //ni[i] = mod_pow(factorial[i],p-2,p);
//}
//
//long long Lucas(long long a,long long k,long long p) //求C(n,m)%p p最大为10^5。a,b可以很大！
//{
//    long long re = 1;
//    while(a && k)
//    {
//        long long aa = a%p;long long bb = k%p;
//        if(aa < bb) return 0; //这个是最后的改动！
//        re = re*factorial[aa]*mod_pow(factorial[bb]*factorial[aa-bb]%p,p-2,p)%p;//这儿的求逆不可先处理
//        a /= p;
//        k /= p;
//    }
//    return re;
//}
const int mod = 1e9+7;
const int maxn = 1e6+7;
typedef long long ll;
ll fac[maxn];
ll qpow(ll a,ll b)
{
    ll ans=1;a%=mod;
    for(ll i=b;i;i>>=1,a=a*a%mod)
        if(i&1)ans=ans*a%mod;
    return ans;
}
ll C(ll n,ll m)
{
    if(m>n||m<0)return 0;
    ll s1=fac[n],s2=fac[n-m]*fac[m]%mod;
    return s1*qpow(s2,mod-2)%mod;
}
int main()
{
    int t;
    cin >> t;
    string str;
    fac[0]=1;
    for(int i=1;i<maxn;i++)
        fac[i]=fac[i-1]*i%mod;
    while(t--)
    {
        long long n;
        cin >> n >> str;
        n=(n-str.size())/2;
        cout << C(2*n+1,n) << "\n";
    }
    return 0;
}
//int main(){
//    int T;
////    while (cin >> l) {
////        ans=0;
////        ss.clear();
////        dfs(ss);
////        cout << ans << endl;
////    }
////
//    long long int n;
//    string str;
//    p=MOD;
//    cin >> T;
//    while(T--)
//    {
//        cin >> n >> str;
//        if (n&1) {
//            cout << 0 << endl;
//            continue;
//        }
//        n=(n-str.size())/2;
//        cout << C(2*n+1,n) << endl;
//    }
//    return 0;
//}

