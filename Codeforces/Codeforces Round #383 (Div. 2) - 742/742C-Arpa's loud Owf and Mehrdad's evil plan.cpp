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
int ar[N];
int br[N];
int mat[200][200];
void  reset(int n){
   f(i,0,n+1) f(j,0,n+1) mat[i][j]=inf;
 }
void warshall(int n){
   f(k,1,n+1) f(i,1,n+1) f(j,1,n+1)
       if(mat[i][k]+mat[k][j]<mat[i][j]) mat[i][j]=mat[i][k]+mat[k][j];
}
ll go(ll a,ll b){
   return (a*b)/gcd(a,b);
}
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int n=nxt();
   reset(n);
   for(int i=1;i<=n;i++){
      mat[i][nxt()]=1;
   }
   warshall(n);

   ll lcm=1;

   for(int i=1;i<=n;i++){
       // cout<<mat[i][i]<<endl;
     if(mat[i][i]==inf) {
        puts("-1");
        return 0;
     }
    // if(mat[i][i]==0) mat[i][i]=1;
     lcm=go(lcm,mat[i][i]%2==0?mat[i][i]/2:mat[i][i]);
   }
   cout<<lcm<<endl;


return 0;
}