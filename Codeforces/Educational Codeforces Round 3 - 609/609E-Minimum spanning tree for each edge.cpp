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
map<pii,int> mp;
vector<pii> adj[N];
struct EDGE{
 ll u,v,cost,id;
}edge[N];
bool compare(EDGE a,EDGE b){
  return a.cost<b.cost;
 }
 int path[N];
void root(int n){
   for(int i=0;i<=n;i++)
       path[i]=i;
}
int findUnion(int x){
   if(path[x]==x) return x;
    return path[x]=findUnion(path[x]);

}
ll mst(int n,int m){
    root(n);
    sort(edge,edge+m,compare);
 ll ans=0;int c=0;
 for(int i=0;i<m;i++){
      int u=findUnion(edge[i].u);
      int v=findUnion(edge[i].v);
      if(u!=v){
          int x=min(edge[i].u,edge[i].v);
          int y=max(edge[i].u,edge[i].v);
        //  cout<<x<<" "<<y<<endl;
      mp[pii(x,y)]=1;
      adj[x].pb(pii(y,edge[i].cost));
      adj[y].pb(pii(x,edge[i].cost));
        ans+=edge[i].cost;
        path[u]=v;
        c++;
        if(c==n-1) break;
      }

   }
   return ans;
}
int table[32][N];
ll table1[32][N];
int depth[N];
int parent[N];
ll dist[N];
void dfs(int s,int p,int d,int di){
       parent[s]=p;
       depth[s]=d;

      for(int i=0;i<adj[s].size();i++){
           int t=adj[s][i].ff;
             if(t==p) continue;

         dist[t]=adj[s][i].ss;

          dfs(t,s,d+1,adj[s][i].ss);
      }


}
void lca_init(int n){
   SET(table);
   for(int i=0;i<n;i++){
      table[0][i]=parent[i];
      table1[0][i]=dist[i];
    }
    for(int i=1;(1<<i)<n;i++){
         for(int j=0;j<n;j++){

            table[i][j]=table[i-1][table[i-1][j]];
            table1[i][j]=max(table1[i-1][j],table1[i-1][table[i-1][j]]);

        }
    }

}
ll lca_query(int p,int q){  ///p && q are two nodes.
        if(depth[q]>depth[p])
              swap(p,q);
        int log=1; ll mx=0;
        while((1<<log)<depth[p]) log++;
    for(int i=log;i>=0;i--){
           if(depth[p]-(1<<i)>=depth[q]){  ///making same level of p and q
                  mx=max(mx,table1[i][p]);
                    p=table[i][p];
                   // debug(p);
                  // debug(mx)
           }
        }
    if(p==q)
          return mx;
    for(int i=log;i>=0;i--){
        if(table[i][p]!=-1&&table[i][p]!=table[i][q]){
                mx=max(mx,table1[i][p]);
                mx=max(mx,table1[i][q]);
               p=table[i][p],q=table[i][q];
        }
    }
    return max(mx,max(dist[p],dist[q]));

}

ll res[N];
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int n=nxt();
   int m=nxt();
   FOR(i,0,m) {
     edge[i].u=nxt()-1;
     edge[i].v=nxt()-1;
     edge[i].cost=nxt();
     edge[i].id=i;
   }
  ll ans=mst(n,m);
   dfs(0,-1,0,0);
   lca_init(n);
  // debug(table1[1][1]);

   FOR(i,0,m){
      int a=edge[i].u;
      int b=edge[i].v;
      int id=edge[i].id;
      int x=min(a,b);
      int y=max(a,b);
      if(mp[pii(x,y)]) {
          res[id]=ans;
      } else {
          ll q=lca_query(a,b);
         res[id]=ans-q+edge[i].cost;

      }

   }

  FOR(i,0,m) printf("%lld\n",res[i]);
return 0;
}