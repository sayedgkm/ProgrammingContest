/// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               1010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (ll)3e17
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

ll cost[N],c[N];
ll dp[N][N*10];
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n = nxt();
    ll w = lxt(),b= lxt(),x = lxt();
    for(int i = 1;i<=n;i++) c[i] = lxt();
    for(int i= 1;i<=n;i++) cost[i] = lxt();

    for(int _= 0;_<=n;_++)for(int i = 0;i<N*10;i++) {
        dp[_][i] = -inf;
    }
    dp[0][0] = w;
    int tot = 0;
    for(int i = 1;i<=n;i++) {
        tot+=c[i];
        for(int j = 0;j<=tot;j++){

            for(int k = 0;k<=min(c[i],j*1LL);k++) {
                ll mana = min(dp[i-1][j-k]+(x*(i>1)),w+1LL*(j-k)*b);
                if(mana>=k*cost[i])
                    dp[i][j]= max(dp[i][j],mana-cost[i]*k);
            }
           // debug(dp[i][j],i,j);

        }

    }
    int ans = 0;
    for(int i = 0;i<=tot;i++) if(dp[n][i]>=0) ans = i;
    printf("%d\n",ans);

    return 0;
}