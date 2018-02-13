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
inline int lxt(){ll aaa;scanf("%lld",&aaa);return aaa;}
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
int a[N];
int br[N];
bool color[N];
vector<int>v,v1;
void dfs(int u,int p){
  v.pb(u);
  color[u]=1;
  for(int i=0;i<adj[u].size();i++){
      int v=adj[u][i];
      if(v==p) continue;
    if(!color[v]) dfs(v,u);
  }

}
int main(){
     // freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   // cin.tie(0);
   int n=nxt();
   int m=nxt();
   for(int i=1;i<=n;i++) a[i]=nxt();
   f(i,0,m) {
    int a=nxt();
    int b=nxt();
    adj[a].pb(b);
    adj[b].pb(a);
   }
 for(int i=1;i<=n;i++){
    if(color[i]) continue;
     dfs(i,-1);
     if(v.size()<=1){
         v.clear();
         continue;
     }

     for(auto it: v)
          v1.pb(a[it]);
      sort(v.begin(),v.end());
      sort(v1.begin(),v1.end());
      reverse(v1.begin(),v1.end());
          for(int j=0;j<v.size();j++) br[v[j]]=v1[j];
          v.clear();
          v1.clear();
}
 for(int i=1;i<=n;i++)
    if(!br[i]) br[i]=a[i];
 f(i,1,n+1) printf("%d ",br[i]);
return 0;
}