 /// Bismillahir-Rahmanir-Rahim
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
/// Given Dag and root of dag
/// call makeDominatorTree
/// Tree will be saved in dTree
vector<int> dag[N];
int root; /// assign root of your dag here
vector<int> dTree[N];
int table[32][N];  ///for sparse  table
int depth[N];     ///depth of each node from root
int color[N];
vector<int> topSort;
vector<int> parentList[N]; /// ParentList of each node in dag
void dfs(int u) {  /// dfs for topSort
    color[u] = 1;
    for(auto it: dag[u]){
        parentList[it].pb(u);
        if(!color[it]) dfs(it);
    }
    topSort.pb(u);
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
    return table[0][p];
}
void add(int u,int v,int n) { /// v will be added under u
    table[0][v] = u;
    depth[v] = depth[u]+1;
    for(int i =1;(1<<i)<n;i++) {
        if(table[i-1][v]!=-1)
            table[i][v]= table[i-1][table[i-1][v]];
    }
    return ;
}
void makeDominatorTree(int n) {
    SET(table);
    CLR(depth);
    CLR(color);
    for(int i =0;i<N;i++) dTree[i].clear(),parentList[i].clear();
    topSort.clear();
    dfs(root);
    depth[root]=1;
    reverse(ALL(topSort));
    for(int i = 0;i<topSort.size();i++) {
        if(i==0) continue;
        int v = topSort[i];
        int u = parentList[v][0];
        for(int j = 1;j<parentList[v].size();j++) u = lca_query(u,parentList[v][j]);
        add(u,v,n);
        dTree[u].pb(v);
    }

}

vector<pii> adj[N];
ll level[N];
int done[N];
void dijkstra(int st) {
    for(int i = 0;i<N;i++) level[i] = 3e17;
    level[st] =0;
    priority_queue<pll> pq;
    pq.push(make_pair(level[0],st));
    while(!pq.empty()) {
        pii top = pq.top();
        pq.pop();
        int u = top.ss;
        if(done[u]) continue;
        done[u] = 1;
        for(int i =0;i<adj[u].size();i++) {
            int v= adj[u][i].ff;
            ll cost = (ll)adj[u][i].ss;
            if(!done[v]&&level[u]+cost<level[v] ) {
                level[v]= level[u]+cost;
                pq.push(make_pair(-level[v],v));
            }

        }

    }

}
vector<tuple< int ,int , int > > edge;
int sz[N];
int finalDfs(int u) {
    sz[u] = 1;
    for(auto it : dTree[u]) {
        if(!sz[it]) finalDfs(it);
        sz[u]+=sz[it];
    }
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n = nxt();
    int m= nxt();
    int st = nxt()-1;
    root = st;
    for(int i = 0;i<m;i++) {
        int a= nxt()-1;
        int b= nxt()-1;
        int c = lxt();
        adj[a].pb(make_pair(b,c));
        adj[b].pb(make_pair(a,c));
        edge.pb(make_tuple(a,b,c));
    }
    dijkstra(st);
    //for(int i = 0;i<n;i++) debug(level[i]);
    for(auto it : edge) {
        int a = get<0>(it);
        int b = get<1>(it);
        ll c = (ll)get<2>(it);
        if(level[a]+c==level[b]) dag[a].pb(b);
        if(level[a]==level[b]+c) dag[b].pb(a);
    }
    makeDominatorTree(n);
    int res = 0;
    finalDfs(root);
    for(int i = 0;i<n;i++) {
        if(root==i) continue;
        res = max(res,sz[i]);
    }
    printf("%d\n",res);

    return 0;
}


