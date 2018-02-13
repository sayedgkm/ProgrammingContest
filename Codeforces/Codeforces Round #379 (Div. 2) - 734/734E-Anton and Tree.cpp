//====================================
//======================================
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
        cerr.write(names, comma - names) << " is " << arg1 <<endl;
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
int ar[N];
int color[N];
vector<int> adj[N],g[N];
void bfs() {
    queue<pii> q;
    int st = 1;
    q.push(make_pair(1,1));
    color[1] = 1;
    while(q.size()) {
        int u = q.front().ff;
        int c = q.front().ss;
        q.pop();
        for(int i = 0;i<adj[u].size();i++) {
            int  v = adj[u][i];
            if(color[v]==0) {
                if(ar[u]!=ar[v]) color[v] = ++st;
                else color[v] = color[u];
                q.push(make_pair(v,color[v]));
            }
        }
    }
}
pii mx;
void dfs(int u,int p=-1) {

    for(int i = 0;i<g[u].size();i++) {
        int v = g[u][i];
        if(v==p) continue;
        color[v]=color[u]+1;
        if(color[v]>mx.ff) {
            mx.ff = color[v];
            mx.ss = v;
        }
        dfs(v,u);
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
    for(int i = 1;i<=n;i++) ar[i] = nxt();
    for(int i = 1;i<n;i++) {
        int a= nxt();
        int b = nxt();
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bfs();
    for(int i = 1;i<=n;i++)  {
        for(int j = 0;j<adj[i].size();j++) {
            if(adj[i][j]<=i) continue;
            if(color[i]!=color[adj[i][j]]) {
                g[color[i]].pb(color[adj[i][j]]);
                g[color[adj[i][j]]].pb(color[i]);
               // debug(i,adj[i][j]);
            }
        }
    }
    CLR(color);
    dfs(1);
    mx.ff = 0;
    CLR(color);
    dfs(mx.ss);
    cout<<(mx.ff+1)/2<<endl;
    return 0;
}