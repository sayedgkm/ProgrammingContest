
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
int ar[N];
int deg[N];
int depth[N];
int sz[N];
int parent[N];
vector<int> adj[N];
void dfs(int u, int d, int p=-1) {
    depth[u] = d;
    sz[u] = 1;
    parent[u] = p;
    for(int v : adj[u]) {
        if(v!=p) {
            dfs(v, d+1, u);
            sz[u]+=sz[v];
        }
    }
}

int mark[N];

struct info{
    int node, child, depth;

    info(int a, int b, int c) {
        node = a;
        child = b;
        depth = c;
    }

    bool operator<(const info &other) const {
        return ((depth-1) - child) > ((other.depth-1)-other.child);
    }
};

ll ans = 0;

void dfsAgain(int u, int white, int p) {

    if(mark[u]==1) {
        ans+=(ll)white;
    }

    for(int v : adj[u]) {
        if(v!=p) {
            dfsAgain(v, white + !mark[v], u);
        }
    }

}

int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int n = nxt(); int k = nxt();
    for(int i = 0;i<n-1;i++) {
        int a= nxt();
        int b= nxt();
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    dfs(1, 1, -1);

    multiset<info> q;
    for(int i = 1;i<=n;i++) {
        sz[i]--;
        deg[i]--;

        if(deg[i]==0) {
           // debug(i, sz[i], depth[i]);
            q.insert(info(i,sz[i],depth[i]));
        }
    }

    //debug(q.size());

    while(k--) {
        info x = *q.begin();
        q.erase(q.begin());
        int node = x.node;
        mark[node] = 1;
        int p = parent[node];

        if(p!=-1) {
            deg[p]--;
            if(deg[p]==0) {
                 q.insert(info(p,sz[p],depth[p]));
            }
        }
    }

    dfsAgain(1, !mark[1], -1);

    for(int i = 1;i<=n;i++) {
        debug(mark[i]);
    }

    printf("%lld\n",ans);



     return 0;
}

