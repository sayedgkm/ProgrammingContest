 /// Bismiintahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                            pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               10000010
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
struct EDGE{
 int u,v,cost;
 bool operator<(const EDGE& other) const{
    return cost<other.cost;
 }
};
bool compare(EDGE a,EDGE b){
  return a.cost<b.cost;
 }
int path[3005];
void root(int n){
   for(int i=0;i<=n;i++)
       path[i]=i;
}
int findUnion(int x){
    if(path[x]==x) return x;
    return path[x]=findUnion(path[x]);

}
vector<pll>adj[3005];
vector<EDGE>vv;
vector<EDGE> edge;
int mp[3005][3005];
vector<EDGE>tmp[N];
void Sort(vector<EDGE> &ok){
    int mx = 0;
    int n = ok.size();
    for(int i = 0;i<n;i++){
        tmp[ok[i].cost].pb(ok[i]);
        mx = max(mx,(int)ok[i].cost);
    }
    ok.clear();
    for(int i = 0;i<=mx;i++) {
        while(tmp[i].size()) {
            ok.pb(tmp[i].back());
            tmp[i].pop_back();
        }
    }
}
ll mst(int n,int m){
 root(n);
 Sort(edge);
 for(int i = 0;i<3005;i++) adj[i].clear();
 CLR(mp);
 vv.clear();
 ll ans=0;int c=0;
 for(int i=0;i<m;i++){
      int u=findUnion(edge[i].u);
      int v=findUnion(edge[i].v);
      if(u!=v){
        mp[edge[i].u][edge[i].v] = 1;
        mp[edge[i].v][edge[i].u] = 1;
        adj[edge[i].u].pb(make_pair(edge[i].v,edge[i].cost));
        adj[edge[i].v].pb(make_pair(edge[i].u,edge[i].cost));
        ans+=edge[i].cost;
        path[u]=v;
        c++;
      } else {
        EDGE tmp;
        tmp.u = edge[i].u;
        tmp.v = edge[i].v;
        tmp.cost = edge[i].cost;
        vv.pb(tmp);
      }

   }
   return ans;
}


int table[32][3005];  ///for sparse  table
int depth[3005];     ///depth of each node from root
int parent[3005];
int cur[3005],up[3005];
void dfs(int s,int p,int d){
       parent[s]=p;
       depth[s]=d;
      for(int i=0;i<adj[s].size();i++){
         int t=adj[s][i].ff;
         if(t==p) continue;
          cur[t] = adj[s][i].ss;
          up[t] = (int)2e9;
          dfs(t,s,d+1);
      }


}

void update(int u,int v,int cost) {
    v = findUnion(v);
    u = findUnion(u);
     while(v!=u) {
        if(depth[v]>depth[u]){
            up[v] = min(up[v],(int)cost);
            path[findUnion(v)] = path[findUnion(parent[v])];
            v = findUnion(v);
        } else {
            up[u] = min(up[u],(int)cost);
            path[findUnion(u)] = path[findUnion(parent[u])];
            u = findUnion(u);
        }
     }

}

int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    debug((int)2e9);
    int n,m;
    while(1) {

        n = nxt();m = nxt();
        if(!n&&!m) break;
        edge.resize(m);
        for(int i =0;i<m;i++) {
            edge[i].u = nxt();
            edge[i].v = nxt();
            if(edge[i].u>edge[i].v) swap(edge[i].u,edge[i].v);
            edge[i].cost = nxt();

        }
        int ans = mst(n,m);
        dfs(0,-1,1);
        root(n);
        for(int i = 0;i<vv.size();i++) {
            update(vv[i].u,vv[i].v,vv[i].cost);
        }
        int q= nxt();
        int res = 0;int i  = 0;
        while(i<q) {
            i++;
            int a= nxt();
            int b= nxt();
            int c = nxt();
            if(parent[b]!=a) swap(a,b);
            if(mp[a][b]==0) {
                res+=ans;
                continue;
            } else {
                res+=(ans-cur[b]+min((int)c,up[b]));
            }


        }
        printf("%0.4f\n",res/(double)q);
        CLR(depth);
        CLR(cur);
        CLR(up);

    }

    return 0;
}
