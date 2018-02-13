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
#define        N                               200010
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
pll ar[N];
int go(ll mid,int n){

    for(int i=0;i<n;i++){

       if(ar[i].ss==2){
         if(mid>=1900) return 2;
         else mid+=ar[i].ff;
       } else {
          if(mid<1900) return 1;
          else mid+=ar[i].ff;
       }
    }
  return 3;
}
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int n=nxt();
   for(int i=0;i<n;i++){
     ar[i].ff=lxt();
     ar[i].ss=lxt();
   }
   ll b=-inf,e=(ll)inf; bool ok=false; ll ans=0;
    //cout<<go(1900,n)<<endl;
   while(b<=e){
    ll mid=(b+e)/2;
     int x=go(mid,n);
       if(x==3){
         b=mid+1;
         ans=b;
          ok=true;
       } else if(x==2){
          e=mid-1;
        } else b=mid+1;
        // cout<<b<<" "<<e<<endl;
     }
     if(ok&&ans<(ll)inf){

        for(int i=0;i<n;i++){
             ans+=ar[i].ff;
        }
        cout<<ans-1<<endl;
     }else if(b>=inf){
        puts("Infinity");
     } else {
        puts("Impossible");
     }
return 0;
}