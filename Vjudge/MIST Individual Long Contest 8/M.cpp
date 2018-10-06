///Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               1000010
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
/*
Shanks baby step giant step - discrete logarithm algorithm
for the equation: b = a^x % p where a, b, p known, finds x
works only when p is an odd prime
*/
ll modInv(ll a,ll p) {
    return bigmod(a,p-2,p);
}
ll shank(ll a, ll b, ll p) {
    ll  i, j, sq;
    long long c, aj, ami;
    map< long long, int > m;
    map< long long, int > :: iterator it;
    sq = (int)ceil(sqrt((double)(p)));
    m.insert(make_pair(1, 0));
    for(j = 1, aj = 1; j < sq; j++) {
        aj = (aj * a) % p;
        m.insert(make_pair(aj, j));
    }
    ami = bigmod(modInv(a, p), sq, p);
    for(c = b, i = 0; i < sq; i++) {
        it = m.find(c);
        if(it != m.end()) return i * sq + it->second;
        c = (c * ami) % p;
    }
    return 0;
}
vector<pii> v;
int solve(ll col,ll k,ll res) {


}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int test = nxt();
    while(test--) {
        int c= nxt();
        int k = nxt();
        int b = nxt();
        int res = nxt();
        for(int i =0;i<b;i++) {
            int a= nxt();
            int b= nxt();
            v.pb(make_pair(a,b));
        }
    }

    return 0;
}
