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
#define        N                               200010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             9e9+100
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
inline ll lxt(){ll aaa;scanf("%lld",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
///******************************************START******************************************
int dista[N];
int distb[N];
vector<int>adj[N];
int table[32][N];  ///for sparse  table
int depth[N];     ///depth of each node from root
int parent[N];

 void dfs2(int u,int c,int p=-1){
     distb[u]=c;
     FOR(i,0,adj[u].size() ){
        int v=adj[u][i];
        if(v==p) continue;
        dfs2(v,c+1,u);
     }
}



void dfs(int s,int p,int d){
       parent[s]=p;
       depth[s]=d;
       dista[s]=d-1;
      for(int i=0;i<adj[s].size();i++){
         int t=adj[s][i];
         if(t==p) continue;
          dfs(t,s,d+1);
      }


}
void lca_init(int n){
   SET(table);
   for(int i=0;i<n;i++){
      table[0][i]=parent[i];
    }
    for(int i=1;(1<<i)<n;i++){
         for(int j=0;j<n;j++){
            table[i][j]=table[i-1][table[i-1][j]];
        }
    }

}
int lca_query(int p,int q){  ///p && q are two nodes.
        if(depth[q]>depth[p])
              swap(p,q);
        int log=1;
        while((1<<log)<depth[p]) log++;
    for(int i=log;i>=0;i--){
           if(depth[p]-(1<<i)>=depth[q])  ///making same level of p and q
                  p=table[i][p];

        }
    if(p==q)
          return p;
    for(int i=log;i>=0;i--){
        if(table[i][p]!=-1&&table[i][p]!=table[i][q])
               p=table[i][p],q=table[i][q];
    }
    return parent[p];

}
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
     int n=nxt();
     int x=nxt();
     FOR(i,0,n-1) {
       int a=nxt();
       int b=nxt();
       a--;
       b--;
       adj[a].pb(b);
       adj[b].pb(a);
     }
     dfs(0,-1,1);
     dfs2(x-1,0);
      lca_init(n);
     // cout<<lca_query(2,3)<<endl;
      int ans=0;
     FOR(i,1,n){
         int lc=lca_query(x-1,i);
         if(distb[lc]<dista[lc]){
              ans=max(ans,dista[i]*2);
         }
     }
     cout<<ans<<endl;
return 0;
}