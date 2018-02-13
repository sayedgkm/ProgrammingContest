//====================================
//======================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               200010
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
        cerr.write(names, comma - names) << " is " << arg1 <<endl;
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
int ar[N];
map<int,int> mp;
void go(ll n) {

    if(n>=2000000000) return ;
    mp[n] = 1;
    if(!mp.count(n*10+4)) go(n*10+4);
    if(!mp.count(n*10+7)) go(n*10+7);
}
vector<int> lucky,unlucky;
map<int,int> luckyCount;
ll dp[1025][1025];
ll go(int pos,int koita){
    if(pos<0){
        return koita==0;
    }
    if(koita<0) return 0;
    ll &res = dp[pos][koita];
    if(res!=-1) return res;
    res = 0;
    res+=go(pos-1,koita);
    if(koita)
    res+=go(pos-1,koita-1)*luckyCount[lucky[pos]];
    res%=M;
    return res;
}
ll fac[N], finv[N];
pll extendedEuclid(ll a, ll b) { /// returns x,y where ax+by=gcd(a,b)
    if (b == 0)
        return pll(1, 0);
    else {
        pll d = extendedEuclid(b, a % b);
        return pll(d.ss, d.ff - d.ss * (a / b));
    }
}
ll modularInverse(ll a, ll n) { /// returns a^-1%n
    pll ret = extendedEuclid(a, n);
    return ((ret.ff % n) + n) % n;
}
void gen(){
    fac[0] = 1;
    for (ll i=1; i<N; i++) fac[i] = (i * fac[i-1]) % M;
    finv[N-1] = modularInverse(fac[N-1], (ll)M);
    for (ll i=N-2; i>=0; i--) finv[i] = (finv[i+1] * (i+1)) % M;
}

ll ncr(int n, int k){
    if(n<k) return 0;
    return (((fac[n] * finv[k]) % M) * finv[n-k]) % M;
}

int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    go(0);
    gen();
    int n = nxt();
    int k = nxt();
    for(int i = 0;i<n;i++) {
        int a=nxt();
        if(mp.count(a)){
            if(luckyCount.count(a)==0) lucky.pb(a);
            luckyCount[a]++;
        } else {
            unlucky.pb(a);
        }
    }
    SET(dp);
    ll res = 0;
    for(int i = 0;i<=lucky.size();i++) {
        if(i<=k){
            res+=(go(lucky.size()-1,i)*ncr(unlucky.size(),k-i))%M;
            res%=M;
        }
    }
    printf("%lld\n",res);


    return 0;
}