 /// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               2010010
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
vector<int>primes;
bool m[2*N];
void sieve(int n) {
    primes.push_back(2);
    for(int i=3; i*i<=n; i+=2)
     for(int j = i*i; j <= n; j += i * 2)
            m[j] = 1;
    for (int i = 3; i <= n; i += 2)
        if (!m[i]) primes.push_back(i);
}
vector<int> pFactor[N];
int ar[N];
pii ans[N];
vector<pii> mark[N];
vector<int> adj[N];
void dfs(int u,int id,int  p  = -1) {

    ans[u] =pii(-1,-1);
    for(auto it: pFactor[ar[u]]) {
        if(mark[it].size()) {
           if(ans[u].ff==-1) ans [u]= mark[it].back();
           else if(mark[it].back().ss>ans[u].ss) ans[u]= mark[it].back();
        }
         mark[it].pb(make_pair(u,id));
    }
    for(auto it : adj[u]) {
        if(it!=p) dfs(it,id+1,u);
    }

    for(auto it : pFactor[ar[u]]) mark[it].pop_back();
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    sieve(N-1);

    int mx = 0;
    for(int i = 0;i<primes.size()&&primes[i]<N;i++) {
        for(int j  = primes[i];j<N;j+=primes[i]) {
            pFactor[j].pb(primes[i]);
        }
    }

    int n=nxt();int q=nxt();
    for(int i = 1;i<=n;i++) ar[i] =nxt();
    for(int i =0;i<n-1;i++) {
        int a=nxt();
        int b=nxt();
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1,0);
    while(q--){
        int t= nxt();
        if(t==1){
            int v= nxt();
            printf("%d\n",ans[v].ff);
        } else {
            int x = nxt();
            int w= nxt();
            ar[x]  = w;
            dfs(1,0);
        }
    }
    return 0;
}
