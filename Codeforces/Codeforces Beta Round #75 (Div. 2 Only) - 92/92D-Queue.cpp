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
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T on(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%I64d",&aaa);return aaa;}
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
int table[N][20];
int p[N];
void RMQ_init(int n){

    for(int i=0;i<n;i++)
       table[i][0] = ar[i];
    for(int i=2;i<=n;i++) p[i]=1+p[i/2];
 for(int len = 1;(1<<len)<=n;len++)
     for(int i=0;(i+(1<<len))<=n;i++)
    table[i][len] = min(table[i][len-1],table[i+(1<<(len-1))][len-1]);

}
int getmin(int i,int j){
    int k = p[j-i+1];
 return min(table[i][k],table[j-(1<<k)+1][k]);
}
int go(int b,int e,int key){

  while(b<=e){
    int mid=(b+e)>>1;
      if(getmin(mid,e)<key) b=mid+1;
      else e=mid-1;
  }
  return b-1;
}
int main(){
     // freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   // cin.tie(0);
   int n=nxt();
   f(i,0,n)ar[i]=nxt();
      RMQ_init(n);
   for(int i=0;i<n;i++){
     int ans=go(i,n-1,ar[i]);
     printf("%d ",ans<=i?-1:ans-i-1);
   }
 puts("");
return 0;
}