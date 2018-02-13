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
struct info{
  int f,s,id;
}ar[N];
bool cmp(info x,info y){
 return x.f<y.f;}
 int dp[N];
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);

     int n=nxt();
     int w=nxt(),h=nxt();
     int x=0;
     for(int i=0;i<n;i++){
         info temp;
         temp.f=nxt();
         temp.s=nxt();
         temp.id=i+1;
         if(temp.f>w&&temp.s>h) ar[x++]=temp;
     }
     sort(ar,ar+x,cmp);

     for(int i=0;i<x;i++){
            dp[i]=1;
         for(int j=0;j<i;j++){
            if(ar[i].f>ar[j].f&&ar[i].s>ar[j].s) dp[i]=max(dp[i],dp[j]+1);
         }
     }
      int mx=0;
     for(int i=0;i<x;i++) mx=max(mx,dp[i]);
      int last=-1; vector<int>v;
     for(int i=x-1;i>=0;i--){
         if(dp[i]==mx){
            if(last==-1){
                last=i;
                v.pb(ar[i].id);
                mx--;
            } else if(ar[last].f>ar[i].f&&ar[last].s>ar[i].s){
                 v.pb(ar[i].id);
                 last=i;
                 mx--;
            }
         }

     }
cout<<v.size()<<endl;
for(int i=v.size()-1;i>=0;i--) printf("%d ",v[i]);

return 0;
}