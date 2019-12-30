///Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               4000010
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

vector<pll> adj[N];
ll mst(int n,int m){
    root(n);
    sort(edge,edge+m,compare);
 ll ans=0;int c=0;
 for(int i=0;i<m;i++){
      int u=findUnion(edge[i].u);
      int v=findUnion(edge[i].v);
      if(u!=v){
        ans+=edge[i].cost;
        adj[edge[i].u].push_back(make_pair(edge[i].v,edge[i].cost));
        adj[edge[i].v].push_back(make_pair(edge[i].u,edge[i].cost));
        path[u]=v;
        c++;
        if(c==n-1) break;
      }

   }
   return ans;
}
ll x[2005];
ll y[2005];
ll get(int i,int j) {
    return abs(x[i]-x[j])+ abs(y[i]-y[j]);
}
ll power[2005];
ll wire[2005];
vector<pii> connection;
vector<int> station;
ll totalCost =  0;

//int isPlacedStation[2005];
vector<int> adjStation[2005];
int st[2005];
int ed[2005];
int T = 1;
vector<int> nodes;
vector< EDGE> edges;
int level[N];
void dfs(int u,int depth, int p = -1) {
    st[u] = T++;
    nodes.push_back(u);
    level[u] = depth;
    for(auto it : adj[u]) {
        int v = it.ff;
        ll cost = it.ss;
        if(v!=p) {
//            if(power[v]<cost) {
//              //  isPlacedStation[v] = 1;
//            } else {
//                connection.push_back(make_pair(u,v));
//                adjStation[u].push_back(v);
//                adjStation[v].push_back(u);
//                totalCost+=cost;
//            }
            EDGE e;
            e.u = u;
            e.v = v;
            e.cost = cost;
            edges.push_back(e);
            dfs(v,depth+1, u);
        }
    }
    ed[u] = T;
}
int visited[2005];
ll totalMin;
ll mnNode;
void dfsAgain(int u) {
    visited[u] = 1;
    if(power[u]<totalMin) {
        totalMin = power[u];
        mnNode=u;
    }
    for(auto it : adjStation[u]) {
        if(!visited[it])  {
            dfsAgain(it);
        }
    }
}


struct info{
   ll sum;
   ll mx;
}tree[2005*4];
void segment_tree(int node,int low,int high){
     if(low==high){
        tree[node].sum=power[nodes[low-1]];
        return;
     }
    int left=2*node;
    int right=2*node+1;
    int mid=(low+high)/2;
    segment_tree(left,low,mid);
    segment_tree(right,mid+1,high);
    tree[node].sum=min(tree[left].sum,tree[right].sum);
}
ll query(int node,int low,int hi,int i,int j){
    if(i>hi||j<low) return LLONG_MAX;
    if(low>=i&&hi<=j)
      return tree[node].sum;
    int mid=(low+hi)/2;
    int left=2*node;
    int right=left+1;
    ll x= query(left,low,mid,i,j);
    ll y= query(right,mid+1,hi,i,j);
    return min(x,y);
}

int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n = nxt();
    for(int i = 0;i<n;i++) {
        x[i] = lxt();
        y[i] = lxt();
    }
    for(int i = 0;i<n;i++) {
        power[i] = lxt();
    }
     for(int i = 0;i<n;i++) {
        wire[i] = lxt();
    }
    int m = 0;
    for(int i = 0;i<n;i++) {
        for(int j = i+1;j<n;j++) {
            EDGE e;
            e.u = i;
            e.v = j;
            e.cost = get(i,j) * (wire[i] + wire[j]);
            edge[m++]= e;
        }
    }
    mst(n,m);

    int root = -1;
    ll mn = LLONG_MAX;
    for(int i = 0;i<n;i++) {
        if(power[i]<mn) {
            mn = power[i];
            root = i;
        }
    }
    dfs(root,1);
    segment_tree(1,1,n);

    for(auto it : edges) {
        int u = it.u;
        int v = it.v;
        int node = -1;
        if(level[u]>level[v]) node = u;
        else node = v;
        int mn = query(1,1,n,st[node],ed[node]);
        int mn2 = min(query(1,1,n,1,st[node]-1),query(1,1,n,ed[node]+1,n));
        if(power[node]>mn || power[node]>mn2) {
            debug(u,v);
            adjStation[u].push_back(v);
            adjStation[v].push_back(u);
        }
    }
    for(int i = 0;i<n;i++) {
        if(!visited[i]) {
            totalMin = LLONG_MAX;
            dfsAgain(i);
            station.push_back(mnNode);
            totalCost+=totalMin;
        }
    }

    printf("%lld\n",totalCost);
    printf("%d\n",(int)station.size());
    for(auto it : station) {
        printf("%d ",it+1);
    }
    printf("\n");

    printf("%d\n",(int)connection.size());
    for(auto it : connection) {
        printf("%d %d\n",it.ff+1,it.ss+1);
    }

    return 0;
}
