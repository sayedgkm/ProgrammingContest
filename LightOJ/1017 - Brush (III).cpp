// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long
#define        f(x,y,z)                        for(int x=y;x<z;x++)
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
#define        inf                             (int)1e9
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%lld",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
#define sayed
#ifdef sayed
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif
struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///******************************************START******************************************
int dp[105][105];
int ar[105];
int n,k,w;
int go(int i,int moves){
     if(i>=n) return 0;
     if(moves>k) return 0;
     if(dp[i][moves]!=-1) return dp[i][moves];
     int d1=0,d2=0,ans=0;
     int j=upper_bound(ar,ar+n,ar[i]+w)-ar;
     d1=go(j,moves+1)+(j-i);
    d2=go(i+1,moves);
    ans=max(d1,d2);
    return dp[i][moves]=ans;

}
int main()
{
    ///ios_base::sync_with_stdio(0); cin.tie(0);
    /// freopen("out.txt","w",stdout);
    int test=nxt();
    int cs=1;
    while(test--){
            SET(dp);
       n=nxt(); w=nxt();k=nxt();
       f(i,0,n){
         int a=nxt();
         ar[i]=nxt();
       }
      sort(ar,ar+n);
      printf("Case %d: %d\n",cs++,go(0,1));
    }


      return 0;
}


