 /// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               500010
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
int level[N];
int sz[N];
vector<int> adj[N],res[N];
vector<pii> query[N];
string s;
void dfs(int u,int d) {

    sz[u] = 1;
    level[u] = d;
    for(auto v: adj[u]) if(!level[v]) dfs(v,d+1),sz[u] = sz[v]+1;
}
int big[N];
int ans[N];
int cnt[N];
void add(int u,int p ,int x) {
    if(x) {
        res[level[u]][s[u]-'a']= 1 - res[level[u]][s[u]-'a'];
        if(res[level[u]][s[u]-'a']) cnt[level[u]]++;
        else cnt[level[u]]--;
    } else res[level[u]][s[u]-'a'] = 0,cnt[level[u]] = 0;

    for(auto it : adj[u]) {
        if(it!=p&&!big[it]) add(it,u,x);
    }
}
void dfs(int u,int p,int keep) {
    int large_node=-1;
    int submx= -1;
    for(auto it: adj[u]) {
        if(it!=p&&sz[it]>submx) {
            submx= sz[it];
            large_node = it;
        }
    }
    for(auto it : adj[u]) {
        if(it!=large_node&&it!=p) {
            dfs(it,u,0);
        }
    }
    if(large_node!=-1) dfs(large_node,u,1),big[large_node]=1;
    add(u,p,1);
    for(auto it : query[u]){
        ans[it.ss] = cnt[it.ff]<=1;
    }
    if(large_node!=-1) big[large_node]=0;
    if(!keep) add(u,p,-1);


}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 2;i<=n;i++) {
        int a;
        cin>>a;
        adj[a].pb(i);
    }
    for(int i = 0;i<=n;i++) res[i].resize(26,0);

    cin>>s;
    s='?'+s;
    for(int i = 0;i<m;i++) {
        int a,l;
        cin>>a>>l;
        query[a].pb(make_pair(l,i));
    }
    dfs(1,1);

    dfs(1,-1,1);
    for(int i = 0;i<m;i++) {
        if(ans[i]) cout<<("Yes\n");
        else cout<<("No\n");
    }

    return 0;
}
