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
vector<pii> adj[N],bt[N];
int disc[N],low[N],color[N],visited[N];
int counter=1;
int cycle[N];
multiset<pii> B;
void Bridge(int s,int p) {
    disc[s]=low[s]=counter++;
    color[s]=1;
    for(int i=0; i<adj[s].size(); i++) {
        int t=adj[s][i].ff;
        if(t==p)
            continue;
        if(!color[t]) {
            Bridge(t,s);
            if(disc[s]<low[t]){
                int x = min(s,t);
                int y = max(s,t);
               // debug(x+1,y+1);
                B.insert(make_pair(x,y));
            }

            low[s]=min(low[s],low[t]);
        } else               ///Back Edge
            low[s]=min(low[s],disc[t]);

    }

}
int root; /// root of every component
void dfs(int u) {
    visited[u]  = 1;
    cycle[u] = root;

    for(int i  = 0;i<adj[u].size();i++) {
        int v = adj[u][i].ff;
        int x = min(u,v);
        int y = max(u,v);
        if(B.find(make_pair(x,y))!=B.end()) continue;
        if(!visited[v]) {
            dfs(v);
        }
    }
}
int make_tree(int n) {
    CLR(visited);CLR(color);CLR(disc);CLR(low);CLR(cycle);
    B.clear();
    counter = 1;
    for(int i =0;i<N;i++) bt[i].clear();
    for(int i =0;i<n;i++){
        if(!color[i]) Bridge(i,-1);
    }
    for(int i = 0;i<n;i++) if(!visited[i]) root= i,dfs(i);
    for(int i =0;i<n;i++) {
        for(int j = 0;j<adj[i].size();j++) {
            int v = adj[i][j].ff;
            int c = adj[i][j].ss;
            if(cycle[i]!=cycle[v]) {
                bt[cycle[i]].pb(make_pair(cycle[v],c));
            }
        }
    }
}
void print_bt(int n) {
    for(int i =0;i<n;i++) {
        for(int j =0;j<bt[i].size();j++) {
            printf("%d %d %d\n",i+1,bt[i][j].ff+1,bt[i][j].ss);
        }
    }
}
ll level[N];
pll par[N];
void dfs_on_tree(int u,ll dis,ll subDis,int p = -1){
    level[u] = dis;
    par[u] = make_pair(p,subDis);
    for(int i =0;i<bt[u].size();i++) {
        int v = bt[u][i].ff;
        if(v==p) continue;
        dfs_on_tree(v,dis+bt[u][i].ss,bt[u][i].ss,u);
    }
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int test = nxt();
    while(test--){
        int n= nxt();
        int m = nxt();
        for(int i = 0;i<m;i++) {
            int a= nxt();
            int b= nxt();
            int c = nxt();
            a--,b--;
            adj[a].pb(make_pair(b,c));
            adj[b].pb(make_pair(a,c));
        }
        make_tree(n);
        CLR(level);
        dfs_on_tree(0,0,0);
        int st_node=0;
        ll mx = 0;
        for(int i = 0;i<n;i++){
            if(level[i]>mx) {
                mx = level[i];
                st_node = i;
            }
        }
        CLR(level);
        CLR(par);
        dfs_on_tree(st_node,0,0);
        int ed_node= 0;
        mx = 0;
        for(int i = 0;i<n;i++){
            if(level[i]>mx) {
                mx = level[i];
                ed_node = i;
            }
        }
        ll res = (ll)mx;
        ll tot = mx;
        ll baki = 0;
        ll cur = ed_node;
        while(1){
            if(par[cur].ff==-1) break;
            baki+=par[cur].ss;
            if(res>max(tot-baki,baki)){
                cur = par[cur].ff;
                res = max(tot-baki,baki);
            }else if(res==max(tot-baki,baki)){
                cur = min(cur,par[cur].ff);
                break;
            } else break;

        }
        printf("%lld %lld\n",cur+1,res);
        for(int i =0;i<n;i++) adj[i].clear();
    }



    return 0;
}
