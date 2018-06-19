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
#define        N                               205033
#define        M                               100000007
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
vector<ll> v;
ll limit = (10e10)+ 1000;
void go(ll cur,ll mul) {
   if(cur>=limit) return;
   v.pb(cur);
   go(cur*mul,mul);

}
ll fac[N], finv[N];
pll extendedEuclid(ll a, ll b) { /// returns x,y where ax+by=gcd(a,b)
    if (b == 0)
        return pll(1, 0);
    else {
        pll d = extendedEuclid(b, a % b);
        return pll(d.ss, d.ff - d.ss * (a / b));
    }
}
ll modularInverse(ll a, ll n) { /// returns a^-1%n
    pll ret = extendedEuclid(a, n);
    return ((ret.ff % n) + n) % n;
}
void gen(){
    fac[0] = 1;
    for (ll i=1; i<N; i++) fac[i] = (i * fac[i-1]) % M;
    finv[N-1] = modularInverse(fac[N-1], (ll)M);
    for (ll i=N-2; i>=0; i--) finv[i] = (finv[i+1] * (i+1)) % M;
}

ll catalan(int n){
    if(n==0) return 0;
    return (((fac[2*n] * finv[n+1]) % M) * finv[n]) % M;
}
int main(){
    #ifdef sayed
     freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   FOR(i,2,1e5+1) {
        go((ll)i*i,i);
   }
   sort(ALL(v));
   v.erase(unique(ALL(v)),v.end());
       gen();
   int test = nxt();
   int cs =1 ;
   while(test--){

      ll a= lxt();
      ll b = lxt();
    //  if(a>b) swap(a,b);
          int l = lower_bound(ALL(v),a)-v.begin();
          int r = upper_bound(ALL(v),b)-v.begin();
          r--;
          printf("Case %d: %lld\n",cs++,catalan(r-l+1));

   }

return 0;
}


