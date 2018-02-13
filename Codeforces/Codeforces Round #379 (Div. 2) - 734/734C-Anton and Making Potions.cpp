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
pll a[N], b[N];
ll ar[N];
bool cmp(pll x,pll y){
  return x.ss<y.ss;
}
int go(int b,int e,int val){

    while(b<=e){
        int mid=(b+e)>>1;
        if(a[mid].ss<=val) b=mid+1;
        else e=mid-1;
    }
    return b-1;

}
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   ll n=lxt(),m=lxt(),k=lxt();
   ll x=lxt(),s=lxt();

   for(int i=0;i<m;i++){
      a[i].ff=lxt();
   }
   for(int i=0;i<m;i++){
      a[i].ss=lxt();
   }
   for(int i=0;i<k;i++){
      b[i].ff=lxt();
   }
   for(int i=0;i<k;i++){
      b[i].ss=lxt();
   }
   sort(a,a+m,cmp);
   ar[0]=a[0].ff;
   for(int i=1;i<m;i++) ar[i]=min(ar[i-1],a[i].ff);
   ll ans=n*x; ll portion;
   for(int i=0;i<k;i++){
       if(b[i].ss<=s){
           ll tempk=s-b[i].ss;
            portion=n-b[i].ff;
          int xx =go(0,m-1,tempk);
          if(xx>=0){
          ll mn=ar[xx];
          //cout<<tempk<<" "<<portion<<" "<<xx<<" "<<mn<<endl;
          ans=min(ans,portion*mn);
          }
          ans=min(ans,portion*x);
       }


   }
   //cout<<ans<<endl;
   int xx=go(0,m-1,s);
   if(xx>=0){

      ans=min(ans,n*ar[xx]);
   }
  cout<<ans<<endl;
return 0;
}
/*
20 3 2
10 99
2 4 3
20 10 40
4 15
1 1
*/