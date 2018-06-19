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
#define        N                               1000010
#define        M                               100000007
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
int coin[105];
int freq[105];
int dp[55][1005];
int n;
ll go(int pos,int sum){
    if(sum==0) return 1;
     if(sum<0) return 0;
    if(pos>=n) return 0;
    if(dp[pos][sum]!=-1) return dp[pos][sum];
    ll p=0;
   for(int i=0;i<=freq[pos];i++){
     p=(p+go(pos+1,sum-coin[pos]*i))%M;
   }
  return dp[pos][sum]=p;
}
ll go(int pos,int sum,int x){
    dp[0][0]=1;
   for(int i=1;i<=n;i++){
     for(int j=0;j<=freq[i-1];j++){
         for(int k=0;k<=sum;k++){
           if(k>=coin[i-1]*j)
             dp[i][k]=(dp[i][k]+dp[i-1][k-coin[i-1]*j])%M;

         }
        }
   }
  return dp[pos][sum]%M;
}
int main()
{
    ///ios_base::sync_with_stdio(0); cin.tie(0);
    /// freopen("out.txt","w",stdout);
 int test=nxt();
   int cs=1;
   while(test--){
       CLR(dp);
    n=nxt();int k=nxt();
    f(i,0,n) coin[i]=nxt();
    f(i,0,n) freq[i]=nxt();
    printf("Case %d: %lld\n",cs++,go(n,k,0));
   }

      return 0;
}



