//==========================================================================
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
#define        N                               2010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             9+100
#define        eps                             1e-9
#define        debug(x)                        cerr << #x << " is " << x << endl;
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
///******************************************START******************************************
ll ar[N];
ll br[N];
ll dp[N][N];
int n,k;
ll pos;
ll go(int x,int y){

       if(x>=n){
          return (ll)0;
       }

       if(y>=k) return (ll)1e16;
       if(dp[x][y]!=-1) return dp[x][y];
       ll res=0;
       ll res1=0;
      res=max(res,max(go(x+1,y+1),abs(ar[x]-br[y])+abs(br[y]-pos)));
      res1=max(res1,go(x,y+1));
//      debug(res);
//      debug(res1);
    //  if(res==0) res=(ll)1e16;
    //  if(res1==0) res1=(ll)1e16;
    return dp[x][y]=min(res,res1);
}
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
    SET(dp);
    n=nxt();
    k=nxt();
    pos=lxt();
    FOR(i,0,n) {
      ar[i]=lxt();
    }
    FOR(i,0,k){
        br[i]=lxt();
    }
    sort(ar,ar+n);
    sort(br,br+k);
    cout<<go(0,0)<<endl;
return 0;
}