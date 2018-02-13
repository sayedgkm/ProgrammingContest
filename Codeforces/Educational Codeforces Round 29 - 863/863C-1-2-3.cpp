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
#define        inf                              1e9
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
int ar[4][4];
int br[4][4];
int x,y;
pii go(int a,int b) {
   if(a==1&&b==3) return {1,0};
   if(a==3&&b==1) return {0,1};
   if(a==b) return {0,0};
   if(a>b) return {1,0};
   return {0,1};
}
int go(ll n) {
     int a = 0 ;
     int b = 0;
     FOR(i,1,n+1) {
          pii tm = go(x,y);
          a+=tm.ff;
          b+=tm.ss;
          int nx = ar[x][y];
          int ny = br[x][y];
          x = nx;
          y = ny;
     }
  cout<<a<<" "<<b<<endl;
  exit(0);
}
pii sum[N];
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
     ll n = lxt();
    x = nxt();
     y = nxt();
     FOR(i,1,4) FOR(j,1,4) ar[i][j] = nxt();
     FOR(i,1,4) FOR(j,1,4) br[i][j] = nxt();
     if(n<=1000) {
          go(n);
     } else {
          map<pii,int> mp;
           int l ,r ;
        for(int i = 1;i<=n;i++){
              pii tmp = go(x,y);
               if(mp[{x,y}]){
                   l = mp[{x,y}];
                   r = i-1;
                break;
               }
              mp[{x,y}]=i;
            sum[i].ff+=sum[i-1].ff+tmp.ff;
            sum[i].ss+=sum[i-1].ss+tmp.ss;
            int nx = ar[x][y];
            int ny = br[x][y] ;
            x= nx;
            y = ny;
        }
        ll a = 0 ;
        ll b = 0 ;
        a+=sum[l-1].ff;
        b+=sum[l-1].ss;
        ll tx = sum[r].ff-sum[l-1].ff;
        ll ty = sum[r].ss-sum[l-1].ss;
        ll sz = r-l+1;
        n-=(l-1);
        ll res = n/sz;
        ll rem = n%sz;
        a+=tx*res;
        b+=ty*res;
        a+=sum[l+rem-1].ff-sum[l-1].ff;
        b+=sum[l+rem-1].ss-sum[l-1].ss;

        cout<<a<<" "<<b<<endl;
     }
return 0;
}