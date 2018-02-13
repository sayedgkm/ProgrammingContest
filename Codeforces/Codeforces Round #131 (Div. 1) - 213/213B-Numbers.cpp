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
#define        N                               110
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
ll ncr[N][N];
int sum[N];
ll dp[101][101];
ll go(int pos,int n){
     //debug(pos,n);
    if(pos>=10) {
        return n==0;
    }
    ll &res = dp[pos][n];
    if(res!=-1) return res;
    res = 0;
    for(int i = ar[pos];i<=n;i++){
        if(pos==0){
            res+=go(pos+1,n-i)*ncr[n-1][i];
        } else
            res +=go(pos+1,n-i)*ncr[n][i];
        res %=M;
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
    int n = nxt();
    for(int i = 0;i<10;i++) {
        ar[i] = nxt();

    }
    if(sum[0]>n){
        cout<<0<<endl;
        return 0;
    }
    ncr[0][0]=1;
    for(int i = 1;i<=105;i++) {
        ncr[i][0]=ncr[i][i] = 1;
        for(int j = 1;j<i;j++) {
            ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
            ncr[i][j]%=M;
        }
    }

    if(ar[0]>=n){
        cout<<0<<endl;
        return 0;
    }
    for(int i = 9;i>=0;i--) {
        sum[i]+=sum[i+1]+ar[i];
    }
    ll ans = 0;
    SET(dp);

    for(int i = 1;i<=n;i++){
        ans+=go(0,i);
        ans%=M;
    }
    printf("%lld\n",ans);
    return 0;
}