 /// Bismillahir-Rahmanir-Rahim
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
int subtree[N];
int del[N];
vector<int> adj[N];
vector<int> centroid_tree[N];
int root;      /// 0 based node
int total_node = 0;
void dfs(int u,int p = -1) {
    subtree[u] = 1;
    total_node++;
    for(int i = 0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(del[v]||v==p) continue;
        dfs(v,u);
        subtree[u] += subtree[v];
    }
}
int GetCenter(int u,int p=-1){
    for(int i = 0;i<adj[u].size();i++) {
        int v = adj[u][i];
        if(del[v]||v==p) continue;
        if(subtree[v]>total_node/2) return GetCenter(v,u);
    }
    return u;
}

void decompose(int u,int p = -1) {
    del[u] = 1;
    for(int i = 0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(del[v]||v==p)  continue;
        total_node = 0;
        dfs(v);
        int c = GetCenter(v);
        centroid_tree[u].pb(c);
        centroid_tree[c].pb(u);
        decompose(c,u);
    }
}
void decompose_tree(int n){
    CLR(subtree);
    CLR(del);
    for(int i = 0;i<n;i++) centroid_tree[i].clear();
    dfs(0);
    root = GetCenter(0);
    decompose(root);
}

int parent[N];
void dfs1(int u,int p=-1) {
    parent[u] = p;
    for(auto it : centroid_tree[u]) {
        if(it==p) continue;
        dfs1(it,u);
    }
}

int table[32][N];  ///for sparse  table
int depth[N];     ///depth of each node from root
int par[N];
void dfs(int s,int p,int d){
    par[s]=p;
    depth[s]=d;
    for(int i=0;i<adj[s].size();i++){
        int t=adj[s][i];
        if(t==p) continue;
        dfs(t,s,d+1);
      }


}
void lca_init(int n){
   SET(table);
   for(int i=0;i<n;i++){
      table[0][i]=par[i];
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
    return par[p];

}
int dist(int a,int b) {
    return depth[a]+depth[b]- 2*depth[lca_query(a,b)];
}
bool ispaint[N];
set<pii>ans[N];
int node;
void paint(int u){
    if(u==-1) return ;
    ans[u].insert(make_pair(dist(u,node),node));
    paint(parent[u]);
}
void reverse_paint(int u){
    if(u==-1) return ;
    ans[u].erase(ans[u].find(make_pair(dist(node,u),node)));
    reverse_paint(parent[u]);
}
int query(int u,int res) {
    if(u==-1) return res;
    auto it = *ans[u].begin();
    return query(parent[u],min(res,it.ff+dist(node,u)));
}

int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n = nxt();
    for(int i =0;i<n-1;i++) {
        int a= nxt();
        int b=nxt();
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i =0;i<n;i++) ans[i].insert(make_pair(inf,i)),parent[i]=-1;
    decompose_tree(n);
    dfs(0,-1,1);
    lca_init(n);
    dfs1(root);
    int q =nxt();
    while(q--) {
        int t = nxt();
        node = nxt();
        node--;
        if(t==0) {
            if(ispaint[node]) {
                ispaint[node] =0;
                reverse_paint(node);
            } else {
                ispaint[node] = 1;
                paint(node);
            }
        } else {
            int val = query(node,inf);
            if(val>=inf) printf("-1\n");
            else printf("%d\n",val);
        }
    }

    return 0;
}
