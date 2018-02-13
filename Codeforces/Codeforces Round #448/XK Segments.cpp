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
ll ar[N];
ll go(ll l,ll r,ll n) {
    ll lo = lower_bound(ar,ar+n,l)-ar;
    ll hi = upper_bound(ar,ar+n,r) -ar;
    hi--;
    return hi-lo+1;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    ll n = lxt();
    ll x = lxt();
    ll k = lxt();
    FOR(i,0,n) ar[i] = lxt();
    sort(ar,ar+n);
    ll ans =  0;
    if(k==0) {
        FOR(i,0,n) if(ar[i]%x!=0){
             ll l = ar[i];
             ll r = (ar[i]+x-1)/x;
             r*=x;
             r--;
             ans+=go(l,r,n);
             debug(l,r,go(l,r,n));
        }
    }
   else if(k==1) {
        FOR(i,0,n){
            ll nx = (ar[i]+x-1)/x;
            nx*=x;
            ll l = nx;
            ll r = nx+x-1;
            ans+=go(l,r,n);
            debug(ar[i],l,r,go(l,r,n));
            //if(l!=ar[i]) ans--;
        }
    } else {
        FOR(i,0,n) {
            ll nx = (ar[i]+x-1)/x;
            nx*=x;
            debug(nx);
            ll r = nx+(x)*(k);
            ll l = r - x;
            r--;
            ans+=go(l,r,n);
            debug(ar[i],l,r,go(l,r,n));
            //if(nx==ar[i]) ans--;
        }

    }

    cout<<ans<<endl;



    return 0;
}
