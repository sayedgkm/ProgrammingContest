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
vector<int>adj[N];
int table[N][32];  ///for sparse  table
int depth[N];     ///depth of each node from root
int parent[N];
int sz[N];
void dfs(int s,int p,int d){
       parent[s]=p;
       depth[s]=d;
       sz[s]=1;
      for(int i=0;i<adj[s].size();i++){
         int t=adj[s][i];
         if(t==p) continue;
          dfs(t,s,d+1);
          sz[s]+=sz[t];
      }


}
void lca_init(int n){
   SET(table);
   for(int i=1;i<=n;i++){
      table[i][0]=parent[i];
    }
    for(int j=1;(1<<j)<=n;j++){
         for(int i=1;i<=n;i++){
            table[i][j]=table[table[i][j-1]][j-1];
        }
    }

}
int lca_query(int n,int p,int q){  ///p && q are two nodes.
        if(depth[q]>depth[p])
              swap(p,q);
        int log=1;
        while((1<<log)<depth[p]) log++;
    for(int i=log;i>=0;i--){
           if(depth[p]-(1<<i)>=depth[q])  ///making same level of p and q
                  p=table[p][i];

        }
    if(p==q)
          return p;
    for(int i=log;i>=0;i--){
        if(!table[p][i]!=-1&&table[p][i]!=table[q][i])
               p=table[p][i],q=table[q][i];
    }
    return parent[p];

}
int getparent(int p,int d){

   for(int i=20;i>=0;i--){
       if(1<<i<=d){
          if(table[p][i]!=-1){
              d-=1<<i;
              p=table[p][i];

          }
       }

   }
  return p;

}
int main()
{
  //  ios_base::sync_with_stdio(0); cin.tie(0);
    /// freopen("out.txt","w",stdout);
    int n=nxt();
    f(i,0,n-1){
       int a=nxt();
       int b=nxt();
       adj[a].pb(b);
       adj[b].pb(a);
    }
    dfs(1,-1,0);
    lca_init(n);
    int q=nxt();
    while(q--){
        int x=nxt(),y=nxt();
        if(x==y){
            cout<<n<<endl;
            continue;
        }
        if(depth[x]<depth[y]) swap(x,y);
        int lca=lca_query(n,x,y);
        int dis=depth[x]+depth[y]-2*depth[lca];
     // cout<<dis<<endl;
        if(dis%2){
            puts("0");
            continue;
        }
        int mid=getparent(x,dis/2);
        if(depth[x]==depth[y]){
                int rng=depth[x]-depth[lca];
            cout<<n-sz[getparent(x,rng-1)]-sz[getparent(y,rng-1)]<<endl;
        } else {
            
           cout<<sz[mid]-sz[getparent(x,(dis/2)-1)]<<endl;
        }


    }


      return 0;
}