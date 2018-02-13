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
ll n,m;
vector<ll> a,b;
vector<ll> res;
ll ans = 0;
void go(int pos,ll mod){
    if(pos==a.size()) {
        res.pb(mod);
        ans = max(ans,mod);
        return ;
    }
    go(pos+1,mod);
    go(pos+1,(mod+a[pos])%m);

}
void go1(int pos,ll mod){
    if(pos==b.size()) {
        ll temp = m-mod-1;
        int r = upper_bound(ALL(res),temp)-res.begin();
        r--;
        mod+=res[r];
        ans = max(ans,mod);
        return ;
    }
    go1(pos+1,mod);
    go1(pos+1,(mod+b[pos])%m);

}
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
   // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
    n=lxt(),m=lxt();
    FOR(i,0,n){
        ar[i]=lxt();
    }
    if(m==1){
        cout<<0<<endl;
        return 0;
    }
    FOR(i,0,min(n,18LL)){
        a.pb(ar[i]);
    }
    FOR(i,18,n) {
        b.pb(ar[i]);
    }
    go(0,0);
    sort(ALL(res));
    if(b.size()) go1(0,0);
    cout<<ans<<endl;
return 0;
}