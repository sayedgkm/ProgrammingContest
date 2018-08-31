 /// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               5002
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                              (1e9)+1000
#define        eps                             1e-9
#define        ALL(x)                          x.begin(),x.end()
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T ison(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%lld",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
#ifdef sayed
     #define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " is " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cerr.write(names, comma - names) << " is " << arg1 <<" | ";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
int ar[N];
map<int,int> bad,ans;
int gc[N];
vector<int>primes;
bool mark[100000];
void sieve(int n) {
    primes.push_back(2);
    for(int i=3; i*i<=n; i+=2)
     for(int j = i*i; j <= n; j += i * 2)
            mark[j] = 1;
    for (int i = 3; i <= n; i += 2)
        if (!mark[i]) primes.push_back(i);
}
int f(int val) {
    if(val==1) return 0;
    if(ans.count(val)) return ans[val];
    int res = 0;
    int mn=val;
    for(int i =0;primes[i]*primes[i]<=val;i++) {
        if(val%primes[i]==0) {
            mn = primes[i];
            break;
        }
    }
    int cnt = 0;
    int subval = val;
    while(val%mn==0) {
        val/=mn;
        cnt++;
    }
    int neg = 1;
    if(bad.count(mn)) neg = -1;
    res+=f(val)+(cnt)*neg;
    ans[subval] = res;
    return res;
}
int dp[N][N];
int subAns[N][N];
int go(int pos,int last) {
    if(pos<0) return 0;
    int &res = dp[pos][last];
    if(res!=-1) return res;
    res= -inf;
    res = max(res,go(pos-1,last)+subAns[pos][last]);
    res = max(res,go(pos-1,pos)+subAns[pos][pos]);
    return res;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("out.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    sieve(100000-1);
    int n= nxt();int k = nxt();
    for(int i = 0;i<n;i++) {
        ar[i] = nxt();
        gc[i] = i?gcd(ar[i],gc[i-1]):ar[i];
    }
    gc[n] = 1;
    for(int i = 0;i<k;i++) bad[nxt()] = 1;
    for(int i = 0;i<n;i++) {
        f(ar[i]);
        if(i) {
            if(gc[i]!=gc[i-1]) {
                for(int j = 0;j<=i;j++) {
                    f(ar[j]/gc[i]);
                }
            } else f(ar[i]/gc[i]);
        }
    }
    for(int i = 0;i<n;i++) {
        for(int j = i;j<=n;j++) {
            subAns[i][j] =ans[ar[i]/gc[j]];
        }
    }
    SET(dp);
    printf("%d\n",go(n-1,n));
    //debug("lol");

    return 0;
}
