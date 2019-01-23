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
ll sv[N],av[N];
ll parent[N];
vector<int> adj[N];
void dfs(int u,int h) {
//    if(h%2==1&&u>1) {
//        int p = parent[u];
//        int pp = parent[p];
//        if(av[p]!=-1) {
//            if(av[p]!=sv[u]-sv[pp]) {
//                cout<<-1<<endl;
//                exit(0);
//            }
//        } else {
//            if(sv[u]-sv[pp]<0) {
//                cout<<-1<<endl;
//                exit(0);
//            }
//            av[p] = sv[u]-sv[pp];
//        }
//    }
    if(h%2==0&&adj[u].size()==0) {
        av[u] = 0;
    } else if(h%2==0){
        ll mn = LLONG_MAX;
        for(auto it : adj[u]) {
            mn  = min(mn,sv[it]);
        }
        int p = parent[u];
        if(mn-sv[p]<0) {
            cout<<-1<<endl;
            exit(0);
        }
        av[u] = mn - sv[p];
    }
    for(auto it : adj[u]) {
        dfs(it,h+1);
    }
}
void dfs(int u) {
    if(sv[u]==-1) {
        assert(av[u]!=-1);
        int p = parent[u];
        sv[u] = sv[p]+av[u];
    }
    if(av[u]==-1) {
             //debug(u);
        int p = parent[u];
       // debug(p);
        av[u] = sv[u]-sv[p];
        if(av[u]<0) {
            cout<<-1<<endl;
            exit(0);
        }
    }
    for(auto it : adj[u]) dfs(it);
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n = nxt();
    for(int i = 2;i<=n;i++) {
        int  p = nxt();
        parent[i] = p;
        adj[p].pb(i);
    }
    parent[1]=-1;
    for(int i =1;i<=n;i++) {
        sv[i] = lxt();
    }
    SET(av);
    av[1] = sv[1];
    dfs(1,1);
   // debug("asche");
    dfs(1);

    ll sum = 0;
    for(int i = 1;i<=n;i++) {
        sum+=av[i];
    }
    cout<<sum<<endl;

    return 0;
}
