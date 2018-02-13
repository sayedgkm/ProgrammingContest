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
int ar[500][500];
int dp[301][301][301];
int n;
int go(int i1,int j1,int i2){
    if(i1==n-1&&j1==n-1&&i2==n-1) {
        return ar[i1][j1];
    }
    int &res = dp[i1][j1][i2];
    int j2 = i1+j1-i2;
    if(res!=-1) return res;
    res = -inf;
    if(i1+1<n&&i2+1<n) {
        res = max(res,go(i1+1,j1,i2+1)+ar[i1][j1]+ar[i2][j2]*(!(i2==i1&&j2==j1)));
    }
    if(j1+1<n&&j2+1<n) {
        res = max(res,go(i1,j1+1,i2)+ar[i1][j1]+ar[i2][j2]*(!(i2==i1&&j2==j1)));
    }
    if(i1+1<n&&j2+1<n) {
        res = max(res,go(i1+1,j1,i2)+ar[i1][j1]+ar[i2][j2]*(!(i2==i1&&j2==j1)));
    }
     if(j1+1<n&&i2+1<n) {
        res = max(res,go(i1,j1+1,i2+1)+ar[i1][j1]+ar[i2][j2]*(!(i2==i1&&j2==j1)));
    }

    return res;
}
//void path(int i ,int j) {
//    if(i==n-1&&j==n-1) {
//        ar[i][j] = 0;
//        return;
//    }
//    int res = go(i,j);
//    if(i+1<n&&go(i+1,j)+ar[i][j]==res) {
//        ar[i][j] = 0;
//        path(i+1,j);
//    } else {
//        ar[i][j] = 0;
//        path(i,j+1);
//    }
//}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
     n = nxt();
    for(int i = 0;i<n;i++) for(int j = 0;j<n;j++) ar[i][j] = nxt();
    SET(dp);
    int res = go(0,0,0);
    printf("%d\n",res);
    return 0;
}