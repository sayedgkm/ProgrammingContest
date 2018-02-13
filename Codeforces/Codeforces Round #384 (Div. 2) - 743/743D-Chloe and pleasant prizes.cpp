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
#define        N                               200010
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
vector<int> adj[N];
ll prize[N];
ll mx[N];
bool color[N]; ll res=LLONG_MIN;
void dfs(int u){
      color[u]=1;
      mx[u]=LLONG_MIN;
      ll x,y;
      x=y=LLONG_MIN;
      for(auto v:adj[u]){
          if(!color[v]){
              dfs(v);
              prize[u]+=prize[v];
              mx[u]=max(mx[u],mx[v]);
              //cout<<mx[v]<<" "<<u<<endl;
              if(mx[v]>=x){
                  y=x;
                  x=mx[v];
                } else {
                  y=max(y,mx[v]);
                }
             //cout<<u<<" "<<x<<" "<<y<<endl;
          }
        }
      mx[u]=max(mx[u],prize[u]);
    if(x>LLONG_MIN&&y>LLONG_MIN) res=max(res,x+y);
}

int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int n=nxt();
   for(int i=1;i<=n;i++){
      prize[i]=lxt();
   }
     for(int i=0;i<n-1;i++){
          int a=nxt(),b=nxt();
          adj[a].pb(b);
          adj[b].pb(a);
     }

       dfs(1);
       if(res==LLONG_MIN){
         puts("Impossible");
       } else cout<<res<<endl;

return 0;
}