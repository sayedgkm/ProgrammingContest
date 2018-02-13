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
        cerr.write(names, comma - names) << " is " << arg1 <<endl;
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
int ar[N];
struct info{
    int u;
    ll cost;
    info(int _x,ll _cost) {
        u = _x;
        cost = _cost;
    }
    bool operator< (const info& ok) const{
        return cost>ok.cost;
    }

};
ll level[N];
int ans = 0;
vector<pii> adj[N];
int par[N];
void bfs(int s,int l) {
    SET(par);
    priority_queue<info> pq;
    pq.push(info(s,0));
    for(int  i = 0;i<N;i++) level[i] = (ll)1e15;
    level[s] = 0;
    while(!pq.empty()) {
        info temp = pq.top();
        pq.pop();
        for(auto it : adj[temp.u]) {
            if(temp.cost+it.ss<level[it.ff]) {
                level[it.ff] = it.ss+temp.cost;
                par[it.ff] = temp.u;
                pq.push(info(it.ff,level[it.ff]));
            }
        }
    }

}
bool cmp ( pii a, pii b) {
    return a.ss<b.ss;
}
map<pii,int> mp;
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n = nxt();
    int m = nxt();
    int s = nxt();
    FOR(i,0,m) {
        int a = nxt();
        int b = nxt();
        int c = nxt();
        adj[a].pb(make_pair(b,c));
        adj[b].pb(make_pair(a,c));
    }
    FOR(i,0,n+1) sort(ALL(adj[i]),cmp);
    int l = nxt();
    bfs(s,l);
    for(int i = 1;i<=n;i++) {
        for(int j = 0;j<adj[i].size();j++) {
            int x = adj[i][j].ff;
            int c = adj[i][j].ss;
            int tmp = -1;
            if(level[i]<l&&level[i]+c>l&&par[i]!=x) {
                ll baki = level[i]+c-l;
                if(baki+level[x]>=l) ans++;
            }
            if(level[x]<l&&level[x]+c>l&&par[x]!=i) {
                ll baki = level[x]+c-l;
                if(baki+level[i]>l) ans++;
            }


        }

    }
    ans/=2;
    FOR(i,1,n+1) ans += level[i]==l;
    cout<<ans<<endl;


    return 0;
}