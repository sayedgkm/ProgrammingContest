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
#define        N                               1010
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
int ar[N],br[N];
vector<int> adj[N];
vector<int> v[N];  int id;
int color[N];
void dfs(int u,int id){
       v[id].pb(u); color[u]=1;
       for(auto it: adj[u]){
           if(!color[it])
               dfs(it,id);
       }
}

ll dp[N][N];
ll go(int pos,int w){
    if(pos>=id) {
         return 0;
    }
    if(dp[pos][w]!=-1) return dp[pos][w];
     ll res=0;
    res=max(res,go(pos+1,w));
    for(int i=0;i<v[pos].size();i++){
            if(w>=ar[v[pos][i]])
        res=max(res,go(pos+1,w-ar[v[pos][i]])+br[v[pos][i]]);
    }

    ll tempa=0,tempb=0;
    for(int i=0;i<v[pos].size();i++){
         tempa+=ar[v[pos][i]];
         tempb+=br[v[pos][i]];
    }
    if(w>=tempa)
    res=max(res,go(pos+1,w-tempa)+tempb);

  return dp[pos][w]=res;
}
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int n=nxt(),m=nxt(),w=nxt();

   for(int i=1;i<=n;i++)
         ar[i]=nxt();
   for(int i=1;i<=n;i++)
         br[i]=nxt();
   for(int i=0;i<m;i++){
     int a=nxt(),b=nxt();
     adj[a].pb(b);
     adj[b].pb(a);
   }
       id=0;
     for(int i=1;i<=n;i++){
          if(!color[i]){
              dfs(i,id);
              id++;
          }
     }
    SET(dp);
        cout<<go(0,w)<<endl;

return 0;
}