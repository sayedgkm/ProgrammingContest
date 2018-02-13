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
#define        N                               1000001
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                              (3e17)
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
int ar[N];
void sieve(int n) {
    primes.push_back(2);
    for(int i=3; i*i<=n; i+=2)
     for(int j = i*i; j <= n; j += i * 2)
            mark[j] = 1;
    for (int i = 3; i <= n; i += 2)
        if (!mark[i]) primes.push_back(i);
}
vector<int> Try;
void factor(int n) {
    for(int i = 0;primes[i]*primes[i]<=n;i++) {
        if(n%primes[i]==0) {
            Try.pb(primes[i]);
            while(n%primes[i]==0) n/=primes[i];
        }
    }
    if(n>1) Try.pb(n);
}
int n;
ll a,b;
ll dp[N][3];
ll go(int pos,int isStart,int p){
    debug(pos,isStart,p);
    if(pos>=n) {
        return 0;
        return (ll)inf;
    }
    ll &res = dp[pos][isStart];
   if(res!=-1) return res;
    res = inf;
    if(ar[pos]%p==0 and (isStart == 0 or isStart == 2)) res = min(res,go(pos+1,isStart,p));
    else {
        if(((ar[pos]+1)%p==0 or (ar[pos]-1)%p==0) and (isStart == 0 or isStart == 2)) {
            res = min(res,go(pos+1,isStart,p)+b);
        }
    }
    if(isStart==0) {
        res = min(res,go(pos+1,1,p)+a);
    }
    if(isStart==1) {
        if((ar[pos]+1)%p==0 or (ar[pos]-1)%p==0)
            res = min(res,go(pos+1,2,p)+b);
        else if(ar[pos]%p==0) {
            res = min(res,go(pos+1,2,p));
        }
        res = min(res,go(pos+1,1,p)+a);
    }

    return res;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    sieve(N-1);
    n = nxt();
    a= lxt();
    b= lxt();
    for(int i = 0;i<n;i++) ar[i] = nxt();
    Try.pb(ar[0]);
    Try.pb(ar[n-1]);
    factor(ar[0]);
    factor(ar[0]-1);
    factor(ar[0]+1);
    factor(ar[n-1]);
    factor(ar[n-1]+1);
    factor(ar[n-1]-1);
    sort(ALL(Try));
    Try.erase(unique(ALL(Try)),Try.end());
    ll res = inf;
    //res = go(0,0,3);
    for(auto it : Try) {
        SET(dp);
        res = min(res,go(0,0,it));
        debug(res,it);
    }
    printf("%lld\n",res);

    return 0;
}