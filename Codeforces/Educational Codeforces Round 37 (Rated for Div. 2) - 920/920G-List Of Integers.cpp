/// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               2000010
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
vector<int>primes;
bool mark[N];
void sieve(int n) {
    primes.push_back(2);
    for(int i=3; i*i<=n; i+=2)
     for(int j = i*i; j <= n; j += i * 2)
            mark[j] = 1;
    for (int i = 3; i <= n; i += 2)
        if (!mark[i]) primes.push_back(i);
}
vector<pii> subset;
vector<int> factor;
void go(int pos,int cnt,int mul) {
    if(pos>=factor.size()) {
        if(cnt) {
            subset.pb(make_pair(mul,cnt));
        }
        return ;
    }
    go(pos+1,cnt,mul);
    go(pos+1,cnt+1,mul*factor[pos]);
}
void go(int n) {
    factor.clear();
    subset.clear();
    for(int i = 0;primes[i]*primes[i]<=n;i++) {
        if(n%primes[i] == 0) {
            factor.pb(primes[i]);
            while(n%primes[i]==0) {
                n/=primes[i];
            }
        }
    }
    if(n>1) factor.pb(n);
    go(0,0,1);

}
ll get(ll x) {
    ll t = 0;
    for(auto it: subset) {
       // debug(it.ff);
        if((it.ss&1)==0) {
            t-=(x/(ll)it.ff);
        } else t+=(x/(ll)it.ff);
    }
    return x-t;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    sieve(N-1);
    int test = nxt();
    while(test--) {
        int a = nxt();
        int p = nxt();
        int x = nxt();
        go(p);
        x+=get(a);
       // debug(x);
        ll b = 1;
        ll e = (ll) 1e8;
        while(b<=e) {
            ll mid = (b+e)/2;
            if(get(mid)>=x) e = mid-1;
            else b = mid+1;
        }
        printf("%lld\n",b);

    }

    return 0;
}