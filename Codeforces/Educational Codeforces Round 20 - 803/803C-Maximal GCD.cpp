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
int ar[N]; ll n;
bool series(ll st,ll k){
   ll a=st;
   ll d=st;
   ll sum=2*a+(k-1)*d;
   sum=sum*k;
   sum/=2;
   if(sum<0) return false;
   if(sum<=n) return true;
   return false;
}
vector<ll> res;
int main()
{
#ifdef sayed
    // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
     n=lxt();
    ll k=lxt();
    if(k>1000000||k*(k+1)/2LL>n){
         cout<<-1<<endl;
         return 0;
    }
  vector<ll> v;
  for(ll i=1;i*i<=n;i++){
      if(n%i==0) {
         v.pb(i);
        if(i*i==n) continue;
         v.pb(n/i);
      }
  }
  sort(ALL(v));
  ll ans=-1;
   for(int i=v.size()-1;i>=0;i--){
        ll val=v[i];
        if(series(val,k)) {
         ans=val;
          break;
        }

   }
   if(ans==-1) {
    cout<<-1<<endl;
    return 0;
   }
   ll sum=0;
   for(ll i=0;i<k;i++){
      sum+=ans*(i+1);
      res.pb(ans*(i+1));
      //debug(sum);
     // debug(ans*(i+1));
   }

   res.back()+=(n-sum);
   FOR(i,0,k) cout<<res[i]<<" ";
    return 0;
}