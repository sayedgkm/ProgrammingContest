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
vector<int> adj[N];
int disc[N],low[N],color[N];
int vis[N];int cnt = 0;
int counter=1;
int root;

int odd[N];
void init(){
    counter =1 ;
    for(int i = 0;i<N;i++) {
        adj[i].clear();
        disc[i] = low[i]= color[i]= vis[i]  = odd[i]=0;
    }
}
stack<int>st;
ll ans = 0;
int dfs(int u,int p = -1) {
    vis[u] = 1;
    disc[u] = low[u] = counter++;
    st.push(u);
    for(int i =0;i<adj[u].size();i++) {
        int  v= adj[u][i];
        if(v==p)continue;
        if(vis[v]==0) {
            if(color[u]==1) color[v] = 2;
            else color[v] = 1;
            dfs(v,u);
            low[u]= min(low[v],low[u]);
        } else {
            low[u] = min(low[v],low[u]);

            if(color[u]==color[v]) odd[u] = odd[v] = 1;
        }
    }

    if(disc[u]==low[u]) {
        set<int> ok ;
        int x  = -1;
        int f = 0;
        while(u!=x) {
            x = st.top();

            st.pop();
            if(odd[x]==1) f = 1;
            ok.insert(x);
        }

        if(f) ans+=ok.size();
    }
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
   int test = nxt();int cs = 1;
   while(test--) {
        int n= nxt();
        int m = nxt();
        for(int i =0;i<m;i++){
            int a= nxt();
            int b= nxt();adj[a].pb(b);
            adj[b].pb(a);
        }
        ans = 0;
        for(int i = 0;i<n;i++) if(!vis[i]) color[i]=1,dfs(i);
        printf("Case %d: %lld\n",cs++,ans);
        init();

   }



    return 0;
}
