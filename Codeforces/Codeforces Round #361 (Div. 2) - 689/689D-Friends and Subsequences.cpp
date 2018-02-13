//==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long
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
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T on(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
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
int ar[N],br[N];
int table[N][20],table1[N][20];
int Log[N];
void RMQ_init(int n){
   for(int i=0;i<n;i++){
      table[i][0]=ar[i];
      table1[i][0]=br[i];
   }
   for(int i=2;i<=n;i++) Log[i]=Log[i/2]+1;
   for(int j=1;(1<<j)<=n;j++){
     for(int i=0;i+(1<<j)<=n;i++){
        table[i][j]=max(table[i][j-1],table[i+(1<<(j-1))][j-1]);
        table1[i][j]=min(table1[i][j-1],table1[i+(1<<(j-1))][j-1]);
     }

   }

}
 int getmax(int i,int j){
   int k=Log[j-i+1];
   return max(table[i][k],table[j-(1<<k)+1][k]);
 }
 int getmin(int i,int j){
   int k=Log[j-i+1];
   return min(table1[i][k],table1[j-(1<<k)+1][k]);
 }
 int Left(int i,int n){
     int b=i;int e=n-1;
    while(b<=e){
        int mid=(b+e)>>1;
        if(getmax(i,mid)<getmin(i,mid)) b=mid+1;
        else e=mid-1;

    }
   return b;
 }
 int Right(int i,int n){
  int b=i;int e=n-1;
    while(b<=e){
        int mid=(b+e)>>1;
        if(getmax(i,mid)<=getmin(i,mid)) b=mid+1;
        else e=mid-1;

    }
   return b;

 }
int main(){
     // freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   // cin.tie(0);
   int n=nxt();
   f(i,0,n) ar[i]=nxt();
   f(i,0,n) br[i]=nxt();
   RMQ_init(n);
  ll ans=0;
  f(i,0,n) ans+=Right(i,n)-Left(i,n);
  printf("%I64d\n",ans);
return 0;
}