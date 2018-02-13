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
#define        N                               110
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (ll)1e15
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T on(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%I64d",&aaa);return aaa;}
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
 int ar[N];
 int p[N][N];
 ll dp[N][N][N];
 int n,m,k; bool f=false;
ll go(int pos,int prev,int k){
     //cout<<pos<<" "<<prev<<" "<<k<<endl;
     if(pos>n) {
      if(k==0)
        {
            f=true;
            return 0;
        }
       else return inf;
     }
     if(dp[pos][prev][k]!=-1) return dp[pos][prev][k];
    ll x=inf,y=inf;
  for(int i=1;i<=m;i++){
      if(ar[pos]){
        if(ar[pos]!=prev)
             x=go(pos+1,ar[pos],k-1);
        else x=go(pos+1,ar[pos],k);
      } else  {
         if(i==prev) x=go(pos+1,i,k)+p[pos][i];
         else x=go(pos+1,i,k-1)+p[pos][i];
      }
        y=min(y,x);

    }

   return dp[pos][prev][k]=y;
 }
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   SET(dp);
   n=nxt(); m=nxt(),k=nxt();
   f(i,1,n+1) ar[i]=nxt();
   f(i,1,n+1) f(j,1,m+1) p[i][j]=nxt();
   ll ans=go(1,0,k);
   if(f)
   cout<<ans<<endl;
   else puts("-1");

return 0;
}