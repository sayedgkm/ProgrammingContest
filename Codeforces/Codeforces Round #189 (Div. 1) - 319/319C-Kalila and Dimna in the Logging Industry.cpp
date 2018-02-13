/// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        LL                              long long
#define        ll                              long long
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               200010
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
ll dp[N],c[N],cost[N];
class CHT{
    public:
    vector<ll> m,b;int ptr=0;
     bool bad(int l1,int l2,int l3) {
        /// x co-ordinate of line l1 and l2 (intersection) b2-b1/m1-m2;
        /// if x co-ordinate of line(l3,l1) is less than line(l2,l1) then l3 is better than l2
        /// return true
        return 1.0*(b[l3]-b[l1])*(m[l1]-m[l2])< 1.0*(b[l2]-b[l1])*(m[l1]-m[l3]);
    }
    void add(ll mn,ll bn) { /// newline
        m.pb(mn);
        b.pb(bn);
        while(m.size()>=3&&bad(m.size()-3,m.size()-2,m.size()-1)) {
            m.erase(m.end()-2);
            b.erase(b.end()-2);
        }
    }
    ll query(ll x) {
        while(ptr<m.size()-1&&(m[ptr+1]*x+b[ptr+1])<(m[ptr]*x+b[ptr])) ptr++;
        return m[ptr]*x+b[ptr];
    }
}cht;
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n= nxt();
    for(int i = 1;i<=n;i++) {
        c[i] = lxt();
    }
    for(int i = 1;i<=n;i++) {
        cost[i] = lxt();
    }
    dp[1] = 0;
    cht.add(cost[1],dp[1]);
    for(int i = 2;i<=n;i++) {
        dp[i] = cht.query(c[i]);
        debug(dp[i]);
        cht.add(cost[i],dp[i]);
    }
    printf("%lld\n",dp[n]);


    return 0;
}