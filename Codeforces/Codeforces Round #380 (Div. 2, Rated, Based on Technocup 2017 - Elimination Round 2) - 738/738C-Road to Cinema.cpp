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
int n,k,s,t;
int br[N];
pii ar[N];
bool go(int tel){

    int Time=0;
    for(int i=1;i<=k;i++){

        int dist=br[i]-br[i-1];
        if(tel<dist) return false;
        int x=max(dist,dist*2-(tel-dist));
        Time+=x;
    }
    if(Time<=t) return true;
    return false;

}
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   n=nxt(),k=nxt(),s=nxt(),t=nxt();
   for(int i=0;i<n;i++){
    ar[i].ff=nxt();
    ar[i].ss=nxt();
   }
   for(int i=1;i<=k;i++){
       br[i]=nxt();
   }
   sort(br+1,br+k+1);
   k++;
   br[k]=s;
   int b=0,e=(int)inf+100;
   while(b<=e){
      int mid=(b+e)>>1;
      if(go(mid)) e=mid-1;
      else b=mid+1;

   }
   int ans=inf+100;
   for(int i=0;i<n;i++){
      if(b<=ar[i].ss) ans=min(ans,ar[i].ff);
   }
   if(ans==inf+100) puts("-1");
   else printf("%d\n",ans);
return 0;
}