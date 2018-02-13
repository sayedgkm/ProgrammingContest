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

struct info{
   ll a,b,c;
   ll diff ;
}ar[N];
bool cmp(info x,info y) {
   return x.diff>y.diff;
}
ll sum = 0;
ll k = 0;
ll n ;
 vector<ll> x,y;
ll go(ll bam) {
  ll dan = sum- bam;
   bam*=k;
   dan*= k;
   ll l=0,r=0;
   ll tot = 0;
  x.clear();
  y.clear();

   FOR(i,0,n) {
     if(ar[i].b>ar[i].c){
        l+=ar[i].a;
        tot+=ar[i].b*ar[i].a;
        x.pb(i);
     } else {
         r+=ar[i].a;
         tot+= ar[i].c*ar[i].a;
         y.pb(i);
     }
   }
   if(l>bam) {
       for(int i = x.size()-1;i>=0;i--) {
           ll kom = ar[x[i]].a;
            ll mn = min(kom,l-bam);
            if(mn==0)  break;
            tot-=ar[x[i]].b*mn;
            tot+=ar[x[i]].c*mn;
            l-=mn;
       }

   }
   if(r>dan){
     for(int i = y.size()-1;i>=0;i--) {
           ll kom = ar[y[i]].a;
            ll mn = min(kom,r-dan);
            if(mn==0)  break;
            tot-=ar[y[i]].c*mn;
            tot+=ar[y[i]].b*mn;
            r-=mn;
       }
   }
   return tot;
}
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);

      n = lxt();
      k = lxt();

     FOR(i,0,n) {
         ar[i].a = lxt();
         ar[i].b = lxt();
         ar[i].c = lxt();
         ar[i].diff = labs(ar[i].b-ar[i].c) ;
         sum+=ar[i].a;
     }
     sort(ar,ar+n,cmp) ;
      sum=(sum+k-1)/k;
      ll lo = 0;
      ll hi = sum;

 while(lo < hi) {      /// ternery search on integer
    ll mid = (lo + hi) >> 1;
    if(go(mid) > go(mid+1)) {
        hi = mid;
    }
    else {
        lo = mid+1;
    }
 }
 cout<<go(lo)<<endl;
return 0;
}