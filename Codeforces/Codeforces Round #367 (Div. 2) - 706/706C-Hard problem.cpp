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
ll dp[N][3];
string s[N];
string rev[N];
int val[N]; int n;
int ans = inf;int flag=0;
ll go(int pos, int last){
 if (pos > n){
            flag=1;
  return 0;
 }
 if(dp[pos][last]!=-1) return dp[pos][last];
 string p = s[pos - 1];
 string q = rev[pos-1];
 string m = rev[pos];
 ll x = 1000000000000000000;// y = inf;
 if (!last){

  if (s[pos] >= p){
   x =(x,go(pos + 1, 0));
  }

     if (m >= p){
   x=min(x, go(pos + 1, 1) + val[pos]);
  }

 }
 else {
  if (s[pos] >= q){
   x= min(x,go(pos + 1, 0));
  }

    if (m >= q){
   x = min(x,go(pos + 1, 1) + val[pos]);
  }


 }
 return dp[pos][last]=x;


}
char str[N];
int main(){
 //freopen("out.txt","w",stdout);
 //ios_base::sync_with_stdio(false);
 //cin.tie(0);
 SET(dp);
 n = nxt();
 f(i, 1, n + 1) val[i] = nxt();
 f(i, 1, n + 1) {
   scanf("%s",str);
   s[i]=rev[i]=str;
   reverse(rev[i].begin(),rev[i].end());
 }
 ll ans=go(1,0);
 if(!flag) puts("-1");
 else
 cout <<ans<< endl;
 return 0;
}