// ==========================================================================
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
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
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
int ar[N];
int br[N];
bool ok(ll cookies,ll k,int n){
   ll sum=0;
   f(i,0,n){
     if(cookies*(ll)ar[i]>br[i]) sum+=cookies*(ll)ar[i]-br[i];
   }
     if(sum<0) return false;
   return k>=sum;
}
int main()
{
    ///ios_base::sync_with_stdio(0); cin.tie(0);
    /// freopen("out.txt","w",stdout);
    int n=nxt(),k=nxt();
    f(i,0,n) ar[i]=nxt();
    f(i,0,n) br[i]=nxt();
    ll b=0,e=(ll)5e9,mid;
    while(b<=e){
        mid=(b+e)>>1;
        if(ok(mid,k,n))
            b=mid+1;
        else  e=mid-1;
     }
     cout<<b-1<<endl;


      return 0;
}