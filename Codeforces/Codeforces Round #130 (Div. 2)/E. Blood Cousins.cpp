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
vector<int>adj[N];
int table[32][N];  ///for sparse  table
int depth[N];     ///depth of each node from root
int parent[N];
vector<pii> disc[N];
int level[N];
int t = 1;
int st[N];
int ed[N];
void dfs(int s,int p,int d){
    parent[s]=p;
    depth[s]=d;
    level[s] = d;
    disc[d].pb(make_pair(t,s));
    st[s] = t;
    t++;
    for(int i=0;i<adj[s].size();i++){
        int t=adj[s][i];
        if(t==p) continue;
        dfs(t,s,d+1);
      }
    ed[s] = t-1;

}
void lca_init(int n){
   SET(table);
   for(int i=0;i<n;i++){
      table[0][i]=parent[i];
    }
    for(int i=1;(1<<i)<n;i++){
         for(int j=0;j<n;j++){
            table[i][j]=(table[i-1][j]==-1?-1:table[i-1][table[i-1][j]]);
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
int getParent(int u,int x) {

    for(int i = 20;i>=0;i--) {
        if((1<<i)<=x) {
            u=table[i][u];
            if(u==-1) return -1;
            x-=(1<<i);
        }
    }
    return u;

}
vector<int> root;
int lo(int l,int x) {
    int lo =0;
    int hi = disc[l].size()-1;
    while(lo<=hi) {
        int mid = (lo+hi) /2;
        if(disc[l][mid].ff<x) lo = mid+1;
        else hi = mid-1;
    }
    return lo;
}
int hi(int l,int x) {
    int lo =0;
    int hi = disc[l].size()-1;
    while(lo<=hi) {
        int mid = (lo+hi) /2;
        if(disc[l][mid].ff<=x) lo = mid+1;
        else hi = mid-1;
    }
    return lo-1;

}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n =  nxt();
    for(int i = 1;i<=n;i++) {
        int a= nxt();
        if(a==0) root.pb(i-1);
        else adj[a-1].pb(i-1);
    }
    SET(parent);
    for(auto it:root) dfs(it,-1,0);
    lca_init(n);

    int q = nxt();
    while(q--) {

        int u = nxt()-1;
        int x= nxt();
        u = getParent(u,x);
        debug(u);
        if(u==-1) printf("0 ");
        else {

            int l = level[u];
            l+=x;
            printf("%d ",hi(l,ed[u])-lo(l,st[u]));

        }
    }


    return 0;
}
