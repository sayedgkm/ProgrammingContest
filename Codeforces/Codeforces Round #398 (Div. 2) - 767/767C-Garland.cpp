//==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
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
#define        eps                             1e-9
#define        debug(x)                        cerr << #x << " is " << x << endl;
#define        ALL(x)                          x.begin(),x.end()
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
///******************************************START******************************************
int ar[N],br[N]; ll sum[N]; int s=0;
vector<int> adj[N];
int x,y;
int root; int start;
void dfs(int u,int p){
         sum[u]=ar[u];
       FOR(i,0,adj[u].size()){
          int v=adj[u][i];
          if(v==p) continue;
           dfs(v,u);
           sum[u]+=sum[v];
       }
    // cout<<u<<" "<<sum[u]<<endl;
     if(sum[u]==s&&x==-1){
       x=u;
       root=p;
       return;
     }
}
void dfsagain(int u,int p){
        sum[u]=ar[u];
       FOR(i,0,adj[u].size()){
          int v=adj[u][i];
          if(v==p) continue;
          if(u==root&&v==x) continue;
           dfsagain(v,u);
         sum[u]+=sum[v];
       }


     if(sum[u]==s&&y==-1&&u!=start){
       y=u;
       return;
     }
}
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
    x=-1;
    y=-1;
    root=-1;
   int n=nxt();  start;
   FOR(i,1,n+1){
       int a=nxt();
       int b=nxt();
       adj[i].pb(a);
       adj[a].pb(i);
       if(a==0) start=i;
       ar[i]=b; s+=b;
       sum[i]=b;
   }
   if(s%3) {
     puts("-1");
     return 0;
   }
   s/=3;
   dfs(start,0);
   if(x==-1) {
       puts("-1");
       return 0;
    }
   CLR(sum);
   dfsagain(start,0);

   if(y==-1) {
       puts("-1");
       return 0;
    }
    cout<<x<<" "<<y<<endl;
return 0;
}