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
#define        N                               100010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
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
inline ll lxt(){ll aaa;scanf("%I64d",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
///******************************************START******************************************
ll ar[N],br[N];
ll go(int x,int y,int p){
     return y/p-(x-1)/p;
}
int main()
{
#ifdef sayed
    // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
     int n=nxt();
     int p=nxt();
     FOR(i,0,n) ar[i]=lxt(),br[i]=lxt();
     double ans=0;
     FOR(i,1,n){
         double x=br[i-1]-ar[i-1]+1;
         double y=br[i]-ar[i]+1;
         double down=x*y;
         double div=0;
         double tot=go(ar[i-1],br[i-1],p);
         div+=tot*y;
          x-=tot;
         tot=go(ar[i],br[i],p);
         div+=x*tot;
         ans+=(div/down)*(2000.0);
  }
         double x=br[0]-ar[0]+1;
         double y=br[n-1]-ar[n-1]+1;
         double down=x*y;
         double div=0;
         double tot=go(ar[0],br[0],p);
         div+=tot*y;
          x-=tot;
         tot=go(ar[n-1],br[n-1],p);
         div+=x*tot;

         ans+=(div/down)*(2000.0);
         cout<<setprecision(20)<<fixed<<ans<<endl;
    return 0;
}