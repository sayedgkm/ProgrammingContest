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
pii ar[N];
int n;
int dp[3][101][10001];
int go(int pos,int c,int sum) {
    if(c==0) {
        if(sum <= 0) return 0;
        return inf;
    }
    if(sum<=0) return inf;
    if(pos<0) return inf;
    return dp[pos][c][sum];
    int res = inf;
    res = min(res,go(pos-1,c,sum));
    res = min(res,go(pos-1,c-1,sum-ar[pos].ff)+min(sum-ar[pos].ss,ar[pos].ff-ar[pos].ss));
    return res;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    n = nxt();
    int tot = 0;
    FOR(i,0,n) {
        ar[i].ss = nxt();
        tot+=ar[i].ss;
    }
    for(int i = 0;i<n;i++){
        ar[i].ff = nxt();
    }
    sort(ar,ar+n) ;
    reverse(ar,ar+n);
    int c = 0;
    int sum = tot;
    for(int i = 0;i<n;i++) {
        if(tot<=0) {
            break;
        }
        tot-=ar[i].ff;
        c++;
    }
    int cur = 0;
    int prev = 1;
    for(int  i = 0;i<=c;i++){
        for(int j = 0;j<=sum;j++){
            dp[0][i][j] = inf;
        }
    }
    for(int i = 0;i<n;i++) {
        swap(cur,prev);
        for(int j = 0;j<=c;j++) {
            for(int k  = 0;k<=sum;k++) {
                dp[cur][j][k] = min(go(prev,j,k),go(prev,j-1,k-ar[i].ff)+min(k-ar[i].ss,ar[i].ff-ar[i].ss));
            }
        }
    }
    cout<<c;
    cout<<" " <<dp[cur][c][sum]<<endl;


    return 0;
}