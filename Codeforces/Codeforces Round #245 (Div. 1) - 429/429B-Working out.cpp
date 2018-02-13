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
#define        N                               1010
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
ll ar[N][N];
ll f1[N][N],f2[N][N],f3[N][N],f4[N][N];
int n,m;
void print(int x){
    puts("**************");
   for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
       if(x==1) cout<<f1[i][j]<<" ";
       if(x==2) cout<<f2[i][j]<< " ";
        if(x==3) cout<<f3[i][j]<<" ";
       if(x==4) cout<<f4[i][j]<< " ";
    }
    cout<<endl;
   }

 }
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   n=nxt(),m=nxt();
   for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        ar[i][j]=lxt();
    }
   }
   for(int i=1;i<=n;i++){
     for(int j=1;j<=m;j++){
        f1[i][j]=max(f1[i-1][j],f1[i][j-1])+ar[i][j];
     }
   }
   for(int i=n;i>=1;i--){
     for(int j=m;j>=1;j--){
         f2[i][j]=max(f2[i+1][j],f2[i][j+1])+ar[i][j];
     }
   }
   for(int i=n;i>=1;i--){
     for(int j=1;j<=m;j++){
        f3[i][j]=max(f3[i+1][j],f3[i][j-1])+ar[i][j];
     }
    }
    for(int i=1;i<=n;i++){
         for(int j=m;j>=1;j--){
            f4[i][j]=max(f4[i-1][j],f4[i][j+1])+ar[i][j];
         }
    }
    ll ans=0;
    for(int i=2;i<n;i++){
         for(int j=2;j<m;j++){
            ll val=f1[i][j-1]+f2[i][j+1]+f3[i+1][j]+f4[i-1][j];
            ans=max(ans,val);
            val=f1[i-1][j]+f2[i+1][j]+f3[i][j-1]+f4[i][j+1];
            ans=max(ans,val);

         }
    }
    cout<<ans<<endl;
return 0;
}