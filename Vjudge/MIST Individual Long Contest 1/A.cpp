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
int ar[N];
vector<pll> adj[N];
struct info {
    ll cost ,cur;
    info(ll _cost,ll _cur) {
        cost = _cost;
        cur = _cur;
    }
    bool operator< (const info& other) const {
        return cost>other.cost;
    }
};
ll level[3][N];

void dj(int s,int id) {

    priority_queue<info> pq;
    pq.push(info(0,s));
    for(int i =0;i<N;i++)level[id][i] =(ll)3e17;
    level[id][s] = 0;
    while(!pq.empty()) {
        info top= pq.top();
        pq.pop();
        int u = top.cur;
        for(auto it : adj[u]) {
            int vv = it.ff;
            ll cost = it.ss;
            if(level[id][u]+cost<level[id][vv]) {
                level[id][vv] = level[id][u]+cost;
                pq.push(info(level[id][vv],vv));
            }
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
    int test = nxt();
    while(test--) {

        int n = nxt();
        int m = nxt();
        int s =nxt();
        int t= nxt();
        int v= nxt();
        for(int i =0;i<m;i++) {
            int a= nxt();
            int b= nxt();
            ll c= lxt();
            adj[a].pb(make_pair(b,c));
            adj[b].pb(make_pair(a,c));
        }
        dj(s,0);
        dj(t,1);
        dj(v,2);
        ll ans = (ll)3e17;
        for(int i = 1;i<=n;i++)  ans = min({ans,level[0][i]+level[1][i]+level[2][i]});
        printf("%lld\n",ans);
        for(int i = 0;i<N;i++) adj[i].clear();

    }

    return 0;
}
