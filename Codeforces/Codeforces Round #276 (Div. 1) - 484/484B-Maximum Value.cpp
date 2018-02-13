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
#define        N                               1000010
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
vector<int> divisor[N];
int ar[N],br[2*(N+10)];
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
  int n=nxt(); int x=0;
  for(int i=0;i<n;i++){
         int a=nxt();
         if(br[a]==0) ar[x++]=a;
         br[a]=1;
  }
  CLR(br); int j=0;
   sort(ar,ar+x);
  for(int i=ar[0];i<2*(N+10);i++){
        while(ar[j]<i&&j<x-1){
             j++;
        }
        if(ar[j]>=i&&j) j--;
        br[i]=ar[j];
  }

    int mx=0;
    for(int i=0;i<x;i++){
            if(ar[i]==1) continue;
            int last=0;
         for(int j=ar[i]*2;j<N;j+=ar[i]){
                last=j;
               int in=br[last];
               mx=max(mx,in%ar[i]);
        }
        if(last==0){
             last=ar[i]*2;
        } else {
           last=((N+ar[i]-1)/ar[i])*ar[i];
          }
          mx=max(mx,br[last]%ar[i]);
    }
    cout<<mx<<endl;
return 0;
}