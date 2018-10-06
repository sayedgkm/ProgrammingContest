///Bismillahir-Rahmanir-Rahim
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
#define        inf                              (1e9)+1000
#define        eps                             1e-9
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
#ifdef sayed
     #define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " is " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cerr.write(names, comma - names) << " is " << arg1 <<" | ";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
int table[32][N];  ///for sparse  table
int depth[N];     ///depth of each node from root
int parent[N];
vector<pll> adj[N];
ll Final[N];
void dfs(int s,int p,int d,ll dist){
    parent[s]=p;
    depth[s]=d;
    Final[s]=dist;
    for(int i=0;i<adj[s].size();i++){
     int t=adj[s][i].ff;
     if(t==p) continue;
      dfs(t,s,d+1,dist+adj[s][i].ss);
    }
}
void lca_init(int n){
   SET(table);
   for(int i=0;i<n;i++){
      table[0][i]=parent[i];
    }
    for(int i=1;(1<<i)<n;i++){
         for(int j=0;j<n;j++){
            if(table[i-1][j]!=-1)
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






struct EDGE{
 ll u,v,cost;
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
vector<int> extra;

ll mst(int n,int m){
    root(n);
    sort(edge,edge+m,compare);
    ll ans=0;int c=0;
    for(int i=0;i<m;i++){
      int u=findUnion(edge[i].u);
      int v=findUnion(edge[i].v);
      if(u!=v){
        ans+=edge[i].cost;
        path[u]=v;
        c++;
        adj[edge[i].u].pb(make_pair(edge[i].v,edge[i].cost));
        adj[edge[i].v].pb(make_pair(edge[i].u,edge[i].cost));
      } else {
        extra.pb(edge[i].u);
        extra.pb(edge[i].v);
      }

    }
    return ans;
}
vector<pll> g[N];
vector<ll> res[N];
vector<ll> dj(int st,int n) {
    vector<ll> level(n,(ll)3e17);
    level[st]=0;
    priority_queue<pll> pq;
    pq.push(make_pair(-0,st));
    while(!pq.empty()) {
        pll top = pq.top();
        pq.pop();
        for(auto it : g[top.ss]) {
            if(level[top.ss]+it.ss<level[it.ff]) {
                level[it.ff]=level[top.ss]+it.ss;
                pq.push(make_pair(-level[it.ff],it.ff));
            }
        }

    }
    return level;
}
ll query(int u,int v) {
    int lc = lca_query(u,v);
   // debug(lc);
    return Final[u]+Final[v]-2*Final[lc];
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n= nxt();
    int m = nxt();
    for(int i = 0;i<m;i++) {
        edge[i].u = lxt()-1;
        edge[i].v = lxt()-1;
        edge[i].cost = lxt();
        g[edge[i].u].pb(make_pair(edge[i].v,edge[i].cost));
        g[edge[i].v].pb(make_pair(edge[i].u,edge[i].cost));
    }
    mst(n,m);
    for(auto it: extra) {
        res[it] = dj(it,n);
     //   for(int i : res[it]) debug(it,i);
    }
    dfs(0,-1,0,0LL);
    lca_init(n);
    int q = nxt();
    while(q--) {

        int u = nxt()-1;
        int v = nxt()-1;
        ll ans = query(u,v);
       // debug(ans);
        for(auto it : extra) {
            ans = min(ans,res[it][u]+res[it][v]);
        }
        printf("%lld\n",ans);
    }

    return 0;
}
