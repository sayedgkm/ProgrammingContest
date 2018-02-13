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
pair<double,double> ar[N];
int n;
double ax,ay,bx,by,rx,ry;

long double go(double x1,double y1 ,double x2,double y2 ) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
long double sum;
long double dp[N][2][2];
long double go(int pos,int adil,int bera) {
    if(pos==n) {
        if(adil||bera) return sum;
        return (long double) 1e18;
    }

    long double &res = dp[pos][adil][bera];
    if(res!=-1) return res;
    res = (long double) 1e18;
    res = min(res,go(pos+1,adil,bera));
    if(adil==0) {
       res = min(res,go(pos+1,1,bera)-go(rx,ry,ar[pos].ff,ar[pos].ss)+go(ax,ay,ar[pos].ff,ar[pos].ss));
    }
    if(bera==0)
        res = min(res,go(pos+1,adil,1)-go(rx,ry,ar[pos].ff,ar[pos].ss)+go(bx,by,ar[pos].ff,ar[pos].ss));
    return res;

}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    for(int i = 0;i<N;i++) FOR(j,0,2) FOR(k,0,2) dp[i][j][k] = -1;
    ax = dxt(),ay = dxt(),bx = dxt(),by = dxt(),rx = dxt(),ry = dxt();
    n = nxt();
    for(int i = 0;i<n;i++) {
        ar[i].ff = dxt();
        ar[i].ss = dxt();
        sum+= go(rx,ry,ar[i].ff,ar[i].ss)*2.0;
    }
    cout<<setprecision(20)<<fixed<<go(0,0,0)<<endl;
    return 0;
}