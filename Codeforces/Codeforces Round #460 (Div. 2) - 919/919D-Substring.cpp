/// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               300010
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
char s[N];
vector<int> adj[N];
bool cycle = 0;
int color[N];
vector<int> top;
int res = 0;
void dfs(int u){
    color[u] = 1;
    for(int  i =0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(color[v]==0){
            dfs(v);
        } else if(color[v]==1){
            cycle = 1;
            return;
        }
    }
    color[u] = 2;
    top.pb(u);
}
int mark[30];
char now;
map<pii,char> mp;
int dp[N][30];
int vis[N][30];
int again(int u,int c){
    if(vis[u][c]==1) return 0;
    if(vis[u][c]==2) return dp[u][c];
    vis[u][c] = 1;
    int res = 0;
    for(auto v: adj[u]) res = max(res,again(v,c)+((s[v-1]-'a')==c));
    vis[u][c] = 2;
    return dp[u][c]=res;
}

int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
     freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

     int n =nxt();
     int m =nxt();
     scanf("%s",s);
     for(int i = 0;i<m;i++){
        int a= nxt();
        int b= nxt();
        if(mp.count(make_pair(a,b))) continue;
        mp[make_pair(a,b)]=1;
        adj[a].pb(b);
     }
    for(int i = 1;i<=n;i++){
        if(color[i]==0){
            dfs(i);
            if(cycle){
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    reverse(ALL(top));
    int ans= 0;
    for(int i = 0;i<=25;i++) for(auto j : top) ans = max(ans,again(j,i)+((s[j-1]-'a')==i));
    cout<<ans<<endl;
    return 0;
}