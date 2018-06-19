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
inline ll lxt(){ll aaa;scanf("%lld",&aaa);return aaa;}
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

string binaryString (ll number){
   string s;
   while(number){
    s+=(number%2)+'0';
    number/=2;
   }
  reverse(s.begin(),s.end());

  return s;
}
ll dp[35][35][2][2];string s;
ll go(int pos,int adj,int prev,int isSmall){
   // cout<<pos<<" "<<s.length()<<endl;
     if(pos>=s.length()){
        return adj;
     }
     if(dp[pos][adj][prev][isSmall]!=-1) return dp[pos][adj][prev][isSmall];
     ll res=0;
     int limit=isSmall?1:s[pos]-'0';
     for(int i=0;i<=limit;i++){
        if(prev==1&&i)
          res+=go(pos+1,adj+1,i,isSmall|i<(s[pos]-'0'));
        else res+=go(pos+1,adj,i,isSmall|i<(s[pos]-'0'));
     }
     return dp[pos][adj][prev][isSmall]=res;
}
int main(){
    //  freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   // cin.tie(0);

   int cs=1; int test=nxt();
   while(test--){
     SET(dp);
    ll n=lxt();
     s=binaryString(n);
      ll ans=go(0,0,0,0);
     printf("Case %d: %lld\n",cs++,ans);
   }

return 0;
}


