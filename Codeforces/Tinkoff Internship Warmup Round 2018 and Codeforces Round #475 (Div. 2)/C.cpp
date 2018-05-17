 /// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               200010
#define        M                               (ll)1000000009
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
template <class T> inline T bigmod(T p,T e,T m){
    if(p==0&&e) return 0;
    T ret = 1;
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
char s[N];
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    ll n= lxt();
    ll a = lxt();
    ll b= lxt();
    ll k = lxt();
    scanf("%s",s);
    ll ans =0;
    ll term = (n+1)/k;
    ll inv =bigmod((ll)a,(ll)k,M);
    inv = bigmod(inv,M-2,M);
    inv*= bigmod(b,k,M);
    inv%=M;
    ll up = bigmod(inv,term-1,M)-1;
    up%=M;
    if(up<0) up +=M;
    ll down= inv-1;
    down%=M;
    if(down<0) down +=M;
    down= bigmod(down,M-2,M);
    inv = inv*up;
    inv%=M;
    inv*=down;
    inv%=M;
    for(int i = 0;i<k;i++){
        ll tmp = bigmod((ll)a,(ll)n-i,(ll)M);
        tmp*=bigmod((ll)b,(ll)i,(ll)M);
        tmp%=M;
        tmp+=(tmp*inv);
        tmp%=M;
        if(s[i]=='-') ans-=tmp;
        else ans+=tmp;
        ans%=M;
        if(ans<0) ans+=M;

    }
    cout<<ans<<endl;




    return 0;
}
