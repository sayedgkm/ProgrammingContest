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
#define        N                               100010
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
inline ll lxt(){ll aaa;scanf("%lld",&aaa);return aaa;}
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
string s;
ll dp[15][15][2][2];
ll go(int pos,int cntZero,int isStart,int isSmall){
     if(pos>=s.length()){
        return cntZero;
     }
   if(dp[pos][cntZero][isStart][isSmall]!=-1) return dp[pos][cntZero][isStart][isSmall];
   ll res=0;
   int limit=isSmall?9:s[pos]-'0';
   for(int i=0;i<=limit;i++){
       if(isStart&&!i){
            res+=go(pos+1,cntZero+1,isStart,isSmall|i<(s[pos]-'0'));
       } else {
          res+=go(pos+1,cntZero,i?1:0,isSmall|i<(s[pos]-'0'));
       }

   }
  return  dp[pos][cntZero][isStart][isSmall]=res;
}
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   //SET(dp);
   //s="11";
   //cout<<go(0,0,0,0)<<endl;
   int test=nxt(); int cs=1;
   while(test--){
     SET(dp);
    ll a,b;a=lxt(),b=lxt();

     s=NumberToString(b);
     ll ans=go(0,0,0,0);
     if(!a) ans++;
     SET(dp);
     if(a) a--;
     s=NumberToString(a);
     ans-=go(0,0,0,0);
      printf("Case %d: %lld\n",cs++,ans);
   }


return 0;
}


