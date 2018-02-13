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
map<pll,ll> mp;
map<ll,bool> ok;
ll lca(unsigned ll a,unsigned ll b){
    ok.clear();
  ll p=0;
  ok[a]=true;
   while(a!=1){
        a=a/(ll)2;
    ok[a]=true;

   }
   if(ok[b]==true) return b;
   while(b!=1){
     b=b/(ll)2;
    if(ok[b]==1) return b;

   }
}
int main(){
     // freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   // cin.tie(0);
   int n=nxt();
   while(n--){
     int c=nxt();
     if(c==1){
        ll a=lxt(),b=lxt(),w=lxt();
        ll parent=lca(a,b);
        ll p=1;
        while(a!=parent){
            ll x=a/(ll)2;
            mp[pll(a,x)]+=w;
            mp[pll(x,a)]+=w;
            p++;
            a=x;
        }
        p=1;
        while(b!=parent){
            ll x=b/(ll)2;
            mp[pll(b,x)]+=w;
            mp[pll(x,b)]+=w;
            b=x;
            p++;

        }

     } else {

       ll a=lxt(),b=lxt();
       ll parent=lca(a,b);
       ll sum=0;
        ll p=1;
        while(a!=parent){
            ll x=a/(ll)2;
            sum+=mp[pll(a,x)];
            a=x;
            p++;
        }
        p=1;
        while(b!=parent){
            ll x=b/(ll)2;
            sum+=mp[pll(b,x)];
            b=x;
            p++;

        }
       printf("%I64d\n",sum);

     }


   }

return 0;
}