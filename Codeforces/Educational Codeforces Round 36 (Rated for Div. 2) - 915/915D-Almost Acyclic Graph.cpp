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
#define        N                               505
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
        cerr.write(names, comma - names) << " is " << arg1 <<" | " ;
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
#define gray 1
#define white 0
#define black 2
vector<int> adj[N];
int visited[N];
vector<int> cycle;

vector<pii> edgeList;
vector<pii> cycleEdgeList;
int cutu ,cutv;
int mark[N];

bool dfs(int u) {
    visited[u] = 1;
   // debug(u);
    for(int i =0;i<adj[u].size();i++) {
        int v = adj[u][i];
        if(u==cutu&&v==cutv) continue;
         if(visited[v]==1){
            return true;
        }
        if(visited[v]==0) {
            if(dfs(v)) return true;
        }
       
    }
    visited[u] = 2;
    return false;
}
int found = 0;
int path[N];
void dfs1(int u){

    visited[u] = 1;
    if(found) return;
    for(int i =0;i<adj[u].size();i++) {
        int v = adj[u][i];
        if(visited[v]==0&&!found) {
            path[v] = u;
            dfs1(v);
        }
        if(visited[v]==1&&!found){
            found = 1;
            cycle.pb(u);
            while(path[u]!=v){
                u = path[u];
                cycle.pb(u);
            }
            cycle.pb(v);
            return ;
        }
    }
    visited[u] = 2;


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
    FOR(i,0,m) {
        int a= nxt();
        int b = nxt();
        adj[a].pb(b);
        edgeList.pb(make_pair(a,b));
    }
    for(int i = 1;i<=n;i++) {
        if(!found&&!visited[i]) {
            dfs1(i);
        }
    }
    for(int i = 0;i<cycle.size();i++){
        //cout<<cycle[i]<< " ";
        mark[cycle[i]] = 1;
    }
    for(int i = 0;i<edgeList.size();i++) {
        if(mark[edgeList[i].ff]&&mark[edgeList[i].ss]){
            cycleEdgeList.pb(edgeList[i]);
        }
    }
    if(cycleEdgeList.empty()){
        cout<<"YES"<<endl;
        return 0;
    }
    for(int i = 0;i<cycleEdgeList.size();i++) {
        cutu=cycleEdgeList[i].ff;
        cutv = cycleEdgeList[i].ss;
        debug(cutu,cutv);
        CLR(visited);
        int flag = 0;
        for(int j = 1;j<=n;j++) {
            if(!visited[j]&&dfs(j)) flag = 1;
            if(flag) break;
        }
        if(flag==0){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;

    return 0;
}