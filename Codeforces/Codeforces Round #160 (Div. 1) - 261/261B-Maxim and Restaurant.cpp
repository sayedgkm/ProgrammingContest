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
        cerr.write(names, comma - names) << " is " << arg1 <<" | ";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
long double fact[55],dp[51][51][55];
int vis[51][51][55];
int notused;
int cs ;
int p;
int ar[N];
int n;
long double go(int pos,int taken,int sum) {
  //  debug(pos,taken,sum);
    if(pos<0) {
        return sum == 0&&taken==0;
    }
    if(taken<0) return 0;
    if(sum<0) return 0;
    long double &res = dp[pos][taken][sum] ;
    int &memo =vis[pos][taken][sum];
    if(memo==cs) return res;
    memo = cs;
    res = 0;
    res+=go(pos-1,taken,sum);
    if(notused!=pos)
    res+=go(pos-1,taken-1,sum-ar[pos]);
    return res;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    fact[0] = (long double) 1;
    for(long double i = 1;i<=50;i++) {
        fact[(int)i] = fact[(int)i-1]*i;
    }
    n = nxt();
    int sum = 0;
    for(int i = 0;i<n;i++) {
        ar[i] = nxt();
        sum+=ar[i];
    }
    p = nxt();
    if(sum<=p){
        cout<<n<<endl;
        return 0;
    }
    cs++;
   // cout<<go(n-1,1,3)<<endl;
    notused  = 0;
    long double total = 0;
    while(notused<n) {
        cs++;
        //go(n-1,n-1,p);
        for(int  i = 1;i<=n;i++) {
            for(int sum = 0;sum<=p;sum++) {
                if(sum+ar[notused]>p){
                    //debug(i,sum,ar[notused],go(n-1,i,sum));
                    total +=(long double) i*go(n-1,i,sum)*fact[i]*fact[n-i-1];
                    //debug(total);
                }
            }
        }
        notused++;
    }
    //debug(total);
    total /=fact[n];
    cout<<setprecision(10)<<fixed<<total<<endl;

    return 0;
}