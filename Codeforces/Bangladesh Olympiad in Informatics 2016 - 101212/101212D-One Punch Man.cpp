//==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long int
#define        f(x,y,z)                        for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               100010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
#define        eps                              1e-9
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T ison(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%I64d",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
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
pii ar[N]; int n,r;
ll sum[N];int nxtpos[N];
int upper(int b,int e,int val){
   while(b<=e){
      int mid=(b+e)/2;
      if(ar[mid].ff<=val) b=mid+1;
      else e=mid-1;
    }
   return b;
}
ll dp[N][55];
ll go(int pos,int k){
   if(pos>n) return 0;
    if(dp[pos][k]!=-1) return dp[pos][k];
   ll res=0;
    if(k){
        int np=nxtpos[pos];
        res=max(res,(go(np,k-1)+sum[np-1]-sum[pos-1]));
    }
    res=max(res,go(pos+1,k));
    return dp[pos][k]=res;

}
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
  int test=nxt();
  int cs=1;
  while(test--){
     n=nxt(),r=nxt();int k=nxt();
     for(int i=1;i<=n;i++){
         ar[i].ff=nxt();
         ar[i].ss=nxt();

     }
     r=r*2;
     sort(ar+1,ar+n+1);
     for(int i=1;i<=n;i++) sum[i]+=sum[i-1]+ar[i].ss;
     for(int i=1;i<=n;i++){
        nxtpos[i]=upper(i,n,ar[i].ff+r);
     }
     SET(dp);
     ll ans=go(1,k);
     printf("Case %d: %I64d\n",cs++,ans);
    CLR(ar);
    CLR(sum);
    CLR(nxtpos);

  }
return 0;
}