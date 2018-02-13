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
int ar[N];
vector<int> v;
ll dp[65][1025][2][2][11];
ll go(int pos,int mask,int isstart,int issmall,int base) {
      if(pos<0){
        return isstart&(mask==0);
      }
     ll &res = dp[pos][mask][isstart][issmall][base];

      if(res!=-1&&issmall) return res ;
      res = 0 ;
       int limit = v[pos];
       if(issmall) limit = base-1;
      FOR(i,0,limit+1) {
          res+=go(pos-1,(isstart|i)?(mask^(1<<i)):mask,isstart|i>0,issmall|i<v[pos],base);
      }
      return res;
}
ll solve(ll x,ll base) {
    v.clear();
   while(x) {
      v.pb(x%base) ;
      x/= base;
    }
    //reverse(ALL(v));
    return go(v.size()-1,0,0,0,base);
}
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   SET(dp) ;

   int test = nxt();
   while(test -- ) {

       int base = nxt();
       ll a = lxt();
       ll b = lxt() ;
       printf("%lld\n",solve(b,base)-solve(a-1,base));
   }

return 0;
}